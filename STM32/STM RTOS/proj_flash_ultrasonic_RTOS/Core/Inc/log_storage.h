#ifndef LOG_STORAGE_H
#define LOG_STORAGE_H

#include <stdint.h>

typedef struct {
    uint32_t timestamp_ms;
    uint16_t distance_cm;
} DistanceSample_t;

void Log_Init(void);
void Log_AppendSample(const DistanceSample_t *sample);
uint32_t Log_GetCount(void);
DistanceSample_t Log_GetSample(uint32_t index);

#endif // LOG_STORAGE_H

