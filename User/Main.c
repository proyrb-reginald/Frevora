#define Main_C

#ifdef Include_Main_H
#include "Main.h" // 包含主头文件以确保正确的配置和初始化
#endif // Include_Main_H

#include "SC_Init.h"
#include "SC_it.h"
#include "DMA-Buffer-Manager.h"
#include "Terminal.h"

void vTask_Monitor(void *pvParameters)
{
	TickType_t xLastWakeTime;
    const TickType_t xFrequency = pdMS_TO_TICKS(3000); // 周期为1秒
    xLastWakeTime = xTaskGetTickCount(); // 初始化上次唤醒时间为当前时间
	for (;;)
	{
		GPIO_TogglePins(GPIOB, GPIO_Pin_15);
		Terminal_Output("Free Heap: %u bytes\n  %s: %u words\n",
			xPortGetMinimumEverFreeHeapSize(), pcTaskGetName(vTask_List[0]), uxTaskGetStackHighWaterMark(vTask_List[0]));
        vTaskDelayUntil(&xLastWakeTime, xFrequency); // 延迟到下一个周期点
	}
}

int main(void)
{
    SC_Init(); // 初始化芯片外设
	DMA_Buffer_Manager_Initialize(DMA_Buffer_Manager_UART1, 128, DMA0, UART0, DMA_UART); // 初始化DMA缓冲区管理器
    xTaskCreate(vTask_Monitor, "Monitor", 128, NULL, 1, &vTask_List[0]); // 创建监控任务
    vTaskStartScheduler(); // 启动调度器
    while (1);
}
