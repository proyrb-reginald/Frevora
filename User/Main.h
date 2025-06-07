#ifndef Main_H
#define Main_H

#include "FreeRTOS.h"
#include "task.h"

#define Task_List_Length 3  // 定义任务列表长度

extern TaskHandle_t vTask_List[Task_List_Length];

#ifdef Main_C
TaskHandle_t vTask_List[Task_List_Length];
#endif  // Main_C

void vTask_Monitor(void* pvParameters);

#endif  // Main_H
