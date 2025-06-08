#define Main_C

#include "Main.h"
#include "DMA-Buffer-Manager.h"
#include "SC_Init.h"
#include "SC_Interrupt.h"
#include "Terminal.h"
#include <stdio.h>
#include <string.h>

void vTask_LED(void* pvParameters)
{
    TickType_t       xLastWakeTime;
    const TickType_t xFrequency = pdMS_TO_TICKS(500);  // 周期为0.5秒
    xLastWakeTime = xTaskGetTickCount();  // 初始化上次唤醒时间为当前时间
    for (;;) {
        GPIO_TogglePins(GPIOB, GPIO_Pin_15);
        vTaskDelayUntil(&xLastWakeTime, xFrequency);  // 延迟到下一个周期点
    }
}

void vTask_Monitor(void* pvParameters)
{
    TickType_t       xLastWakeTime;
    const TickType_t xFrequency = pdMS_TO_TICKS(3000);  // 周期为3秒
    xLastWakeTime = xTaskGetTickCount();  // 初始化上次唤醒时间为当前时间
    char* const  Task_Name = pcTaskGetName(NULL);  // 获取当前任务名称
    TaskHandle_t xIdleTaskHandle =
        xTaskGetIdleTaskHandle();  // 获取空闲任务句柄
    for (;;) {
        Terminal_Output("[%s] Free Memory:\n Heap: %u Bytes\n %s: %u Words\n "
                        "%s: %u Words\n %s: %u Words\n",
                        Task_Name, xPortGetMinimumEverFreeHeapSize(),
                        pcTaskGetName(vTask_List[0]),
                        uxTaskGetStackHighWaterMark(vTask_List[0]),
                        pcTaskGetName(vTask_List[1]),
                        uxTaskGetStackHighWaterMark(vTask_List[1]),
                        pcTaskGetName(xIdleTaskHandle),
                        uxTaskGetStackHighWaterMark(xIdleTaskHandle));
        vTaskDelayUntil(&xLastWakeTime, xFrequency);  // 延迟到下一个周期点
    }
}

int main(void)
{
    SC_Init();  // 初始化芯片外设
    DMA_Buffer_Manager_Initialize(&DMA_Buffer_Manager_UART1, 256, DMA1, UART1,
                                  DMA_UART);  // 初始化DMA缓冲区管理器
    DMA_Buffer_Manager_Initialize(&DMA_Buffer_Manager_SPI0, 256, DMA0, SPI0,
                                  DMA_SPI);  // 初始化DMA缓冲区管理器
    xTaskCreate(vTask_LED, "LED", 36, NULL, 1, &vTask_List[0]);  // 创建监控任务
    xTaskCreate(vTask_Monitor, "Monitor", 100, NULL, 2,
                &vTask_List[1]);  // 创建监控任务
    vTaskStartScheduler();        // 启动调度器
    while (1)
        ;
}
