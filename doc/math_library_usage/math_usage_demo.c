/**
 * @file math_usage_demo.c
 * @brief AW31N SDK数学库使用示例和测试
 * 
 * 本文件演示如何在AW31N SDK中进行数学运算
 * 包含各种常用数学函数的使用示例
 * 
 * @author AW31N SDK Example
 * @date 2025-01-29
 */

#include "math_example.h"
#include "printf.h"

/**
 * @brief 测试基本算术运算
 */
void test_basic_math(void)
{
    printf("=== 基本算术运算测试 ===\n");
    
    // 测试绝对值
    printf("abs(-42) = %d\n", math_abs(-42));
    printf("abs(42) = %d\n", math_abs(42));
    
    // 测试最大最小值
    printf("max(10, 20) = %d\n", MATH_MAX(10, 20));
    printf("min(10, 20) = %d\n", MATH_MIN(10, 20));
    
    // 测试限制值
    printf("clamp(5, 10, 20) = %d\n", MATH_CLAMP(5, 10, 20));
    printf("clamp(15, 10, 20) = %d\n", MATH_CLAMP(15, 10, 20));
    printf("clamp(25, 10, 20) = %d\n", MATH_CLAMP(25, 10, 20));
    
    printf("\n");
}

/**
 * @brief 测试幂运算和平方根
 */
void test_power_and_sqrt(void)
{
    printf("=== 幂运算和平方根测试 ===\n");
    
    // 测试幂运算
    printf("pow(2, 0) = %u\n", math_pow_u32(2, 0));
    printf("pow(2, 5) = %u\n", math_pow_u32(2, 5));
    printf("pow(2, 10) = %u\n", math_pow_u32(2, 10));
    printf("pow(3, 4) = %u\n", math_pow_u32(3, 4));
    printf("pow(10, 3) = %u\n", math_pow_u32(10, 3));
    
    // 测试平方
    printf("square(5) = %u\n", math_square(5));
    printf("square(16) = %u\n", math_square(16));
    
    // 测试平方根
    printf("sqrt(0) = %u\n", math_sqrt_u32(0));
    printf("sqrt(1) = %u\n", math_sqrt_u32(1));
    printf("sqrt(4) = %u\n", math_sqrt_u32(4));
    printf("sqrt(16) = %u\n", math_sqrt_u32(16));
    printf("sqrt(100) = %u\n", math_sqrt_u32(100));
    printf("sqrt(255) = %u\n", math_sqrt_u32(255));
    printf("sqrt(1000) = %u\n", math_sqrt_u32(1000));
    
    printf("\n");
}

/**
 * @brief 测试位运算相关函数
 */
void test_bit_operations(void)
{
    printf("=== 位运算测试 ===\n");
    
    // 测试popcount
    printf("popcount(0) = %u\n", math_popcount(0));
    printf("popcount(1) = %u\n", math_popcount(1));
    printf("popcount(7) = %u (0b111)\n", math_popcount(7));
    printf("popcount(15) = %u (0b1111)\n", math_popcount(15));
    printf("popcount(0xFF) = %u\n", math_popcount(0xFF));
    
    // 测试前导零计数
    printf("clz(1) = %u\n", math_clz(1));
    printf("clz(2) = %u\n", math_clz(2));
    printf("clz(8) = %u\n", math_clz(8));
    printf("clz(0x80000000) = %u\n", math_clz(0x80000000));
    
    // 测试log2
    printf("log2(1) = %u\n", math_log2(1));
    printf("log2(2) = %u\n", math_log2(2));
    printf("log2(8) = %u\n", math_log2(8));
    printf("log2(16) = %u\n", math_log2(16));
    printf("log2(1000) = %u\n", math_log2(1000));
    
    // 测试是否为2的幂
    printf("is_power_of_2(0) = %u\n", math_is_power_of_2(0));
    printf("is_power_of_2(1) = %u\n", math_is_power_of_2(1));
    printf("is_power_of_2(2) = %u\n", math_is_power_of_2(2));
    printf("is_power_of_2(3) = %u\n", math_is_power_of_2(3));
    printf("is_power_of_2(16) = %u\n", math_is_power_of_2(16));
    printf("is_power_of_2(17) = %u\n", math_is_power_of_2(17));
    
    // 测试向上取整到2的幂
    printf("round_up_pow2(0) = %u\n", math_round_up_pow2(0));
    printf("round_up_pow2(1) = %u\n", math_round_up_pow2(1));
    printf("round_up_pow2(5) = %u\n", math_round_up_pow2(5));
    printf("round_up_pow2(16) = %u\n", math_round_up_pow2(16));
    printf("round_up_pow2(17) = %u\n", math_round_up_pow2(17));
    printf("round_up_pow2(100) = %u\n", math_round_up_pow2(100));
    
    printf("\n");
}

/**
 * @brief 测试线性插值和映射
 */
void test_interpolation(void)
{
    printf("=== 插值和映射测试 ===\n");
    
    // 测试线性插值
    printf("lerp(0,0, 100,100, 0) = %d\n", math_lerp(0, 0, 100, 100, 0));
    printf("lerp(0,0, 100,100, 50) = %d\n", math_lerp(0, 0, 100, 100, 50));
    printf("lerp(0,0, 100,100, 100) = %d\n", math_lerp(0, 0, 100, 100, 100));
    
    // 测试范围映射
    // 将0-100映射到0-255
    printf("map(0, 0,100, 0,255) = %d\n", math_map(0, 0, 100, 0, 255));
    printf("map(50, 0,100, 0,255) = %d\n", math_map(50, 0, 100, 0, 255));
    printf("map(100, 0,100, 0,255) = %d\n", math_map(100, 0, 100, 0, 255));
    
    // 将0-1023映射到0-100（ADC转换百分比）
    printf("map(0, 0,1023, 0,100) = %d\n", math_map(0, 0, 1023, 0, 100));
    printf("map(512, 0,1023, 0,100) = %d\n", math_map(512, 0, 1023, 0, 100));
    printf("map(1023, 0,1023, 0,100) = %d\n", math_map(1023, 0, 1023, 0, 100));
    
    printf("\n");
}

/**
 * @brief 测试距离计算
 */
void test_distance(void)
{
    printf("=== 距离计算测试 ===\n");
    
    // 测试两点间距离
    printf("distance(0,0, 0,0) = %u\n", math_distance(0, 0, 0, 0));
    printf("distance(0,0, 3,4) = %u (应为5)\n", math_distance(0, 0, 3, 4));
    printf("distance(0,0, 5,12) = %u (应为13)\n", math_distance(0, 0, 5, 12));
    printf("distance(1,1, 4,5) = %u (应为5)\n", math_distance(1, 1, 4, 5));
    printf("distance(-10,-10, 10,10) = %u\n", math_distance(-10, -10, 10, 10));
    
    printf("\n");
}

/**
 * @brief 测试随机数生成
 */
void test_random(void)
{
    printf("=== 随机数生成测试 ===\n");
    
    u32 seed = 12345; // 初始种子
    
    printf("生成10个随机数:\n");
    for (int i = 0; i < 10; i++) {
        printf("%u ", math_rand(&seed));
    }
    printf("\n");
    
    printf("\n生成10个0-100范围内的随机数:\n");
    seed = 67890; // 重新设置种子
    for (int i = 0; i < 10; i++) {
        printf("%u ", math_rand_range(&seed, 0, 100));
    }
    printf("\n");
    
    printf("\n");
}

/**
 * @brief 测试除法向上取整
 */
void test_division(void)
{
    printf("=== 除法运算测试 ===\n");
    
    printf("div_ceil(10, 3) = %u (应为4)\n", math_div_ceil(10, 3));
    printf("div_ceil(9, 3) = %u (应为3)\n", math_div_ceil(9, 3));
    printf("div_ceil(100, 7) = %u (应为15)\n", math_div_ceil(100, 7));
    printf("div_ceil(1, 1) = %u (应为1)\n", math_div_ceil(1, 1));
    
    printf("\n");
}

/**
 * @brief 实际应用示例：ADC值处理
 */
void example_adc_processing(void)
{
    printf("=== 实际应用示例：ADC值处理 ===\n");
    
    // 假设ADC读取到的原始值
    u32 adc_raw_value = 768;  // 0-1023范围
    
    // 转换为百分比（0-100）
    s32 percentage = math_map(adc_raw_value, 0, 1023, 0, 100);
    printf("ADC原始值: %u -> 百分比: %d%%\n", adc_raw_value, percentage);
    
    // 转换为电压（假设参考电压3.3V，转换为mV）
    s32 voltage_mv = math_map(adc_raw_value, 0, 1023, 0, 3300);
    printf("ADC原始值: %u -> 电压: %d mV\n", adc_raw_value, voltage_mv);
    
    printf("\n");
}

/**
 * @brief 实际应用示例：传感器位置检测
 */
void example_sensor_position(void)
{
    printf("=== 实际应用示例：传感器位置检测 ===\n");
    
    // 假设检测到两个连续的传感器位置
    s32 x1 = 100, y1 = 200;
    s32 x2 = 103, y2 = 204;
    
    // 计算移动距离
    u32 distance = math_distance(x1, y1, x2, y2);
    printf("从位置(%d,%d)移动到(%d,%d)\n", x1, y1, x2, y2);
    printf("移动距离: %u\n", distance);
    
    // 判断移动是否超过阈值
    u32 threshold = 5;
    if (distance > threshold) {
        printf("移动距离超过阈值%u，触发事件\n", threshold);
    } else {
        printf("移动距离未超过阈值%u\n", threshold);
    }
    
    printf("\n");
}

/**
 * @brief 实际应用示例：内存对齐计算
 */
void example_memory_alignment(void)
{
    printf("=== 实际应用示例：内存对齐 ===\n");
    
    // 将内存大小向上对齐到2的幂
    u32 sizes[] = {17, 33, 100, 256, 1000};
    
    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        u32 original = sizes[i];
        u32 aligned = math_round_up_pow2(original);
        printf("原始大小: %4u -> 对齐后: %4u\n", original, aligned);
    }
    
    printf("\n");
}

/**
 * @brief 主测试函数
 */
void math_library_demo(void)
{
    printf("\n");
    printf("========================================\n");
    printf("   AW31N SDK 数学库使用示例\n");
    printf("========================================\n");
    printf("\n");
    
    // 运行所有测试
    test_basic_math();
    test_power_and_sqrt();
    test_bit_operations();
    test_interpolation();
    test_distance();
    test_random();
    test_division();
    
    printf("========================================\n");
    printf("   实际应用示例\n");
    printf("========================================\n");
    printf("\n");
    
    example_adc_processing();
    example_sensor_position();
    example_memory_alignment();
    
    printf("========================================\n");
    printf("   测试完成\n");
    printf("========================================\n");
    printf("\n");
}
