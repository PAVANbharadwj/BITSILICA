/*
 * stm32l4xx_I2C_Driver.c
 * Fixed & stabilized for STM32L4
 */

#include "STM32Lxx.h"
#include "STM32Lxx_I2Cx_header.h"
#include "main.h"

/* ========================= STATIC HELPERS ========================= */

static void I2C_ClearFlags(I2C_RegDef_t *pI2Cx)
{
    /* Clear STOPF, NACKF, BERR, ARLO */
    pI2Cx->ICR |= (1U << 5) | (1U << 4) | (1U << 8) | (1U << 9);
}

/* ========================= CLOCK CONTROL ========================= */

void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t state)
{
    if (state == ENABLE)
    {
        if (pI2Cx == I2C1) I2C1_PCLK_EN();
        else if (pI2Cx == I2C2) I2C2_PCLK_EN();
        else if (pI2Cx == I2C3) I2C3_PCLK_EN();
    }
}

/* ========================= PERIPHERAL ENABLE ========================= */

void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx, uint8_t state)
{
    if (state == ENABLE)  pI2Cx->CR1 |= (1 << 0);
    else                 pI2Cx->CR1 &= ~(1 << 0);
}

/* ========================= INIT ========================= */

void I2C_Init(I2C_Handle_t *pI2CHandle)
{
    /* Disable peripheral before config */
    pI2CHandle->pI2Cx->CR1 &= ~(1 << 0);

    /* Timing: 100kHz @ 16MHz PCLK (example) */
    pI2CHandle->pI2Cx->TIMEINGR = 0x00303D5B;

    /* Own address (not used in master, but required) */
    pI2CHandle->pI2Cx->OAR1 = (1 << 15) | (pI2CHandle->I2C_Config.I2C_DeviceAddress << 1);

    /* Enable peripheral */
    pI2CHandle->pI2Cx->CR1 |= (1 << 0);
}

/* ========================= MASTER TRANSMIT (POLLING) ========================= */

void I2C_MasterTransmitData(I2C_Handle_t *pI2CHandle,
                            uint8_t *pTxBuffer,
                            uint8_t txLen,
                            uint8_t slaveAddr,
                            uint8_t Sr)
{
    I2C_RegDef_t *I2Cx = pI2CHandle->pI2Cx;

    /* 1. Wait until bus free */
    while (I2Cx->ISR & (1 << 15));

    /* 2. Clear old flags */
    I2C_ClearFlags(I2Cx);

    /* 3. Configure CR2 cleanly */
    uint32_t cr2 = 0;
    cr2 |= (slaveAddr << 1);        // SADD
    cr2 |= (txLen << 16);           // NBYTES
    cr2 &= ~(1 << 10);              // WRITE
    if (Sr == I2C_SR_DISABLE)
        cr2 |= (1 << 25);           // AUTOEND

    I2Cx->CR2 = cr2;

    /* 4. Generate START */
    I2Cx->CR2 |= (1 << 13);

    /* 5. Send bytes */
    while (txLen)
    {
        /* Check NACK */
        if (I2Cx->ISR & (1 << 4))
        {
            I2Cx->ICR |= (1 << 4); // Clear NACK
            return;
        }

        /* Wait until transmitter ready */
        while (1)
        {
            uint32_t isr = I2Cx->ISR;

            if (isr & (1 << 1)) break;        // TXIS OK

            if (isr & (1 << 4))               // NACKF
            {
                I2Cx->ICR |= (1 << 4);
                return;                       // <-- THIS is your issue
            }

            if (isr & (1 << 5))               // STOPF
            {
                I2Cx->ICR |= (1 << 5);
                return;
            }
        }


        I2Cx->TXDR = *pTxBuffer++;
        txLen--;
    }

    /* 6. Wait for STOP */
    if (Sr == I2C_SR_DISABLE)
    {
        while (!(I2Cx->ISR & (1 << 5)));
        I2Cx->ICR |= (1 << 5);
    }
}

/* ========================= MASTER RECEIVE (POLLING) ========================= */

void I2C_MasterReceiveData(I2C_Handle_t *pI2CHandle,
                           uint8_t *pRxBuffer,
                           uint8_t rxLen,
                           uint8_t slaveAddr,
                           uint8_t Sr)
{
    I2C_RegDef_t *I2Cx = pI2CHandle->pI2Cx;

    while (I2Cx->ISR & (1 << 15));   // BUSY wait
    I2C_ClearFlags(I2Cx);

    uint32_t cr2 = 0;
    cr2 |= (slaveAddr << 1);
    cr2 |= (rxLen << 16);
    cr2 |= (1 << 10);                // READ
    if (Sr == I2C_SR_DISABLE)
        cr2 |= (1 << 25);

    I2Cx->CR2 = cr2;
    I2Cx->CR2 |= (1 << 13);          // START

    while (rxLen)
    {
        while (!(I2Cx->ISR & (1 << 2))); // RXNE
        *pRxBuffer++ = I2Cx->RXDR;
        rxLen--;
    }

    if (Sr == I2C_SR_DISABLE)
    {
        while (!(I2Cx->ISR & (1 << 5)));
        I2Cx->ICR |= (1 << 5);
    }
}

/* ========================= START / STOP ========================= */

void I2C_GenerateStartCondition(I2C_RegDef_t *pI2Cx)
{
    pI2Cx->CR2 |= (1 << 13);
}

void I2C_GenerateStopCondition(I2C_RegDef_t *pI2Cx)
{
    pI2Cx->CR2 |= (1 << 14);
}

/* ========================= ACK CONTROL ========================= */

void I2C_ManageAcking(I2C_RegDef_t *pI2Cx, uint8_t state)
{
    if (state == ENABLE) pI2Cx->CR1 |= (1 << I2C_CR1_ACK);
    else                pI2Cx->CR1 &= ~(1 << I2C_CR1_ACK);
}

/* ========================= CALLBACK (USER IMPLEMENTS) ========================= */

__attribute__((weak)) void I2C_ApplicationEventCallBack(I2C_Handle_t *pI2CHandle,
                                                        uint8_t event)
{
    (void)pI2CHandle;
    (void)event;
}
