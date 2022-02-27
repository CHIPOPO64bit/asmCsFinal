#include "modulo.h"


/**
 * Global variables. Makes the code much more efficient in this case.
 * Since it is converted to asm, there are only advantages.
 */

// TODO: assume pointers in add are distinct, and copy outside scope - much
//  more efficient, and cut the run time.

/**
 * init number
 * @param _ptr number pointer
 * @Complexity O(log(n))
 */
void Init(Number *_ptr) {
  for (int i = 0; i < _DEFAULT_SIZE; ++i) {
	_ptr->_ptr[i] = 0;
  }
  _ptr->_length = 0;
}



/**
 * prints _ptr
 * @param _ptr number pointer
 * @Complexity O(log(n))
 */
void _print_number(const Number *_ptr) {
  for (int i = _ptr->_length - 1; i >= 0; --i) {
	printf("%d, ", _ptr->_ptr[i]);
  }
  printf("\n");
}

/**
 * @return max(a,b)
 */
int _max(int a, int b) {
  if (a > b) {
	return a;
  }
  return b;
}

/**
 * @return min(a,b)
 */
int _min(int a, int b) {
  if (a > b) {
	return b;
  }
  return a;
}

/**
 * addition of two Numbers
 * @param _byte_shift shift rhs <> bytes
 * @param _bit_shift shift rhs <> bits
 * @Complexity: O(log(n))
 */
void _add(const Number *_lhs, const Number *_rhs, Number *_res, int
_byte_shift, int _bit_shift) {

  Number _rhs_copied, _lhs_copied;
  // the pointers are not of type restrict
  _copy(&_rhs_copied, _rhs), _copy(&_lhs_copied, _lhs);
  Init(_res);
  // helper variables, unsigned for two's complement addition
  unsigned short carry = 0;
  unsigned short temp;
  int max_length = _min(_max(_lhs_copied._length, _rhs_copied._length +
							_byte_shift),
						_DEFAULT_SIZE);
  const uint8_t *ptr_l = _lhs_copied._ptr, *ptr_r = _rhs_copied._ptr;
  uint8_t *ptr_res = _res->_ptr;
  _res->_length = max_length;
  // add each digit
  for (int i = 0; i < max_length;
	   ++i) {
	// zero padded case
	if (i - _byte_shift < 0) {
	  temp = (short)ptr_l[i];
	} else {
	  // compute the addition result
	  temp = (unsigned short)((((unsigned short)ptr_l[i]) + (unsigned short)
		  (ptr_r[i - _byte_shift] << _bit_shift) + (unsigned short)carry));
	}
	ptr_res[i] = (uint8_t)temp;
	// the carry bits
	carry = (temp & (~_CARRY_MASK)) >> (_CARRY_MASK_LENGTH);
  }
  // use carry
  if (max_length < _DEFAULT_SIZE && carry) {

	ptr_res[max_length] = carry;
	_res->_length = max_length + 1;
  }
}

/**
 * computes -number
 * @param _ptr number
 * @param _res stores the result in _res
 * @Complexity O(log(n))
 */
void _neg(const Number *_ptr, Number *_res) {
  Number temp;
  _copy(&temp, _ptr);
  _res->_length = temp._length;
  // not
  for (unsigned int i = 0; i < _DEFAULT_SIZE; ++i) {
	_res->_ptr[i] = ~(temp._ptr[i]);
	if (_res->_ptr[i] != 0){
	  _res->_length = i+1;
	}
  }
  // add 1

  _add(&_one, _res, _res, 0, 0);
}

/**
 * subtraction _lhs - _rhs
 * @param _res stores the result in _res
 * @Complexity O(log(n))
 */
void _sub(const Number *_lhs, const Number *_rhs, Number *_res, int bytes,
		  int bits) {
  Number _copied;
  _copy(&_copied, _rhs);
  _neg(_rhs, &_copied);
  _add(_lhs, &_copied, _res, bytes, bits);
  _res->_length = 0;
  for (int i = 0; i < _DEFAULT_SIZE; ++i) {
	if (_res->_ptr[i] != 0) {
	  _res->_length = i + 1;
	}
  }
}

/**
 * copy _rhs into _lhs by value
 * @Complexity O(log(n))
 */
void _copy(Number *_lhs, const Number *_rhs) {
  _lhs->_length = _rhs->_length;
  for (unsigned int i = 0; i < _DEFAULT_SIZE; ++i) {
	_lhs->_ptr[i] = _rhs->_ptr[i];
  }
}

/**
 * @return _lhs > _rhs
 * @Complexity O(log(n))
 */
int gt(const Number *_lhs, const Number *_rhs) {
  // trivial cases
  if (_rhs->_length > _lhs->_length) {
	return 0;
  } else if (_rhs->_length < _lhs->_length) {
	return 1;
  }
  if (_rhs->_length == 0) {
	return 0;
  }
  // radix comparison
  for (int i = _rhs->_length - 1; i >= 0; --i) {
	if (_rhs->_ptr[i] < _lhs->_ptr[i]) {
	  return 1;
	} else if (_rhs->_ptr[i] > _lhs->_ptr[i]) {
	  return 0;
	}
  }
  return 0;
}

/**
 * @return _lhs >= _rhs
 * @Complexity O(log(n))
 */
int ge(const Number *_lhs, const Number *_rhs) {
  // trivial cases
  if (_rhs->_length > _lhs->_length) {
	return 0;
  } else if (_rhs->_length < _lhs->_length) {
	return 1;
  }
  if (_rhs->_length == 0) {
	return 1;
  }
  // radix comparison
  for (int i = _rhs->_length - 1; i >= 0; --i) {
	if (_rhs->_ptr[i] < _lhs->_ptr[i]) {
	  return 1;
	} else if (_rhs->_ptr[i] > _lhs->_ptr[i]) {
	  return 0;
	}
  }
  return 1;
}

/**
 * ==
 * @return 1 if equal 0 otherwise
 */
int eq(const Number *_lhs, const Number *_rhs) {
  if (_lhs->_length != _rhs->_length) {
	return 0;
  }
  for (int i = 0; i < _lhs->_length; ++i) {
	if (_lhs->_ptr[i] != _rhs->_ptr[i]) {
	  return 0;
	}
  }
  return 1;
}

/**
 * Division (integral) of two Numbers _lhs / _rhs
 * @Complexity: O(log^2(n))
 */
void _mult(const Number *_lhs, const Number *_rhs, Number *_res) {
  Number _lhs_copied, _rhs_copied;
  _copy(&_lhs_copied, _lhs), _copy(&_rhs_copied, _rhs), Init(_res);
  int mask;
  // scan the bits and add the shifted _rhs accordingly
  for (int i = 0; i < _lhs_copied._length; ++i) {
	mask = 1;
	// scan the bits
	for (int j = 0; j < _BASE_UNIT; ++j) {
	  if ((_lhs_copied._ptr[i] & mask) != 0) {
		_add(_res, &_rhs_copied, _res, i, j);
	  }
	  mask += mask;
	}
  }
}

/**
 * Helper method for divide, computes the quotient in _res
 * A greedy method.
 * @param _q_y helper variable
 * @param _res quotient
 * @Complexity O(log(n^2))
 */
void _div_helper(const Number *_lhs, const Number *_rhs, Number *restrict _q_y,
				 Number *_res) {

  if (gt(_rhs, _lhs)
	  || (((_rhs->_ptr[_DEFAULT_SIZE - 1]) & (1 << (_BASE_UNIT - 1)))
		  != 0)) {
	return;
  }
  // copy elements
  Number temp;
  _add(_rhs, _rhs, &temp, 0, 0);
  // compute _lhs / 2*_rhs
  _div_helper(_lhs, &temp, _q_y, _res);
  _add(_res, _res, _res, 0, 0);
  _add(_q_y, _rhs, &temp, 0, 0);
  if (ge(_lhs, &temp)) { // at least one more factor
	_add(_q_y, _rhs, _q_y, 0, 0);
	_add(_res, &_one, _res, 0, 0);
  }
}

int is_negative(const Number *_ptr) {
  return _ptr->_ptr[_DEFAULT_SIZE - 1] & (1 << (_CARRY_MASK_LENGTH - 1));
}

/**
 * long division of two Numbers _lhs / _rhs
 * @Complexity: O(log^2(n))
 */
void _div(const Number *_lhs, const Number *_rhs, Number *_res) {
  /**
   * find most significant bit of rhs and lhs.  find the distance from lhs
   * to rhs. if negative, return 0, otherwise return the distance. assume
   * both x and y positive integers
   */
  Number _q_y, _lhs_copied, _rhs_copied;
  Init(&_q_y), Init(_res);
  if (is_negative(_lhs)) {
	//printf("here again!! div lhs\n");
	_neg(_lhs, &_lhs_copied);
  } else {
	_copy(&_lhs_copied, _lhs);
  }
  if (is_negative(_rhs)) {
	//printf("here again!! div rhs\n");
	_neg(_rhs, &_rhs_copied);
  } else {
	_copy(&_rhs_copied, _rhs);
  }
  _div_helper(&_lhs_copied, &_rhs_copied, &_q_y, _res);
}

/**
 * Modulo of two numbers _lhs mod _rhs. stored in _res
 * @Complexity: O(log^2(n))
 */
void _modulo(const Number *_lhs, const Number *_rhs, Number *_res) {
  Number _q, _ml, _lhs_copied, _rhs_copied;
  Init(&_lhs_copied), Init(&_rhs_copied);
  int _lhs_negative = 0;
  if (is_negative(_lhs)) {
	//printf("here again!!!!!!!!!!!!\n");
	_neg(_lhs, &_lhs_copied);
	_lhs_negative = 1;
  } else {
	_copy(&_lhs_copied, _lhs);
  }
  if (is_negative(_rhs)) {
	fprintf(stderr, "Can't compute modulo with a negative base\n");
	exit(EXIT_FAILURE);
  } else {
	_copy(&_rhs_copied, _rhs);
  }
  Init(_res);
  _div(&_lhs_copied, &_rhs_copied, &_q);
  _mult(&_q, &_rhs_copied, &_ml);
  _sub(&_lhs_copied, &_ml, _res, 0, 0);
  if (_lhs_negative && _res->_length != 0){
	_sub(_rhs, _res, _res, 0, 0);
  }
}

/**
 * find the msb bit of an integer
 * @return the msb index
 * @Complexity O(log(n))
 */
int _find_msb(uint8_t a) {
  int mask = 1, msb = 0;
  for (int i = 0; i < _BASE_UNIT; ++i) {
	if ((a & mask) != 0) {
	  msb = i;
	}
	mask = mask + mask;
  }
  return msb;
}

/**
 * The modular exponentiation (_exp_base)**(_exp) mod _base. Stored in _res
 * @Comlexitiy O(log^3(n))
 */
void _modular_exp(const Number
				  *_exp_base, const Number *_exp, const Number *_base, Number
				  *_res) {
  _res->_ptr[0] = 1;
  _res->_length = 1;
  int msb, mask, bits;
  // scan each bit, greedily
  for (int i = _exp->_length - 1; i >= 0; --i) {
	msb = _find_msb(_exp->_ptr[i]);
	bits = _BASE_UNIT - 1;
	if (i == _exp->_length - 1) {
	  bits = msb;
	}
	mask = 1 << bits;
	for (int j = bits; j >= 0; --j) {
	  // compute _res**2


//	  printf("before mult res length: %d last byte: %d\n", _res->_length,
//			 _res->_ptr[_DEFAULT_SIZE-1]);
	  _mult(_res, _res, _res);
//	  if (is_negative(_res)){
//		printf("res length: %d last byte: %d\n", _res->_length,
//			   _res->_ptr[_DEFAULT_SIZE-1]);
//	  }
	  _modulo(_res, _base, _res);

	  // mult by _rhs if needed
	  if ((_exp->_ptr[i] & mask) != 0) {
		_mult(_exp_base, _res, _res);
//		if (is_negative(_res)){
//		  printf("res length: %d last byte: %d\n", _res->_length,
//				 _res->_ptr[_DEFAULT_SIZE-1]);
//		}
		_modulo(_res, _base, _res);

	  }
	  mask = mask >> 1;
	}
  }
}

/**
 * shift right
 * @param _ptr number to shift
 * @param _bits_shift 0-8
 * @Complexity: O(log(n))
 */
void _shift_right(const Number *_ptr, Number *_res, int _bytes_shift, int
_bits_shift) {
  short temp;
  unsigned int length = _ptr->_length;
  for (int i = 0; i < _ptr->_length - _bytes_shift; ++i) {
	temp = _ptr->_ptr[i + _bytes_shift];

	_res->_ptr[i] = (temp >> _bits_shift);

	if (i > 0) {
	  _res->_ptr[i - 1] = _res->_ptr[i - 1] | ((temp & ((1 << _bits_shift) -
		  1)) << (_BASE_UNIT - _bits_shift));
	}
	if (_res->_ptr[i] != 0) {
	  length = i;
	}
  }
  _res->_length = length + 1;

}

/**
 * Compose a number to the form (u*2^s) where u is odd
 * @param _ptr base
 * @param _u odd
 * @param _exp power
 * @Complexity O(log(n))
 */
void _compose(const Number *_ptr, Number *_u, Number *_exp, int *_pow) {
  int mask;
  int _res = 0, not_found = 1;
  for (int i = 0; (i < _ptr->_length) && not_found; ++i) {
	mask = 1;

	for (int j = 0; j < _BASE_UNIT; ++j) {
	  if ((_ptr->_ptr[i] & mask) != 0) {
		not_found = 0;
		break;
	  }

	  ++_res;
	  mask = mask + mask;
	}
  }
  int _start = _res / _BASE_UNIT, _sub_start = _res % _BASE_UNIT;
  _exp->_ptr[_start] = 1 << (_sub_start);
  _exp->_length = _start + 1;

  _shift_right(_ptr, _u, _start, _sub_start);

  *_pow = _start * _BASE_UNIT + _sub_start;
}

/**
 * Find s,t such that a*s+b*t=gcd(a,b), assume _a > _b
 * @Complexity O(log^3(n))
 */
void _extended_euclid(const Number *_a, const Number *_b, Number *_gcd, Number
*_s, Number *_t) {
  if (_b->_length == 0) {
	_copy(_gcd, _a);
	_s->_length = 1;
	_s->_ptr[0] = 1;
  } else {
	Number temp;
	_modulo(_a, _b, &temp);
	_extended_euclid(_b, &temp, _gcd, _s, _t);
	_div(_a, _b, &temp);
	_mult(_t, &temp, &temp);
	_sub(_s, &temp, &temp, 0, 0);
	_copy(_s, _t);
	_copy(_t, &temp);
  }
}

/**
 * Find the multiplicative inverse of _ptr mod _base
 * @param _prt number to find its inverse
 * @param _res result stored in _res
 * @param _base modulo base
 * @Complexity O(log^3(n))
 */
void _inverse(const Number *_ptr, const Number *_base, Number *_res) {
  Number t, _gcd;
  Init(&t);
  _extended_euclid(_ptr, _base, &_gcd, _res, &t);
  _modulo(_res, _base, _res);
}

/**
 * generate a random number in the range 1,...,_upper_bound - 1
 * @param _upper_bound range upper bound
 * @param _res the result is stored in _res
 */
void _random(const Number *_upper_bound, Number *_res) {
  Init(_res);
  for (int i = 0; i < _upper_bound->_length; ++i) {
	_res->_ptr[i] = rand();
	if (_res->_ptr[i] != 0) {
	  _res->_length = i + 1;
	}
  }
  _modulo(_res, _upper_bound, _res);
  if (_res->_length == 0) {
	_copy(_res, &_one);
  }
}
