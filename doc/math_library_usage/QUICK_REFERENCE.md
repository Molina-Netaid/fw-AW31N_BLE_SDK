# AW31N SDK 数学库使用速查表 / Quick Reference

## 核心要点 / Key Points

✅ **本SDK不使用标准 math.h**  
✅ **This SDK does not use standard math.h**

✅ **所有运算都是整数运算**  
✅ **All operations are integer-based**

✅ **使用编译器内建函数获得最佳性能**  
✅ **Use compiler built-ins for best performance**

---

## 快速函数列表 / Quick Function List

### 基本运算 / Basic Operations
```c
math_abs(x)                    // 绝对值 / Absolute value
MATH_MAX(a, b)                 // 最大值 / Maximum
MATH_MIN(a, b)                 // 最小值 / Minimum
MATH_CLAMP(val, min, max)      // 限制范围 / Clamp to range
```

### 幂和根 / Power & Root
```c
math_pow_u32(base, exp)        // base^exp
math_square(x)                 // x * x
math_sqrt_u32(x)               // sqrt(x) 整数部分 / integer part
```

### 位运算 / Bit Operations
```c
math_popcount(x)               // 统计1的个数 / Count 1s
math_clz(x)                    // 前导零 / Leading zeros
math_log2(x)                   // log₂(x)
math_is_power_of_2(x)          // 是否2的幂 / Is power of 2
math_round_up_pow2(x)          // 向上取整到2的幂 / Round up to power of 2
```

### 映射和插值 / Mapping & Interpolation
```c
math_map(val, in_min, in_max, out_min, out_max)  // 范围映射 / Range mapping
math_lerp(x0, y0, x1, y1, x)                     // 线性插值 / Linear interpolation
```

### 几何 / Geometry
```c
math_distance(x1, y1, x2, y2)  // 两点距离 / Distance between points
```

### 随机数 / Random
```c
math_rand(&seed)               // 生成随机数 / Generate random number
math_rand_range(&seed, min, max) // 范围内随机数 / Random in range
```

---

## 典型应用场景 / Typical Use Cases

### 1. ADC转换 / ADC Conversion
```c
u32 adc = read_adc();
s32 percent = math_map(adc, 0, 1023, 0, 100);  // 转百分比 / To percentage
s32 voltage = math_map(adc, 0, 1023, 0, 3300); // 转毫伏 / To millivolts
```

### 2. 传感器检测 / Sensor Detection
```c
u32 dist = math_distance(old_x, old_y, new_x, new_y);
if (dist > THRESHOLD) {
    trigger_event();
}
```

### 3. 内存对齐 / Memory Alignment
```c
u32 aligned_size = math_round_up_pow2(buffer_size);
```

### 4. 位操作 / Bit Operations
```c
if (math_is_power_of_2(size)) {
    use_fast_path();
}
u32 bits_set = math_popcount(flags);
```

---

## 编译器内建函数 / Compiler Built-ins

```c
__builtin_abs(x)        // 绝对值 / Absolute
__builtin_popcount(x)   // 位计数 / Bit count
__builtin_clz(x)        // 前导零 / Leading zeros
```

---

## 性能提示 / Performance Tips

✅ 使用inline函数（简单运算）  
✅ Use inline functions (simple ops)

✅ 使用位移代替乘除法（如 x<<1 代替 x*2）  
✅ Use bit shifts instead of multiply/divide (e.g., x<<1 instead of x*2)

✅ 避免浮点运算  
✅ Avoid floating-point operations

✅ 注意溢出问题  
✅ Watch for overflow

---

## 文件说明 / File Description

| 文件 / File | 说明 / Description |
|-------------|-------------------|
| `math_example.h` | 函数声明 / Function declarations |
| `math_example.c` | 函数实现 / Implementations |
| `math_usage_demo.c` | 使用示例 / Usage examples |
| `README.md` | 完整文档 / Full documentation |
| `test/test_compile.c` | 编译测试 / Compilation test |

---

## 测试 / Testing

```bash
cd doc/math_library_usage/test
gcc -Wall -Wextra -O2 -o test_compile test_compile.c
./test_compile
# 输出 / Output: All tests passed!
```

---

## 联系方式 / Contact

技术交流群 / Technical Support: 钉钉群 ID: 90400000565

文档链接 / Documentation: https://doc.zh-jieli.com/AW31/

---

**最后更新 / Last Updated**: 2025-01-29
