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
  _res->_length = max_length;
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
 *
 * @param _ptr
 * @param _res
 */
void _neg(const Number *_ptr, Number *_res){
  _res->_length  = _ptr->_length;
  for (unsigned int i = 0; i < _DEFAULT_SIZE; ++i){
	_res->_ptr[i] = ~(_ptr->_ptr[i]);
  }
  _res->_length = _DEFAULT_SIZE;
  Number _one;
  _init(&_one);
  _one._ptr[0] = 1;
  _one._length  = 1;
  _add(&_one, _res, _res, 0 ,0);
}

/**
 *
 * @param _lhs
 * @param _rhs
 * @param _res
 */
void _sub(const Number *_lhs, const Number *_rhs, Number *_res, int bytes,
		  int bits){
  Number _copied;
  _copy(&_copied, _rhs);
  _neg(_rhs, &_copied);
  _add(_lhs, &_copied, _res, bytes, bits);
  _res->_length  = 0;
  for (int i = 0; i < _DEFAULT_SIZE; ++i){
	if (_res->_ptr[i] != 0){
	  _res->_length = i+1;
	}
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
 *
 * @param _lhs
 * @param _rhs
 * @return _lhs > _rhs
 */
int gt(const Number *_lhs, const Number *_rhs){

  //printf("length lhs: %d length rhs: %d\n", _lhs->_length,_rhs->_length);
  if (_rhs->_length > _lhs->_length){
	return 0;
  } else if (_rhs->_length < _lhs->_length){
	return 1;
  }
  if (_rhs->_length == 0){
	return 0;
  }

  for (int i = _rhs->_length-1; i >= 0; --i){
	//printf("before sigsegv %d\n", i);
	if (_rhs->_ptr[i] < _lhs->_ptr[i]){
	  return 1;
	} else if (_rhs->_ptr[i] > _lhs->_ptr[i]){
	  return 0;
	}
  }
  return 0;
}

/**
 * _lhs >= _rhs
 * @param _lhs
 * @param _rhs
 * @return
 */
int ge(const Number *_lhs, const Number *_rhs){
  if (_rhs->_length > _lhs->_length){
	return 0;
  } else if (_rhs->_length < _lhs->_length){
	return 1;
  }
  if (_rhs->_length  == 0){
	return 1;
  }
  for (int i = _rhs->_length-1; i >= 0; --i){
	if (_rhs->_ptr[i] < _lhs->_ptr[i]){
	  return 1;
	} else if (_rhs->_ptr[i] > _lhs->_ptr[i]){
	  return 0;
	}
  }
  return 1;
}

///**
// * Shift right, enlarges the number
// * @param _ptr
// * @param _amount
// * @param _res
// */
//void _shift_right(const Number *_ptr, unsigned int _amount, Number *_res){
//
//}
//
///**
// *
// * @param _ptr
// * @param _bytes
// * @param _bits
// * @param _res
// */
//void _shift_left(const Number *_ptr, unsigned int _bytes, unsigned int _bits,
//				 Number *_res){
//  short temp;
//  for (int i = (int)_ptr->_length - 1; i >= 0; --i){
//	temp = (short)(((short)_ptr->_ptr[i])<<_bits);
//	_res->_ptr[i+_bytes] = (uint8_t) temp;
//	if (i+_bytes+1 < _DEFAULT_SIZE){
//	  _res->_ptr[i+_bytes+1] =   _res->_ptr[i+_bytes+1]  | (temp &
//		  (~_CARRY_MASK)) << _CARRY_MASK_LENGTH;
//	}
//
//  }
//
//}

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

///**
// *
// * @param _ptr
// * @return
// */
//int _find_msb(const Number *_ptr){
//  if (_ptr->_length == 0){
//	return 0;
//  }
//  int offset = 0, mask = 1;
//  for (int i = 0; i < _BASE_UNIT; ++i){
//	if ((mask & _ptr->_ptr[_ptr-> _length - 1]) != 0){
//	  offset = i;
//	}
//	mask = mask + mask;
//  }
//  return _BASE_UNIT*(_ptr->_length - 1) + offset;
//}
// A A A A
// B B B B B B B
///**
// *
// * @param _lhs
// * @param _rhs
// * @return
// */
//int _find_distance(const Number *_lhs, const Number *_rhs){
//  int power_lhs = _find_msb(_lhs);
//  int power_rhs = _find_msb(_rhs);
//  return power_lhs - power_rhs;
//}
//

void _div_helper(const Number *_lhs, const Number *_rhs, Number *_q_y,
				 Number *_res){

  if (gt(_rhs, _lhs) || (((_rhs->_ptr[_DEFAULT_SIZE-1]) & (1<<(_BASE_UNIT-1)))
  != 0)){

	return;
  }

  Number _r_temp, _comp, _one;
  _init(&_r_temp);
  _init(&_comp);
  _init(&_one);
  _add(_rhs, _rhs, &_r_temp, 0, 0);
  _div_helper(_lhs, &_r_temp, _q_y, _res);
  _add(_res, _res, _res,  0 , 0);
  _add(_q_y, _rhs, &_comp, 0, 0);
  if (ge(_lhs, &_comp)){ // at least one more factor

	_add(_q_y, _rhs, _q_y, 0, 0);
	_one._ptr[0] = 1;
	_one._length = 1;
	_add(_res, &_one, _res, 0, 0);

  }


}
/**
 * long division of two Numbers _lhs / _rhs
 * @param rhs
 * @param lhs
 * @Complexity: O(log^2(n))
 */
void _div(const Number *_lhs, const Number *_rhs, Number *_res){
  /**
   * find most significant bit of rhs and lhs.  find the distance from lhs
   * to rhs. if negative, return 0, otherwise return the distance. assume
   * both x and y positive integers
   */
   Number _q_y;
   _init(&_q_y);
   _div_helper(_lhs, _rhs, &_q_y, _res);
}

/**
 * Modulo of two numbers
 * @param _lhs
 * @param _rhs
 * @param _res
 * @Complexity: O(log^2(n))
 */
void _modulo(const Number *_lhs, const Number *_rhs, Number *_res){
  Number _q, _ml;
  _init(&_q), _init(&_ml);
  _div(_lhs, _rhs, &_q);
  _mult(&_q, _rhs, &_ml);
  _sub(_lhs, &_ml, _res, 0 ,0);
}

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


