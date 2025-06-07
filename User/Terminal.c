#include "Terminal.h"            // 终端模块头文件，声明接口和配置
#include "DMA-Buffer-Manager.h"  // DMA 缓冲区管理模块
#include "FreeRTOS.h"            // FreeRTOS 内核支持
#include <string.h>              // 标准库字符串函数

// 如果未在外部定义终端提示符，则使用默认值 "$"
#ifndef Terminal_Prompt
#    define Terminal_Prompt "$"  // 定义终端提示符（可自定义）
#endif                           // Terminal_Prompt

// 发送缓冲区大小（需根据实际通信速率和数据量调整）
#define Buffer_Size 128

/**
 * @brief 将无符号整数转换为字符串（内部辅助函数）
 *
 * @param num 待转换的无符号整数
 * @param buf 输出缓冲区（存储转换后的字符串）
 * @param len 输出字符串长度（通过指针返回）
 */
static void uint_to_str(unsigned int num, char* buf, size_t* len)
{
    // 特殊处理数值0
    if (num == 0) {
        buf[0] = '0';
        *len   = 1;
        return;
    }
    // 临时缓冲区存储逆序数字字符（32位最大值为10位）
    char temp[10];
    int  i = 0;
    // 分解数字并逆序存储到temp
    while (num > 0) {
        temp[i++] = '0' + (num % 10);  // 取个位并转为字符
        num /= 10;                     // 移除个位
    }
    // 将temp中的字符倒序复制到输出缓冲区buf
    *len = i;  // 记录字符串长度
    while (i > 0) {
        buf[*len - i] = temp[i - 1];  // 倒序复制
        i--;
    }
}

/**
 * @brief 格式化输出终端提示符和内容（类似 printf 的功能）
 *
 * 支持的格式符：
 * - %u: 无符号整数
 * - %s: 字符串
 *
 * @param format 格式化字符串
 * @param ...    可变参数列表（与格式符匹配的数据）
 * @return uint8_t 实际发送的字节数（可能因缓冲区溢出截断）
 */
uint8_t Terminal_Output(const char* format, ...)
{
    char    buf[Buffer_Size];  // 本地缓冲区（存储最终输出内容）
    size_t  pos = 0;           // 当前缓冲区写入位置索引
    va_list args;              // 可变参数列表
    va_start(args, format);    // 初始化参数解析
    // 添加宏定义的前缀
    const char* prefix     = Terminal_Prompt;  // 获取提示符
    size_t      prefix_len = strlen(prefix);   // 提示符长度
    memcpy(buf, prefix, prefix_len);           // 复制到缓冲区
    pos = prefix_len;                          // 更新写入位置
    // 解析格式化字符串并填充参数
    while (*format != '\0') {
        if (*format == '%')  // 检测格式符
        {
            format++;  // 跳过 '%' 字符
            switch (*format) {
                case 'u':  // 处理无符号整数
                {
                    unsigned int num = va_arg(args, unsigned int);  // 读取参数
                    size_t       num_len;
                    uint_to_str(num, buf + pos, &num_len);  // 转换为字符串
                    pos += num_len;                         // 更新写入位置
                    break;
                }
                case 's':  // 处理字符串
                {
                    const char* str = va_arg(args, const char*);  // 读取参数
                    if (str) {
                        size_t str_len = strlen(str);  // 字符串长度
                        // 检查缓冲区剩余空间
                        if (pos + str_len < Buffer_Size) {
                            memcpy(buf + pos, str, str_len);  // 复制到缓冲区
                            pos += str_len;                   // 更新写入位置
                        }
                    }
                    break;
                }
                default:  // 未处理的格式符：直接跳过（可扩展）
                    break;
            }
        }
        else  // 普通字符直接写入缓冲区
        {
            if (pos < Buffer_Size) {
                buf[pos++] = *format;
            }
        }
        format++;  // 移动到下一个字符
    }
    DMA_Buffer_Manager_Input(&DMA_Buffer_Manager_UART1, (uint8_t*)buf,
                             pos);  // 一次性发送所有数据
    va_end(args);                   // 结束可变参数处理
    return pos;                     // 返回发送的字节数
}
