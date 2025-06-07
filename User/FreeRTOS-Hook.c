#include "FreeRTOS-Hook.h"
#include "FreeRTOS.h"
#include "Terminal.h"
#include "task.h"

void vApplicationStackOverflowHook(TaskHandle_t xTask, char* pcTaskName)
{
    Terminal_Output("[Warning] \"%s\" Stack Overflow!\n", pcTaskName);
}
