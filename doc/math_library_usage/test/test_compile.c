/**
 * @file test_compile.c
 * @brief Simple compilation test for math library
 * 
 * This is a standalone test that duplicates the math functions
 * to verify they compile correctly without SDK dependencies.
 */

// Minimal typedef.h simulation for standalone compilation test
typedef unsigned char   u8;
typedef char            s8;
typedef unsigned short  u16;
typedef signed short    s16;
typedef unsigned int    u32;
typedef signed int      s32;
typedef unsigned long long u64;
typedef signed long long s64;

#ifndef NULL
#define NULL    0
#endif

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

// ============================================================================
// Math function implementations (copied from math_example.c)
// ============================================================================

static inline int math_abs(int x) 
{ 
    return __builtin_abs(x); 
}

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

u32 math_sqrt_u32(u32 x)
{
    if (x == 0) {
        return 0;
    }
    
    u32 guess = x;
    u32 result = (guess + 1) / 2;
    
    while (result < guess) {
        guess = result;
        result = (guess + x / guess) / 2;
    }
    
    return guess;
}

s32 math_map(s32 val, s32 in_min, s32 in_max, s32 out_min, s32 out_max)
{
    if (in_max == in_min) {
        return out_min;
    }
    
    s64 result = (s64)out_min + ((s64)(val - in_min) * (s64)(out_max - out_min)) / (s64)(in_max - in_min);
    return (s32)result;
}

u32 math_distance(s32 x1, s32 y1, s32 x2, s32 y2)
{
    s32 dx = x2 - x1;
    s32 dy = y2 - y1;
    
    u32 dx_sq = (u32)(dx * dx);
    u32 dy_sq = (u32)(dy * dy);
    
    return math_sqrt_u32(dx_sq + dy_sq);
}

static inline u32 math_popcount(u32 x) 
{ 
    return __builtin_popcount(x); 
}

static inline u32 math_clz(u32 x) 
{ 
    return (x == 0) ? 32 : __builtin_clz(x); 
}

static inline u32 math_log2(u32 x) 
{ 
    return (x == 0) ? 0 : (31 - __builtin_clz(x)); 
}

static inline u8 math_is_power_of_2(u32 x) 
{ 
    return (x != 0) && ((x & (x - 1)) == 0); 
}

u32 math_round_up_pow2(u32 x)
{
    if (x == 0) {
        return 1;
    }
    
    if (math_is_power_of_2(x)) {
        return x;
    }
    
    return 1U << (32 - __builtin_clz(x));
}

// ============================================================================
// Test main
// ============================================================================

int main(void)
{
    u32 result;
    
    // Test power
    result = math_pow_u32(2, 10);
    if (result != 1024) return 1;
    
    // Test sqrt
    result = math_sqrt_u32(100);
    if (result != 10) return 1;
    
    // Test distance
    result = math_distance(0, 0, 3, 4);
    if (result != 5) return 1;
    
    // Test abs
    int abs_result = math_abs(-42);
    if (abs_result != 42) return 1;
    
    // Test mapping
    s32 map_result = math_map(50, 0, 100, 0, 255);
    if (map_result != 127) return 1;
    
    // Test is power of 2
    u8 is_pow2 = math_is_power_of_2(16);
    if (!is_pow2) return 1;
    
    // Test log2
    u32 log_result = math_log2(16);
    if (log_result != 4) return 1;
    
    // Test popcount
    u32 pop_result = math_popcount(0xFF);
    if (pop_result != 8) return 1;
    
    // Test clz
    u32 clz_result = math_clz(8);
    if (clz_result != 28) return 1;
    
    // Test round up pow2
    u32 round_result = math_round_up_pow2(100);
    if (round_result != 128) return 1;
    
    return 0; // All tests passed
}
