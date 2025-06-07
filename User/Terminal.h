#ifndef Terminal_H
#define Terminal_H

#include "SC_Init.h"  // 系统初始化相关头文件
#include <stdarg.h>   // 支持可变参数

/**
 * @brief 终端提示符配置（可自定义）
 *
 * 用户可在编译前通过此宏修改提示符（默认为 "$"）
 * 示例：#define Terminal_Prompt "CMD>"
 */
#define Terminal_Prompt "$"  // 定义终端提示符

/**
 * @brief 格式化输出终端提示符和内容
 *
 * 支持的格式符：
 * - %u: 无符号整数（例如：Terminal_Output("Value: %u", 123);）
 * - %s: 字符串（例如：Terminal_Output("Hello, %s", "World");）
 *
 * @param format 格式化字符串（类似 printf）
 * @param ...    可变参数列表（与格式符匹配的数据）
 * @return uint8_t 实际发送的字节数（可能因缓冲区溢出截断）
 */
uint8_t Terminal_Output(const char* format, ...);

#endif  // Terminal_H
