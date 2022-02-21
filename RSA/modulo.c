#include "modulo.h"
#include <stdlib.h>
#include <stdio.h>
#define _CARRY_MASK 255
#define _CARRY_MASK_LENGTH 8
#define _BASE_UNIT 8

/**
 * TODO: MULT is implemented!!!
 * need: div, shift right, left, modulo(trivial) and so on...
 */

/**
 * init number
 * @param _ptr
 */
void _init(Number *_ptr) {
  for (int i = 0; i < _DEFAULT_SIZE; ++i) {
	_ptr->_ptr[i] = 0;
  }
  _ptr->_length = 0;
}

/**
 * max
 * @param a
 * @param b
 * @return
 */
int _max(int a, int b) {
  if (a > b) {
	return a;
  }
  return b;
}

/**
 * min
 * @param a
 * @param b
 * @return
 */
int _min(int a, int b) {
  if (a > b) {
	return b;
  }
  return a;
}

/**
 * addition of two Numbers
 * @param rhs
 * @param lhs
 * @Complexity: O(log(n))
 */
void _add(const Number *_lhs, const Number *_rhs, Number *_res, int
_byte_shift, int _bit_shift) {
  //printf("bit shift %d\n", _bit_shift);
  int carry = 0;
  short temp;
  int max_length = _max(_lhs->_length, _rhs->_length + _byte_shift);
  const uint8_t *ptr_l = _lhs->_ptr, *ptr_r = _rhs->_ptr;
  uint8_t *ptr_res = _res->_ptr;
  for (int i = 0; i < max_length && (i + _byte_shift < _DEFAULT_SIZE);
	   ++i) {
	if (i - _byte_shift < 0) {
	  temp = (short)ptr_l[i];
	} else {
	  //printf("I: %d byte_shift: %d\n", i, i-_byte_shift);
	  temp = (short)((((short)ptr_l[i]) +(short)
		  (ptr_r[i-_byte_shift] << _bit_shift) +(short) carry));
	}
	//printf("temp %d %d\n", temp, (uint8_t) temp);
	ptr_res[i] = (uint8_t)temp;
	carry = (temp & (~_CARRY_MASK)) >> (_CARRY_MASK_LENGTH);
  }
  if (max_length < _DEFAULT_SIZE && carry) {
	ptr_res[max_length] = carry;
	_res->_length = max_length + 1;
  }
}

/**
 * copy _rhs into _lhs by value
 * @param _lhs
 * @param _rhs
 */
void _copy(Number *_lhs, const Number *_rhs) {
  _lhs->_length = _rhs->_length;
  for (unsigned int i = 0; i < _DEFAULT_SIZE; ++i) {
	_lhs->_ptr[i] = _rhs->_ptr[i];
  }
}

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
 * Division of two Numbers
 * @param rhs
 * @param lhs
 * @Complexity: O(log^2(n))
 */
void _mult(const Number *_lhs, const Number *_rhs, Number *_res) {
  int mask;
  for (int i = 0; i < _lhs->_length; ++i) {
	mask = 1;
	for (int j = 0; j < _BASE_UNIT; ++j) {
	  if ((_lhs->_ptr[i] & mask) != 0) {
		//printf("mask %d\n", mask);
		_add(_res, _rhs, _res, i, j);
	  }
	  mask += mask;
	}
  }
}

/**
 * long multiplication of two Numbers
 * @param rhs
 * @param lhs
 * @Complexity: O(log^2(n))
 */
void _div(const Number *_lhs, const Number *_rhs, Number *_res);

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


