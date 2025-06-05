#include "FreeRTOS-Hook.h"
#include "Terminal.h"

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    //print("$ [Warning] \"%s\" stack over flow!\n", pcTaskName);
}
