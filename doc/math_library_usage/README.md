# AW31N SDK 数学库使用指南

## 概述

AW31N SDK 是基于嵌入式环境的固件开发工具包，不使用标准C库的 `math.h`。本文档提供了在该SDK中进行数学运算的最佳实践和示例代码。

## 重要说明

⚠️ **本SDK不支持标准C数学库（math.h）**

原因：
- 嵌入式环境资源受限
- 避免浮点运算以提高性能
- 减小代码体积
- 优化执行速度

## 可用的数学运算方式

### 1. 编译器内建函数（推荐）

SDK使用GCC编译器，提供了多个内建函数：

```c
// 绝对值
int result = __builtin_abs(-42);  // 返回 42

// 位计数（计算二进制中1的个数）
unsigned int ones = __builtin_popcount(0xFF);  // 返回 8

// 前导零计数
unsigned int zeros = __builtin_clz(8);  // 返回 28 (32位系统)
```

### 2. 已有的SDK宏定义

在 `typedef.h` 中已定义：

```c
// 最大值/最小值
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// 位操作
#define BIT(n)              (1UL << (n))
#define BitSET(REG,POS)     ((REG) |= (1L << (POS)))
#define BitCLR(REG,POS)     ((REG) &= (~(1L<< (POS))))
```

### 3. 自定义实现

对于更复杂的数学运算，建议自己实现整数版本的函数。

## 示例代码说明

本目录包含以下文件：

### math_example.h
数学函数库头文件，提供常用数学运算的声明，包括：
- 基本算术运算（绝对值、最大最小值、限制等）
- 幂运算和平方根
- 位运算（popcount、clz、log2等）
- 插值和映射函数
- 距离计算
- 随机数生成

### math_example.c
数学函数库实现文件，包含所有函数的具体实现。

### math_usage_demo.c
完整的使用示例和测试代码，演示了：
- 基本数学运算测试
- 幂运算和平方根测试
- 位运算测试
- 插值和映射测试
- 距离计算测试
- 随机数生成测试
- 实际应用场景示例

## 快速开始

### 1. 将示例文件添加到你的项目

```bash
# 将 math_example.h 和 math_example.c 复制到你的项目源代码目录
cp doc/math_library_usage/math_example.h apps/demo/your_project/
cp doc/math_library_usage/math_example.c apps/demo/your_project/
```

### 2. 在你的代码中包含头文件

```c
#include "math_example.h"
```

### 3. 使用数学函数

```c
// 计算幂
u32 result = math_pow_u32(2, 10);  // 2^10 = 1024

// 计算平方根
u32 sqrt_val = math_sqrt_u32(100);  // sqrt(100) = 10

// 范围映射（例如ADC值转换）
s32 percentage = math_map(512, 0, 1023, 0, 100);  // 将ADC值映射到百分比
```

## 常用函数说明

### 基本运算

| 函数 | 说明 | 示例 |
|------|------|------|
| `math_abs(x)` | 整数绝对值 | `math_abs(-42)` → 42 |
| `MATH_MAX(a, b)` | 最大值 | `MATH_MAX(10, 20)` → 20 |
| `MATH_MIN(a, b)` | 最小值 | `MATH_MIN(10, 20)` → 10 |
| `MATH_CLAMP(val, min, max)` | 限制范围 | `MATH_CLAMP(5, 10, 20)` → 10 |

### 幂运算和平方根

| 函数 | 说明 | 示例 |
|------|------|------|
| `math_pow_u32(base, exp)` | 整数幂运算 | `math_pow_u32(2, 10)` → 1024 |
| `math_square(x)` | 平方 | `math_square(5)` → 25 |
| `math_sqrt_u32(x)` | 整数平方根 | `math_sqrt_u32(100)` → 10 |

### 位运算

| 函数 | 说明 | 示例 |
|------|------|------|
| `math_popcount(x)` | 统计二进制1的个数 | `math_popcount(0xFF)` → 8 |
| `math_clz(x)` | 前导零计数 | `math_clz(8)` → 28 |
| `math_log2(x)` | 以2为底的对数 | `math_log2(16)` → 4 |
| `math_is_power_of_2(x)` | 判断是否为2的幂 | `math_is_power_of_2(16)` → 1 |

### 映射和插值

| 函数 | 说明 | 应用场景 |
|------|------|----------|
| `math_map()` | 范围映射 | ADC值转换、传感器校准 |
| `math_lerp()` | 线性插值 | 平滑过渡、动画效果 |

## 实际应用场景

### 场景1：ADC值处理

```c
// 读取ADC值（0-1023）并转换为百分比
u32 adc_value = read_adc();
s32 percentage = math_map(adc_value, 0, 1023, 0, 100);
printf("电池电量: %d%%\n", percentage);
```

### 场景2：传感器位置检测

```c
// 计算两个位置之间的移动距离
s32 old_x = 100, old_y = 200;
s32 new_x = 103, new_y = 204;
u32 distance = math_distance(old_x, old_y, new_x, new_y);

if (distance > THRESHOLD) {
    // 触发移动事件
    handle_movement_event();
}
```

### 场景3：内存对齐

```c
// 将内存大小对齐到2的幂（用于DMA、缓冲区等）
u32 buffer_size = 100;
u32 aligned_size = math_round_up_pow2(buffer_size);  // 返回 128
allocate_buffer(aligned_size);
```

### 场景4：随机数生成

```c
// 生成随机延迟时间（用于重传、防冲突等）
u32 seed = get_system_tick();
u32 random_delay = math_rand_range(&seed, 10, 100);  // 10-100ms范围
delay_ms(random_delay);
```

## 性能考虑

1. **使用内联函数**：简单的运算函数声明为 `static inline`，减少函数调用开销
2. **整数运算**：所有运算都基于整数，避免浮点运算
3. **位运算优化**：使用位运算代替乘除法（如 `x << 1` 代替 `x * 2`）
4. **编译器内建函数**：使用 `__builtin_*` 函数获得最佳性能

## 注意事项

1. ⚠️ 所有函数都是整数运算，会有精度损失
2. ⚠️ 幂运算和乘法可能溢出，注意输入范围
3. ⚠️ 除法运算不要除以0
4. ⚠️ 平方根结果是向下取整的整数

## 如何运行测试

如果要在你的应用中运行完整的测试：

```c
#include "math_example.h"

// 在你的main函数或应用启动代码中调用
void app_start(void)
{
    // ... 其他初始化代码 ...
    
    // 运行数学库测试
    math_library_demo();
    
    // ... 应用主循环 ...
}
```

## 参考

- SDK现有实现：`apps/app/bsp/common/norflash/norflash.c` 中的 `_pow()` 函数
- typedef定义：`apps/include_lib/cpu/bd47/typedef.h`
- SDK文档：见 `doc/` 目录

## 许可

本示例代码遵循 AW31N SDK 的许可协议。

---

# English Version

# AW31N SDK Math Library Usage Guide

## Overview

AW31N SDK is an embedded firmware development kit that does not use the standard C library's `math.h`. This document provides best practices and sample code for mathematical operations in this SDK.

## Important Notice

⚠️ **This SDK does not support the standard C math library (math.h)**

Reasons:
- Limited resources in embedded environment
- Avoiding floating-point operations for better performance
- Reducing code size
- Optimizing execution speed

## Available Mathematical Operations

### 1. Compiler Built-in Functions (Recommended)

The SDK uses GCC compiler which provides several built-in functions:

```c
// Absolute value
int result = __builtin_abs(-42);  // Returns 42

// Population count (count 1s in binary)
unsigned int ones = __builtin_popcount(0xFF);  // Returns 8

// Count leading zeros
unsigned int zeros = __builtin_clz(8);  // Returns 28 (on 32-bit system)
```

### 2. Existing SDK Macros

Defined in `typedef.h`:

```c
// Max/Min
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// Bit operations
#define BIT(n)              (1UL << (n))
#define BitSET(REG,POS)     ((REG) |= (1L << (POS)))
#define BitCLR(REG,POS)     ((REG) &= (~(1L<< (POS))))
```

### 3. Custom Implementation

For more complex mathematical operations, implement integer versions of the functions yourself.

## Example Code Description

This directory contains the following files:

### math_example.h
Math function library header file with declarations for common operations including:
- Basic arithmetic (abs, max/min, clamp, etc.)
- Power and square root
- Bit operations (popcount, clz, log2, etc.)
- Interpolation and mapping
- Distance calculation
- Random number generation

### math_example.c
Implementation file with all function implementations.

### math_usage_demo.c
Complete usage examples and test code demonstrating:
- Basic math operation tests
- Power and square root tests
- Bit operation tests
- Interpolation and mapping tests
- Distance calculation tests
- Random number generation tests
- Real-world application scenarios

## Quick Start

### 1. Add Example Files to Your Project

```bash
# Copy math_example.h and math_example.c to your project source directory
cp doc/math_library_usage/math_example.h apps/demo/your_project/
cp doc/math_library_usage/math_example.c apps/demo/your_project/
```

### 2. Include the Header in Your Code

```c
#include "math_example.h"
```

### 3. Use Math Functions

```c
// Calculate power
u32 result = math_pow_u32(2, 10);  // 2^10 = 1024

// Calculate square root
u32 sqrt_val = math_sqrt_u32(100);  // sqrt(100) = 10

// Range mapping (e.g., ADC conversion)
s32 percentage = math_map(512, 0, 1023, 0, 100);  // Map ADC value to percentage
```

## Common Function Reference

### Basic Operations

| Function | Description | Example |
|----------|-------------|---------|
| `math_abs(x)` | Integer absolute value | `math_abs(-42)` → 42 |
| `MATH_MAX(a, b)` | Maximum value | `MATH_MAX(10, 20)` → 20 |
| `MATH_MIN(a, b)` | Minimum value | `MATH_MIN(10, 20)` → 10 |
| `MATH_CLAMP(val, min, max)` | Clamp to range | `MATH_CLAMP(5, 10, 20)` → 10 |

### Power and Square Root

| Function | Description | Example |
|----------|-------------|---------|
| `math_pow_u32(base, exp)` | Integer power | `math_pow_u32(2, 10)` → 1024 |
| `math_square(x)` | Square | `math_square(5)` → 25 |
| `math_sqrt_u32(x)` | Integer square root | `math_sqrt_u32(100)` → 10 |

### Bit Operations

| Function | Description | Example |
|----------|-------------|---------|
| `math_popcount(x)` | Count 1s in binary | `math_popcount(0xFF)` → 8 |
| `math_clz(x)` | Count leading zeros | `math_clz(8)` → 28 |
| `math_log2(x)` | Log base 2 | `math_log2(16)` → 4 |
| `math_is_power_of_2(x)` | Check if power of 2 | `math_is_power_of_2(16)` → 1 |

### Mapping and Interpolation

| Function | Description | Use Case |
|----------|-------------|----------|
| `math_map()` | Range mapping | ADC conversion, sensor calibration |
| `math_lerp()` | Linear interpolation | Smooth transitions, animations |

## Real-World Use Cases

### Case 1: ADC Value Processing

```c
// Read ADC value (0-1023) and convert to percentage
u32 adc_value = read_adc();
s32 percentage = math_map(adc_value, 0, 1023, 0, 100);
printf("Battery: %d%%\n", percentage);
```

### Case 2: Sensor Position Detection

```c
// Calculate movement distance between two positions
s32 old_x = 100, old_y = 200;
s32 new_x = 103, new_y = 204;
u32 distance = math_distance(old_x, old_y, new_x, new_y);

if (distance > THRESHOLD) {
    // Trigger movement event
    handle_movement_event();
}
```

### Case 3: Memory Alignment

```c
// Align memory size to power of 2 (for DMA, buffers, etc.)
u32 buffer_size = 100;
u32 aligned_size = math_round_up_pow2(buffer_size);  // Returns 128
allocate_buffer(aligned_size);
```

### Case 4: Random Number Generation

```c
// Generate random delay (for retry, collision avoidance, etc.)
u32 seed = get_system_tick();
u32 random_delay = math_rand_range(&seed, 10, 100);  // 10-100ms range
delay_ms(random_delay);
```

## Performance Considerations

1. **Use inline functions**: Simple operations declared as `static inline` reduce call overhead
2. **Integer operations**: All operations are integer-based, avoiding floating-point
3. **Bit operation optimization**: Use bit shifts instead of multiply/divide (e.g., `x << 1` instead of `x * 2`)
4. **Compiler built-ins**: Use `__builtin_*` functions for best performance

## Cautions

1. ⚠️ All functions use integer arithmetic - precision loss may occur
2. ⚠️ Power and multiplication operations may overflow - watch input ranges
3. ⚠️ Division operations must not divide by zero
4. ⚠️ Square root results are rounded down integers

## Running Tests

To run the complete test suite in your application:

```c
#include "math_example.h"

// Call in your main function or application startup code
void app_start(void)
{
    // ... other initialization code ...
    
    // Run math library test
    math_library_demo();
    
    // ... application main loop ...
}
```

## References

- SDK existing implementation: `_pow()` function in `apps/app/bsp/common/norflash/norflash.c`
- Typedef definitions: `apps/include_lib/cpu/bd47/typedef.h`
- SDK documentation: see `doc/` directory

## License

This example code follows the AW31N SDK license agreement.
