#ifndef Terminal_H
#define Terminal_H

#include "SC_Init.h"
#include <stdarg.h>

#define Terminal_Prompt "$ " // 定义终端提示符

uint8_t Terminal_Output(const char* format, ...);

#endif // Terminal_H
