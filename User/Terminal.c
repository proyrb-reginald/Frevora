#include "Terminal.h"
#include "FreeRTOS.h"
#include "DMA-Buffer-Manager.h"
#include <string.h>

#ifndef Terminal_Prompt
#define Terminal_Prompt "$ " // 定义终端提示符
#endif // Terminal_Prompt

// 缓冲区大小（根据实际需求调整）
#define Buffer_Size 128

// 用于将数字转换为字符串的辅助函数
static void uint_to_str(unsigned int num, char* buf, size_t* len)
{
    if (num == 0) {
        buf[0] = '0';
        *len = 1;
        return;
    }
    char temp[10]; // 32位无符号整数最多10位
    int i = 0;
    while (num > 0)
    {
        temp[i++] = '0' + (num % 10);
        num /= 10;
    }
    // 倒序复制到输出缓冲区
    *len = i;
    while (i > 0)
    {
        buf[*len - i] = temp[i - 1];
        i--;
    }
}

uint8_t Terminal_Output(const char* format, ...)
{
    char buf[Buffer_Size];
    size_t pos = 0;
    va_list args;
    va_start(args, format);
    // 添加宏定义的前缀
    const char* prefix = "$ ";
    size_t prefix_len = strlen(prefix);
    memcpy(buf, prefix, prefix_len);
    pos = prefix_len;
    // 处理格式化内容
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'u':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    size_t num_len;
                    uint_to_str(num, buf + pos, &num_len);
                    pos += num_len;
                    break;
                }
                case 's':
                {
                    const char* str = va_arg(args, const char*);
                    if (str)
                    {
                        size_t str_len = strlen(str);
                        if (pos + str_len < Buffer_Size)
                        {
                            memcpy(buf + pos, str, str_len);
                            pos += str_len;
                        }
                    }
                    break;
                }
            }
        } else
        {
            if (pos < Buffer_Size)
            {
                buf[pos++] = *format;
            }
        }
        format++;
    }
    DMA_Buffer_Manager_Input(DMA_Buffer_Manager_UART1, (uint8_t *)buf, pos); // 一次性发送所有数据
    va_end(args);
    return pos;
}
