/*
 * FreeRTOS 内核 V11.2.0
 * 版权所有 (C) 2021 Amazon.com, Inc. 或其关联公司。保留所有权利。
 *
 * SPDX-License-Identifier: MIT
 *
 * 特此授权，无需费用，任何人可获取该软件和相关文档文件（"软件"）副本进行使用、
 * 复制、修改、合并、发布、分发、再许可和/或出售软件副本，并允许其进行上述行为，
 * 条件是需遵守以下约束：
 *
 * 上述版权声明和本许可声明需包含在所有软件副本或实质性部分中。
 *
 * 软件按"原样"提供，不提供任何明示或暗示的担保，包括但不限于适销性、特定用途适用性和
 * 非侵权担保。在任何情况下，作者或版权持有者均不对任何索赔、损害或其他责任负责，无论
 * 是合同诉讼、侵权行为还是其他方式，由软件使用或与之相关的活动引起。
 *
 * https://www.FreeRTOS.org 
 * https://github.com/FreeRTOS 
 *
 */
/*******************************************************************************
 * 该文件提供了一个示例FreeRTOSConfig.h头文件，包含对每个配置项的简要说明。
 * 在线文档和参考手册提供更多信息。
 * https://www.freertos.org/a00110.html 
 *
 * 方括号('['和']')括起的常量值必须在文件构建前完成填写。
 *
 * 优先使用随具体RTOS端口提供的FreeRTOSConfig.h文件，而非此通用文件。
 ******************************************************************************/
#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H
/******************************************************************************/
/* 硬件相关定义 ***************************************************************/
/******************************************************************************/
/* configCPU_CLOCK_HZ通常需设置为驱动滴答中断外设的时钟频率。
 * 默认值20MHz匹配QEMU演示设置。实际应用需根据硬件修改。
 * 通常（但不总是）等于主系统时钟频率 */
#define configCPU_CLOCK_HZ    ( ( unsigned long ) 64000000 )
/* configSYSTICK_CLOCK_HZ仅适用于ARM Cortex-M端口（可选参数）。
 *
 * 默认情况下ARM Cortex-M端口使用Cortex-M SysTick定时器生成RTOS滴答中断。
 * 大多数Cortex-M微控制器以与MCU相同频率运行SysTick定时器 - 此时无需定义该参数。
 * 如果SysTick时钟频率与MCU内核不同，则设置configCPU_CLOCK_HZ为MCU时钟频率，
 * configSYSTICK_CLOCK_HZ为SysTick时钟频率。未定义时不使用。
 * 默认值已注释（8000000Hz） */
#define configSYSTICK_CLOCK_HZ                     8000000
/******************************************************************************/
/* 调度行为相关定义 ***********************************************************/
/******************************************************************************/
/* configTICK_RATE_HZ设置滴答中断频率（Hz），通常根据configCPU_CLOCK_HZ计算 */
#define configTICK_RATE_HZ                         1000
/* 设置configUSE_PREEMPTION为1启用抢占式调度，为0使用协作式调度 */
#define configUSE_PREEMPTION                       1
/* 设置configUSE_TIME_SLICING为1在每次滴答中断时切换同优先级就绪任务，
 * 为0禁止仅因滴答中断触发的任务切换 */
#define configUSE_TIME_SLICING                     1
/* 设置configUSE_PORT_OPTIMISED_TASK_SELECTION为1使用针对目标硬件指令集优化的
 * 任务选择算法（通常使用CLZ汇编指令），为0使用通用C算法。并非所有端口支持该选项 */
#define configUSE_PORT_OPTIMISED_TASK_SELECTION    0
/* 设置configUSE_TICKLESS_IDLE为1启用低功耗无滴答模式，为0保持持续滴答中断 */
#define configUSE_TICKLESS_IDLE                    0
/* configMAX_PRIORITIES设置可用任务优先级数量（0到configMAX_PRIORITIES-1）
 * 0为最低优先级 */
#define configMAX_PRIORITIES                       8
/* configMINIMAL_STACK_SIZE定义空闲任务使用的堆栈大小（以字为单位，非字节）*/
#define configMINIMAL_STACK_SIZE                   128
/* configMAX_TASK_NAME_LEN设置任务名称最大长度（含NULL终止符） */
#define configMAX_TASK_NAME_LEN                    32
/* 时间以"滴答"为单位计量 - 自RTOS启动以来的中断次数
 * 滴答计数类型为TickType_t
 *
 * configTICK_TYPE_WIDTH_IN_BITS控制TickType_t的位宽：
 * TICK_TYPE_WIDTH_16_BITS表示16位无符号类型
 * TICK_TYPE_WIDTH_32_BITS表示32位无符号类型
 * TICK_TYPE_WIDTH_64_BITS表示64位无符号类型 */
#define configTICK_TYPE_WIDTH_IN_BITS              TICK_TYPE_WIDTH_32_BITS
/* 设置configIDLE_SHOULD_YIELD为1使空闲任务在存在同优先级应用任务时主动让出，
 * 为0使空闲任务用完时间片 */
#define configIDLE_SHOULD_YIELD                    1
/* 每个任务具有任务通知数组，configTASK_NOTIFICATION_ARRAY_ENTRIES
 * 设置数组索引数量 */
#define configTASK_NOTIFICATION_ARRAY_ENTRIES      1
/* configQUEUE_REGISTRY_SIZE设置队列注册表最大容量（调试器使用） */
#define configQUEUE_REGISTRY_SIZE                  4
/* 设置configENABLE_BACKWARD_COMPATIBILITY为1启用旧版本兼容映射 */
#define configENABLE_BACKWARD_COMPATIBILITY        0
/* 每个任务具有线程本地存储指针数组，configNUM_THREAD_LOCAL_STORAGE_POINTERS
 * 设置数组大小 */
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS    0
/* 设置configUSE_MINI_LIST_ITEM为0时MiniListItem_t和ListItem_t相同，
 * 为1时MiniListItem_t减少3个字段（节省RAM但违反严格别名规则） */
#define configUSE_MINI_LIST_ITEM                   0
/* 设置xTaskCreate()栈大小参数类型，默认为size_t */
#define configSTACK_DEPTH_TYPE                     size_t
/* 设置message buffer长度类型，默认为size_t */
#define configMESSAGE_BUFFER_LENGTH_TYPE           size_t
/* 设置configHEAP_CLEAR_MEMORY_ON_FREE为1时释放内存会清零 */
#define configHEAP_CLEAR_MEMORY_ON_FREE            0
/* vTaskList等API使用的缓冲区长度，默认0xFFFF */
#define configSTATS_BUFFER_MAX_LENGTH              0xFFFF
/* 设置configUSE_NEWLIB_REENTRANT为1为每个任务分配newlib重入结构 */
#define configUSE_NEWLIB_REENTRANT                 0
/******************************************************************************/
/* 软件定时器相关定义 *******************************************************/
/******************************************************************************/
/* 设置configUSE_TIMERS为1包含软件定时器功能 */
#define configUSE_TIMERS                0
/* configTIMER_TASK_PRIORITY设置定时器任务优先级 */
#define configTIMER_TASK_PRIORITY       ( configMAX_PRIORITIES - 1 )
/* configTIMER_TASK_STACK_DEPTH设置定时器任务堆栈大小 */
#define configTIMER_TASK_STACK_DEPTH    configMINIMAL_STACK_SIZE
/* configTIMER_QUEUE_LENGTH设置定时器命令队列长度 */
#define configTIMER_QUEUE_LENGTH        10
/******************************************************************************/
/* 事件组相关定义 ***********************************************************/
/******************************************************************************/
/* 设置configUSE_EVENT_GROUPS为1包含事件组功能 */
#define configUSE_EVENT_GROUPS    1
/******************************************************************************/
/* 流缓冲区相关定义 *********************************************************/
/******************************************************************************/
/* 设置configUSE_STREAM_BUFFERS为1包含流缓冲区功能 */
#define configUSE_STREAM_BUFFERS    0
/******************************************************************************/
/* 内存分配相关定义 *********************************************************/
/******************************************************************************/
/* 设置configSUPPORT_STATIC_ALLOCATION为1启用静态内存分配API */
#define configSUPPORT_STATIC_ALLOCATION              0
/* 设置configSUPPORT_DYNAMIC_ALLOCATION为1启用动态内存分配API */
#define configSUPPORT_DYNAMIC_ALLOCATION             1
/* 设置heap_1/2/4.c使用的堆大小（字节） */
#define configTOTAL_HEAP_SIZE                        (12*1024)
/* 设置configAPPLICATION_ALLOCATED_HEAP为1由应用分配堆内存 */
#define configAPPLICATION_ALLOCATED_HEAP             0
/* 设置configSTACK_ALLOCATION_FROM_SEPARATE_HEAP为1从独立堆分配任务栈 */
#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP    0
/* 设置configENABLE_HEAP_PROTECTOR为1启用堆保护 */
#define configENABLE_HEAP_PROTECTOR                  0
/******************************************************************************/
/* 中断嵌套行为配置 *********************************************************/
/******************************************************************************/
/* configKERNEL_INTERRUPT_PRIORITY设置滴答中断优先级 */
#define configKERNEL_INTERRUPT_PRIORITY          0
/* configMAX_SYSCALL_INTERRUPT_PRIORITY设置不允许调用API的中断优先级上限 */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY     0
/* configMAX_API_CALL_INTERRUPT_PRIORITY是另一个同义定义 */
#define configMAX_API_CALL_INTERRUPT_PRIORITY    0
/******************************************************************************/
/* 钩子函数相关定义 *********************************************************/
/******************************************************************************/
/* 设置以下configUSE_*为1启用对应钩子函数 */
#define configUSE_IDLE_HOOK                   0
#define configUSE_TICK_HOOK                   0
#define configUSE_MALLOC_FAILED_HOOK          0
#define configUSE_DAEMON_TASK_STARTUP_HOOK    0
/* 设置configUSE_SB_COMPLETED_CALLBACK为1启用流缓冲区完成回调 */
#define configUSE_SB_COMPLETED_CALLBACK       0
/* 设置configCHECK_FOR_STACK_OVERFLOW为1/2启用栈溢出检测 */
#define configCHECK_FOR_STACK_OVERFLOW        0
/******************************************************************************/
/* 运行时统计相关定义 *******************************************************/
/******************************************************************************/
/* 设置configGENERATE_RUN_TIME_STATS为1启用任务运行时间统计 */
#define configGENERATE_RUN_TIME_STATS           0
/* 设置configUSE_TRACE_FACILITY为1包含调试跟踪信息 */
#define configUSE_TRACE_FACILITY                0
/* 设置configUSE_STATS_FORMATTING_FUNCTIONS为1包含统计格式化函数 */
#define configUSE_STATS_FORMATTING_FUNCTIONS    0
/******************************************************************************/
/* 协程相关定义 *************************************************************/
/******************************************************************************/
/* 设置configUSE_CO_ROUTINES为1包含协程功能 */
#define configUSE_CO_ROUTINES              0
/* configMAX_CO_ROUTINE_PRIORITIES设置协程优先级数量 */
#define configMAX_CO_ROUTINE_PRIORITIES    1
/******************************************************************************/
/* 调试辅助 *****************************************************************/
/******************************************************************************/
/* configASSERT()定义断言行为 */
#define configASSERT( x )         \
    if( ( x ) == 0 )              \
    {                             \
        taskDISABLE_INTERRUPTS(); \
        for( ; ; )                \
        ;                         \
    }
/******************************************************************************/
/* FreeRTOS MPU专用定义 *****************************************************/
/******************************************************************************/
/* 设置configINCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS为1允许应用
 * 定义特权函数 */
#define configINCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS    0
/* configTOTAL_MPU_REGIONS设置MPU区域数量 */
#define configTOTAL_MPU_REGIONS                                   8
/* configTEX_S_C_B_FLASH配置Flash内存属性 */
#define configTEX_S_C_B_FLASH                                     0x07UL
/* configTEX_S_C_B_SRAM配置RAM内存属性 */
#define configTEX_S_C_B_SRAM                                      0x07UL
/* configENFORCE_SYSTEM_CALLS_FROM_KERNEL_ONLY控制特权调用 */
#define configENFORCE_SYSTEM_CALLS_FROM_KERNEL_ONLY               1
/* configALLOW_UNPRIVILEGED_CRITICAL_SECTIONS控制非特权临界区 */
#define configALLOW_UNPRIVILEGED_CRITICAL_SECTIONS                0
/* configUSE_MPU_WRAPPERS_V1选择MPU包装版本 */
#define configUSE_MPU_WRAPPERS_V1                                 0
/* configPROTECTED_KERNEL_OBJECT_POOL_SIZE设置内核对象池大小 */
#define configPROTECTED_KERNEL_OBJECT_POOL_SIZE                   10
/* configSYSTEM_CALL_STACK_SIZE设置系统调用栈大小 */
#define configSYSTEM_CALL_STACK_SIZE                              128
/* configENABLE_ACCESS_CONTROL_LIST启用访问控制列表 */
#define configENABLE_ACCESS_CONTROL_LIST                          1
/******************************************************************************/
/* SMP多核配置 **************************************************************/
/******************************************************************************/
/* configNUMBER_OF_CORES设置核心数量 */
/*
 #define configNUMBER_OF_CORES                     [可用核心数]
 */
/* configRUN_MULTIPLE_PRIORITIES控制多优先级任务并行 */
#define configRUN_MULTIPLE_PRIORITIES             0
/* configUSE_CORE_AFFINITY启用核心亲和性 */
#define configUSE_CORE_AFFINITY                   0
/* configTASK_DEFAULT_CORE_AFFINITY设置默认核心亲和掩码 */
#define configTASK_DEFAULT_CORE_AFFINITY          tskNO_AFFINITY
/* configUSE_TASK_PREEMPTION_DISABLE允许任务单独禁用抢占 */
#define configUSE_TASK_PREEMPTION_DISABLE         0
/* configUSE_PASSIVE_IDLE_HOOK启用被动空闲钩子 */
#define configUSE_PASSIVE_IDLE_HOOK               0
/* configTIMER_SERVICE_TASK_CORE_AFFINITY设置定时器任务亲和性 */
#define configTIMER_SERVICE_TASK_CORE_AFFINITY    tskNO_AFFINITY
/******************************************************************************/
/* ARMv8-M安全侧端口定义 ***************************************************/
/******************************************************************************/
/* secureconfigMAX_SECURE_CONTEXTS设置安全上下文最大数量 */
#define secureconfigMAX_SECURE_CONTEXTS        5
/* configKERNEL_PROVIDED_STATIC_MEMORY启用内核静态内存分配 */
#define configKERNEL_PROVIDED_STATIC_MEMORY    1
/******************************************************************************/
/* ARMv8-M端口配置 **********************************************************/
/******************************************************************************/
/* configENABLE_TRUSTZONE启用TrustZone支持 */
#define configENABLE_TRUSTZONE            1
/* configRUN_FREERTOS_SECURE_ONLY在安全侧运行FreeRTOS */
#define configRUN_FREERTOS_SECURE_ONLY    1
/* configENABLE_MPU启用内存保护单元 */
#define configENABLE_MPU                  0
/* configENABLE_FPU启用浮点单元 */
#define configENABLE_FPU                  0
/* configENABLE_MVE启用M-Profile向量扩展 */
#define configENABLE_MVE                  0
/******************************************************************************/
/* ARMv7-M/ARMv8-M端口配置 **************************************************/
/******************************************************************************/
/* configCHECK_HANDLER_INSTALLATION验证中断处理安装 */
#define configCHECK_HANDLER_INSTALLATION    1
/******************************************************************************/
/* 功能包含/排除定义 *******************************************************/
/******************************************************************************/
/* 设置以下configUSE_*为1包含对应功能 */
#define configUSE_TASK_NOTIFICATIONS           1
#define configUSE_MUTEXES                      1
#define configUSE_RECURSIVE_MUTEXES            1
#define configUSE_COUNTING_SEMAPHORES          1
#define configUSE_QUEUE_SETS                   0
#define configUSE_APPLICATION_TASK_TAG         0
#define configUSE_POSIX_ERRNO                  0
/* 设置以下INCLUDE_*为1包含对应API */
#define INCLUDE_vTaskPrioritySet               1
#define INCLUDE_uxTaskPriorityGet              1
#define INCLUDE_vTaskDelete                    1
#define INCLUDE_vTaskSuspend                   1
#define INCLUDE_vTaskDelayUntil                1
#define INCLUDE_vTaskDelay                     1
#define INCLUDE_xTaskGetSchedulerState         0
#define INCLUDE_xTaskGetCurrentTaskHandle      1
#define INCLUDE_uxTaskGetStackHighWaterMark    1
#define INCLUDE_xTaskGetIdleTaskHandle         1
#define INCLUDE_eTaskGetState                  0
#define INCLUDE_xTimerPendFunctionCall         0
#define INCLUDE_xTaskAbortDelay                0
#define INCLUDE_xTaskGetHandle                 1
#define INCLUDE_xTaskResumeFromISR             1

#define SysTick_Handler SysTick_IRQHandler /* 确保SysTick_Handler指向正确的中断处理函数 */

#endif /* FREERTOS_CONFIG_H */