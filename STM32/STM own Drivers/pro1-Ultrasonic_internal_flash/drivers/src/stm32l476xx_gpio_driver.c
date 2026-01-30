#include "stm32l476xx_gpio_driver.h"

// Peripheral clock setup
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi){
	if(EnorDi == ENABLE){
		if(pGPIOx==GPIOA){ GPIOA_PCLK_EN(); }
		else if(pGPIOx==GPIOB){ GPIOB_PCLK_EN(); }
		else if(pGPIOx==GPIOC){ GPIOC_PCLK_EN(); }
		else if(pGPIOx==GPIOD){ GPIOD_PCLK_EN(); }
		else if(pGPIOx==GPIOE){ GPIOE_PCLK_EN(); }
		else if(pGPIOx==GPIOF){ GPIOF_PCLK_EN(); }
		else if(pGPIOx==GPIOG){ GPIOG_PCLK_EN(); }
		else if(pGPIOx==GPIOH){ GPIOH_PCLK_EN(); }
	}
	else{
		if(pGPIOx==GPIOA){ GPIOA_PCLK_DI(); }
		else if(pGPIOx==GPIOB){ GPIOB_PCLK_DI(); }
		else if(pGPIOx==GPIOC){ GPIOC_PCLK_DI(); }
		else if(pGPIOx==GPIOD){ GPIOD_PCLK_DI(); }
		else if(pGPIOx==GPIOE){ GPIOE_PCLK_DI(); }
		else if(pGPIOx==GPIOF){ GPIOF_PCLK_DI(); }
		else if(pGPIOx==GPIOG){ GPIOG_PCLK_DI(); }
		else if(pGPIOx==GPIOH){ GPIOH_PCLK_DI(); }
	}
}


// Init and Deinit
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    uint32_t temp = 0;

    // MUST ENABLE SYSCFG for EXTI
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    // 1. Pin mode
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
    {
        temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode
                << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

        pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
        pGPIOHandle->pGPIOx->MODER |= temp;
    }
    else
    {
        // Interrupt configuration
        uint8_t pin = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;

        if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT){
            EXTI->FTSR1 |= (1 << pin);
            EXTI->RTSR1 &= ~(1 << pin);
        }
        else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT){
            EXTI->RTSR1 |= (1 << pin);
            EXTI->FTSR1 &= ~(1 << pin);
        }
        else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT){
            EXTI->FTSR1 |= (1 << pin);
            EXTI->RTSR1 |= (1 << pin);
        }

        uint8_t temp1 = pin / 4;
        uint8_t temp2 = pin % 4;

        uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);

        SYSCFG->EXTICR[temp1] &= ~(0xF << (4 * temp2));
        SYSCFG->EXTICR[temp1] |=  (portcode << (4 * temp2));

        EXTI->IMR1 |= (1 << pin);
    }

    // 2. Speed
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed
            << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDR |= temp;

    // 3. Pull-up/down
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl
            << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

    pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR |= temp;

    // 4. Output type
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType
            << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

    pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER |= temp;

    // 5. Alternate function
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
    {
        uint8_t afr_reg = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
        uint8_t afr_pos = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;

        pGPIOHandle->pGPIOx->AFR[afr_reg] &= ~(0xF << (4 * afr_pos));
        pGPIOHandle->pGPIOx->AFR[afr_reg] |=
                (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * afr_pos));
    }
}


// Reset GPIO
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){
	if(pGPIOx==GPIOA){ GPIOA_REG_RESET(); }
	else if(pGPIOx==GPIOB){ GPIOB_REG_RESET(); }
	else if(pGPIOx==GPIOC){ GPIOC_REG_RESET(); }
	else if(pGPIOx==GPIOD){ GPIOD_REG_RESET(); }
	else if(pGPIOx==GPIOE){ GPIOE_REG_RESET(); }
	else if(pGPIOx==GPIOF){ GPIOF_REG_RESET(); }
	else if(pGPIOx==GPIOG){ GPIOG_REG_RESET(); }
	else if(pGPIOx==GPIOH){ GPIOH_REG_RESET(); }
}


// I/O Functions
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber){
	return (uint8_t)((pGPIOx->IDR >> GPIO_PinNumber) & 0x1);
}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	return (uint16_t)(pGPIOx->IDR);
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber, uint32_t value){
	if(value == GPIO_PIN_SET)
		pGPIOx->ODR |=  (1 << GPIO_PinNumber);
	else
		pGPIOx->ODR &= ~(1 << GPIO_PinNumber);
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint32_t value){
	pGPIOx->ODR = value;
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber){
	pGPIOx->ODR ^= (1 << GPIO_PinNumber);
}


// IRQ Config
void GPIO_IRQ_interrupt_Config(uint8_t IRQNumber, uint8_t EnorDi){
	if(EnorDi == ENABLE){
		if(IRQNumber < 32){
			*NVIC_ISER0 = (1 << IRQNumber);
		}
		else if(IRQNumber < 64){
			*NVIC_ISER1 = (1 << (IRQNumber - 32));
		}
		else if(IRQNumber < 96){
			*NVIC_ISER2 = (1 << (IRQNumber - 64));
		}
	}
	else{
		if(IRQNumber < 32){
			*NVIC_ICER0 = (1 << IRQNumber);
		}
		else if(IRQNumber < 64){
			*NVIC_ICER1 = (1 << (IRQNumber - 32));
		}
		else if(IRQNumber < 96){
			*NVIC_ICER2 = (1 << (IRQNumber - 64));
		}
	}
}

void GPIO_IRQ_priority_Config(uint8_t IRQNumber,uint8_t priority){
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprx_section = IRQNumber % 4;
	uint8_t shift_amount  = (8*iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);

	*(NVIC_PR_BASE_ADDR + iprx) |= (priority << shift_amount);
}

// IRQ Handler
void GPIO_IRQHandling(uint8_t GPIO_PinNumber){
	if(EXTI->PR1 & (1 << GPIO_PinNumber)){
		EXTI->PR1 |= (1 << GPIO_PinNumber); // Clear pending bit
	}
}
