/**
 * @file math_example.h
 * @brief AW31N SDK数学库使用示例头文件
 * 
 * 本SDK基于嵌入式环境，不使用标准C库的math.h
 * 提供常用数学运算的实现示例
 * 
 * @author AW31N SDK Example
 * @date 2025-01-29
 */

#ifndef _MATH_EXAMPLE_H_
#define _MATH_EXAMPLE_H_

#include "typedef.h"

/**
 * @brief 整数绝对值
 * @param x 输入值
 * @return 绝对值
 * @note 使用编译器内建函数以获得最佳性能
 */
static inline int math_abs(int x)
{
    return __builtin_abs(x);
}

/**
 * @brief 整数幂运算
 * @param base 底数
 * @param exp 指数（必须为非负整数）
 * @return base^exp 的结果
 */
u32 math_pow_u32(u32 base, u32 exp);

/**
 * @brief 整数平方根（牛顿迭代法）
 * @param x 输入值
 * @return sqrt(x) 的整数部分
 */
u32 math_sqrt_u32(u32 x);

/**
 * @brief 最大值
 * @param a 第一个值
 * @param b 第二个值
 * @return 较大的值
 */
#define MATH_MAX(a, b) MAX(a, b)

/**
 * @brief 最小值
 * @param a 第一个值
 * @param b 第二个值
 * @return 较小的值
 */
#define MATH_MIN(a, b) MIN(a, b)

/**
 * @brief 限制值在指定范围内
 * @param val 输入值
 * @param min 最小值
 * @param max 最大值
 * @return 限制后的值
 */
#define MATH_CLAMP(val, min, max) (((val) < (min)) ? (min) : (((val) > (max)) ? (max) : (val)))

/**
 * @brief 整数除法（向上取整）
 * @param dividend 被除数
 * @param divisor 除数
 * @return 向上取整的结果
 */
static inline u32 math_div_ceil(u32 dividend, u32 divisor)
{
    return (dividend + divisor - 1) / divisor;
}

/**
 * @brief 线性插值
 * @param x0 起始位置
 * @param y0 起始值
 * @param x1 结束位置
 * @param y1 结束值
 * @param x 当前位置
 * @return 插值结果
 */
s32 math_lerp(s32 x0, s32 y0, s32 x1, s32 y1, s32 x);

/**
 * @brief 将值从一个范围映射到另一个范围
 * @param val 输入值
 * @param in_min 输入范围最小值
 * @param in_max 输入范围最大值
 * @param out_min 输出范围最小值
 * @param out_max 输出范围最大值
 * @return 映射后的值
 */
s32 math_map(s32 val, s32 in_min, s32 in_max, s32 out_min, s32 out_max);

/**
 * @brief 快速整数平方
 * @param x 输入值
 * @return x * x
 */
static inline u32 math_square(u32 x)
{
    return x * x;
}

/**
 * @brief 计算两点之间的距离（整数近似）
 * @param x1 第一个点的x坐标
 * @param y1 第一个点的y坐标
 * @param x2 第二个点的x坐标
 * @param y2 第二个点的y坐标
 * @return 距离的整数近似值
 */
u32 math_distance(s32 x1, s32 y1, s32 x2, s32 y2);

/**
 * @brief 位计数（计算二进制中1的个数）
 * @param x 输入值
 * @return 二进制中1的个数
 */
static inline u32 math_popcount(u32 x)
{
    return __builtin_popcount(x);
}

/**
 * @brief 前导零计数
 * @param x 输入值
 * @return 前导零的个数
 */
static inline u32 math_clz(u32 x)
{
    return (x == 0) ? 32 : __builtin_clz(x);
}

/**
 * @brief 计算以2为底的对数（向下取整）
 * @param x 输入值（必须大于0）
 * @return log2(x) 的整数部分
 */
static inline u32 math_log2(u32 x)
{
    return (x == 0) ? 0 : (31 - __builtin_clz(x));
}

/**
 * @brief 判断是否为2的幂
 * @param x 输入值
 * @return 1表示是2的幂，0表示不是
 */
static inline u8 math_is_power_of_2(u32 x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}

/**
 * @brief 向上取整到2的幂
 * @param x 输入值
 * @return 大于等于x的最小2的幂
 */
u32 math_round_up_pow2(u32 x);

/**
 * @brief 简单的伪随机数生成器（线性同余法）
 * @param seed 种子指针
 * @return 随机数
 */
u32 math_rand(u32 *seed);

/**
 * @brief 生成指定范围内的随机数
 * @param seed 种子指针
 * @param min 最小值
 * @param max 最大值
 * @return [min, max] 范围内的随机数
 */
u32 math_rand_range(u32 *seed, u32 min, u32 max);

#endif // _MATH_EXAMPLE_H_
