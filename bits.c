/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

/*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x | ~y);
    return 2;
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    // return ~(~(~x&y)&~(~y&x));
    return ~(x & y) & ~(~x & ~y);
    return 2;
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    if ((!x) && (!y)) {
        return 1;
    } else {
        if (!((!x) ^ (!y))) {
            return !((x >> 31) ^ (y >> 31));
        }
    }
    return 0;
    return 2;
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int shift = (v > 0xffff) << 4;
    int res;
    v = v >> shift;
    res = shift;
    shift = (v > 0xff) << 3;
    v = v >> shift;
    res = res | shift;
    shift = (v > 0xf) << 2;
    v = v >> shift;
    res = res | shift;
    shift = (v > 0x3) << 1;
    v = v >> shift;
    res = res | shift;
    shift = (v > 0x1);
    v = v >> shift;
    res = res | shift;
    return res;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    n = n << 3;
    m = m << 3;
    return ((x & (~(0xff << n)) & (~(0xff << m))) | (((x >> n) & 0xff) << m) | (((x >> m) & 0xff) << n));
    return 2;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    unsigned res = 0;
    for (int i = 0; 16 - i; i = i + 1) {
        res = res | (((v >> i) & 1) << (31 - i)) | (((v >> (31 - i)) & 1) << (i));
    }
    return res;
    return 2;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    return (x >> n) & ~(((1 << 31) >> n) << 1);
    return 2;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int shift = 0;
    int res = 0;
    shift = (!((~x) >> 16)) << 4;
    x = x << shift;
    res = shift;
    shift = (!((~x) >> 24)) << 3;
    x = x << shift;
    res = res | shift;
    shift = (!((~x) >> 28)) << 2;
    x = x << shift;
    res = res | shift;
    shift = (!((~x) >> 30)) << 1;
    x = x << shift;
    res = res | shift;
    res = res + !((~x) >> 31) + (!((~x) >> 31) & !(((~x) >> 30) & 1));
    return res;
    return 2;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned sign = x & 0x80000000;
    unsigned a = x;
    if (x == 0) {
        return 0;
    } else if (x < 0) {
        a = -a;
    }
    int k = 0;
    while ((a >> k) > 1) {
        k = k + 1;
    }
    unsigned exp = k + 127;
    unsigned frac;
    if (k < 24) {
        frac = (a << (23 - k)) & 0x7fffff;
    } else {
        int shift = k - 23;
        frac = a >> shift;
        unsigned tail = a - (frac << shift);
        unsigned half = 1 << (shift - 1);
        if ((tail > half) | ((tail == half) & (frac & 1))) {
            frac = frac + 1;
        }
        if (frac >> 24) {
            exp = exp + 1;
        }
        frac = frac & 0x7fffff;
    }
    return sign | (exp << 23) | frac;
    return 2;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned sign = uf & 0x80000000;
    unsigned exp = uf & 0x7f800000;
    unsigned frac = uf & 0x007fffff;
    if (uf == 0) {
        return uf;
    } else if (exp == 0) {
        return sign | exp | (frac << 1);
    } else {
        unsigned a = ((0xff) << 23);
        unsigned b = ((0xfe) << 23);
        if (exp == a) {
            return uf;
        } else if (exp == b) {
            return sign | a;
        }
        exp = exp + 0x00800000;
        return sign | exp | frac;
    }
    return 2;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned exp = (uf2 >> 20) & 0x7ff;
    int a = uf2 >> 31;
    if (!exp) {
        return 0;
    } else {
        int e = exp - 1023;
        if (e < 0) {
            return 0;
        }
        if (e >= 31) {
            return 0x80000000;
        }
        unsigned fract1 = uf2 & 0xfffff;
        if (e > 20) {
            int newe = e - 20;
            if (a)
                return -(((1 << e) | (fract1 << newe)) | (uf1 >> (32 - newe)));
            else
                return ((1 << e) | (fract1 << newe)) | (uf1 >> (32 - newe));
        } else {
            if (a)
                return -((1 << e) | (fract1 >> (20 - e)));
            else
                return (1 << e) | (fract1 >> (20 - e));
        }
    }
    return 2;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    unsigned sign = 0;
    unsigned exp = 0;
    unsigned frac = 0;
    if (x > 127) {
        return 0x7f800000;
    } else if (x < -149) {
        return 0;
    } else if (x > -127 && x <= 127) {
        exp = (x + 127) << 23;
        return sign | exp | frac;
    } else if (x <= -127 && x >= -149) {
        int tmp = x - (-149);
        frac = (1u << tmp);
        return sign | exp | frac;
    }
    return 2;
}
