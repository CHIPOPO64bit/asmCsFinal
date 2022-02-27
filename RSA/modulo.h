/**
 * This file is an interface for modular operations
 * Assume a number is represented as an array, with known amount of bits,
 * which is bounded by 1000, that is, no need for dynamic allocations
 */

#ifndef RSA__MODULO_H_
#define RSA__MODULO_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _DEFAULT_SIZE  70
#define _CARRY_MASK 255
#define _CARRY_MASK_LENGTH 8
#define _BASE_UNIT 8

/**
 * Represents a big number, since we want to control the bits, each cell is
 * only one byte.
 */

typedef struct Number {
  uint8_t _ptr[_DEFAULT_SIZE];
  unsigned int _length;
} Number;

Number _one, _minus_one;

/**
 * init number
 * @param _ptr number pointer
 * @Complexity O(log(n))
 */
void Init(Number *_ptr);

/**
 *  init global variables
 */
void init_program();

/**
 * prints _ptr
 * @param _ptr number pointer
 * @Complexity O(log(n))
 */
void _print_number(const Number *_ptr);

/**
 * @return max(a,b)
 */
int _max(int a, int b);

/**
 * @return min(a,b)
 */
int _min(int a, int b);

/**
 * addition of two Numbers
 * @param _byte_shift shift rhs <> bytes
 * @param _bit_shift shift rhs <> bits
 * @Complexity: O(log(n))
 */
void _add(const Number *_lhs, const Number *_rhs, Number *_res, int
_byte_shift, int _bit_shift);

/**
 * computes -number
 * @param _ptr number
 * @param _res stores the result in _res
 * @Complexity O(log(n))
 */
void _neg(const Number *_ptr, Number *_res);

/**
 * subtraction _lhs - _rhs
 * @param _res stores the result in _res
 * @Complexity O(log(n))
 */
void _sub(const Number *_lhs, const Number *_rhs, Number *_res, int bytes,
		  int bits);

/**
 * copy _rhs into _lhs by value
 * @Complexity O(log(n))
 */
void _copy(Number *_lhs, const Number *_rhs);

/**
 * @return _lhs > _rhs
 * @Complexity O(log(n))
 */
int gt(const Number *_lhs, const Number *_rhs);

/**
 * @return _lhs >= _rhs
 * @Complexity O(log(n))
 */
int ge(const Number *_lhs, const Number *_rhs);

/**
 * ==
 * @return 1 if equal 0 otherwise
 */
int eq(const Number *_lhs, const Number *_rhs);

/**
 * Division (integral) of two Numbers _lhs / _rhs
 * @Complexity: O(log^2(n))
 */
void _mult(const Number *_lhs, const Number *_rhs, Number *restrict _res);

/**
 * helper method for divide, computes the quotient in _res
 * @param _q_y helper variable
 * @param _res quotient
 * @Complexity O(log(n^2))
 */
void _div_helper(const Number *_lhs, const Number *_rhs, Number *_q_y,
				 Number *_res);

/**
 * long division of two Numbers _lhs / _rhs
 * @Complexity: O(log^2(n))
 */
void _div(const Number *_lhs, const Number *_rhs, Number *_res);

/**
 * Modulo of two numbers _lhs mod _rhs. stored in _res
 * @Complexity: O(log^2(n))
 */
void _modulo(const Number *_lhs, const Number *_rhs, Number *_res);

/**
 * find the msb bit of an integer
 * @return the msb index
 * @Complexity O(log(n))
 */
int _find_msb(uint8_t a);

/**
 * The modular exponentiation (_exp_base)**(_exp) mod _base. Stored in _res
 * @Comlexitiy O(log^3(n))
 */
void _modular_exp(const Number *_exp_base, const Number *_exp, const Number
*_base, Number *_res);

/**
 * shift right
 * @param _ptr number to shift
 * @param _bits_shift 0-8
 * @Complexity: O(log(n))
 */
void _shift_right(const Number *_ptr, Number *_res, int _bytes_shift, int
_bits_shift);

/**
 * Compose a number to the form (u*2^s) where u is odd
 * @param _ptr base
 * @param _u odd
 * @param _exp power
 * @Complexity O(log(n))
 */
void _compose(const Number *_ptr, Number *_u, Number *_exp, int *_pow);

/**
 * Find s,t such that a*s+b*t=gcd(a,b), assume _a > _b
 * @Complexity O(log^3(n))
 */
void _extended_euclid(const Number *_a, const Number *_b, Number *_gcd, Number
*_s, Number *_t);

/**
 * Find the multiplicative inverse of _ptr mod _base
 * @param _prt number to find its inverse
 * @param _res result stored in _res
 * @param _base modulo base
 * @Complexity O(log^3(n))
 */
void _inverse(const Number *_ptr, const Number *_base, Number *_res);


/**
 * generate a random number in the range 1,...,_upper_bound - 1
 * @param _upper_bound range upper bound
 * @param _res the result is stored in _res
 */
void _random(const Number *_upper_bound, Number *_res);

#endif //RSA__MODULO_H_
