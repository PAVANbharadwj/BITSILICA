#include "log_storage.h"

#define LOG_MAX 256

static DistanceSample_t logBuf[LOG_MAX];
static uint32_t logCount = 0;

void Log_Init(void)
{
    logCount = 0;
}

void Log_AppendSample(const DistanceSample_t *s)
{
    if (logCount < LOG_MAX)
        logBuf[logCount++] = *s;
}

uint32_t Log_GetCount(void)
{
    return logCount;
}

DistanceSample_t Log_GetSample(uint32_t index)
{
    DistanceSample_t empty = {0};

    if (index >= logCount)
        return empty;

    return logBuf[index];
}
