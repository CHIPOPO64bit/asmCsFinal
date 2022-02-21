/**
 * This file is an interface for modular operations
 * Assume a number is represented as an array, with known amount of bits,
 * which is bounded by 1000, that is, no need for dynamic allocations
 */

#ifndef RSA__MODULO_H_
#define RSA__MODULO_H_

#include <stdint.h>
#define _DEFAULT_SIZE  1024

/**
 * Represents a big number, since we want to control the bits, each cell is
 * only one byte.
 */

typedef struct Number{
  uint8_t _ptr[_DEFAULT_SIZE];
  unsigned int _length;
}Number;

/**
 * init number
 * @param _ptr
 */
void _init(Number *_ptr);

/**
 * copy _rhs into _lhs by value
 * @param _lhs
 * @param _rhs
 */
void _copy(Number *_lhs, const Number *_rhs);

/**
 * addition of two Numbers
 * @param rhs
 * @param lhs
 * @param _byte_shift
 * @param _bit_shift
 * @Complexity: O(log(n))
 */
void _add( const Number *_lhs, const Number *_rhs, Number *_res, int
_byte_shift, int _bit_shift);

/**
 * Shift right, enlarges the number
 * @param _ptr
 * @param _amount
 * @param _res
 */
void _shift_right(const Number *_ptr, unsigned int _amount, Number *_res);

/**
 * Shift left, reduces the number
 * @param _ptr
 * @param _amount
 * @param _res
 */
void _shift_left(const Number *_ptr, unsigned int _amount, Number *_res);

/**
 * long multiplication of two Numbers
 * @param rhs
 * @param lhs
 * @Complexity: O(log^2(n))
 */
void _div( const Number *_lhs, const Number *_rhs, Number *_res);


/**
 * Division of two Numbers
 * @param rhs
 * @param lhs
 * @Complexity: O(log^2(n))
 */
void _mult(const Number *_lhs, const Number *_rhs, Number *_res);

/**
 * Modulo of two numbers
 * @param _lhs
 * @param _rhs
 * @param _res
 * @Complexity: O(log^2(n))
 */
void _modulo(const Number *_lhs, const Number *_rhs, Number *_res);

/**
 * The modular exponentiation (_exp_base)**(_exp) mod _base
 * @param _base
 * @param _exp
 * @param _exp_base
 * @param _res
 * @Comlexitiy O(log^3(n))
 */
void _modular_exp(const Number *_base, const Number *_exp, const Number
*_exp_base, Number
*_res);

/**
 * Compose a number to the form (u*2^s) where u is odd
 * @param _ptr
 * @param _u
 * @param _exp
 * @Complexity O(log(n))
 */
void _compose(const Number *_ptr, Number *_u, Number *_exp);

/**
 * Find s,t such that a*s+b*t=gcd(a,b)
 * @param _a
 * @param _b
 * @param _s
 * @param _t
 * @Complexity O(log^3(n))
 */
void _extended_euclid(const Number *_a, const Number *_b, Number *_s, Number
*_t);

/**
 * Find the multiplicative inverse of _ptr mod _base
 * @param _prt
 * @param _res
 * @param _base
 * @Complexity O(log^3(n))
 */
void _inverse(const Number *_ptr, const Number *_base, Number *_res);



#endif //RSA__MODULO_H_
