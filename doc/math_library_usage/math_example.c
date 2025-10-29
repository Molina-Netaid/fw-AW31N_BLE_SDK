/**
 * @file math_example.c
 * @brief AW31N SDK数学库使用示例实现
 * 
 * 本文件提供了嵌入式环境下常用数学运算的实现
 * 所有函数都是基于整数运算，避免使用浮点数以提高性能
 * 
 * @author AW31N SDK Example
 * @date 2025-01-29
 */

#include "math_example.h"

/**
 * @brief 整数幂运算
 * 使用快速幂算法（分治法）
 */
u32 math_pow_u32(u32 base, u32 exp)
{
    u32 result = 1;
    
    while (exp > 0) {
        if (exp & 1) {
            result *= base;
        }
        base *= base;
        exp >>= 1;
    }
    
    return result;
}

/**
 * @brief 整数平方根（牛顿迭代法）
 * 计算精度：返回不大于真实值的最大整数
 */
u32 math_sqrt_u32(u32 x)
{
    if (x == 0) {
        return 0;
    }
    
    // 初始估计值
    u32 guess = x;
    u32 result = (guess + 1) / 2;
    
    // 牛顿迭代
    while (result < guess) {
        guess = result;
        result = (guess + x / guess) / 2;
    }
    
    return guess;
}

/**
 * @brief 线性插值
 */
s32 math_lerp(s32 x0, s32 y0, s32 x1, s32 y1, s32 x)
{
    if (x1 == x0) {
        return y0;
    }
    
    // 使用64位避免溢出
    s64 result = (s64)y0 + ((s64)(y1 - y0) * (s64)(x - x0)) / (s64)(x1 - x0);
    return (s32)result;
}

/**
 * @brief 将值从一个范围映射到另一个范围
 */
s32 math_map(s32 val, s32 in_min, s32 in_max, s32 out_min, s32 out_max)
{
    if (in_max == in_min) {
        return out_min;
    }
    
    // 使用64位避免溢出
    s64 result = (s64)out_min + ((s64)(val - in_min) * (s64)(out_max - out_min)) / (s64)(in_max - in_min);
    return (s32)result;
}

/**
 * @brief 计算两点之间的距离（整数近似）
 * 使用勾股定理: distance = sqrt((x2-x1)^2 + (y2-y1)^2)
 */
u32 math_distance(s32 x1, s32 y1, s32 x2, s32 y2)
{
    s32 dx = x2 - x1;
    s32 dy = y2 - y1;
    
    // 计算平方
    u32 dx_sq = (u32)(dx * dx);
    u32 dy_sq = (u32)(dy * dy);
    
    // 返回平方根
    return math_sqrt_u32(dx_sq + dy_sq);
}

/**
 * @brief 向上取整到2的幂
 */
u32 math_round_up_pow2(u32 x)
{
    if (x == 0) {
        return 1;
    }
    
    if (math_is_power_of_2(x)) {
        return x;
    }
    
    // 找到大于x的最小2的幂
    return 1U << (32 - __builtin_clz(x));
}

/**
 * @brief 简单的伪随机数生成器（线性同余法）
 * 参数来自 Numerical Recipes
 * LCG公式: next = (a * seed + c) mod m
 */
u32 math_rand(u32 *seed)
{
    *seed = (*seed * 1664525UL + 1013904223UL);
    return *seed;
}

/**
 * @brief 生成指定范围内的随机数
 */
u32 math_rand_range(u32 *seed, u32 min, u32 max)
{
    if (min >= max) {
        return min;
    }
    
    u32 range = max - min + 1;
    return min + (math_rand(seed) % range);
}
