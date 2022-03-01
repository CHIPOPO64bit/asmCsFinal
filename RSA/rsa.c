//
// Created by David Keisar on 2/26/22.
//
#include "rsa.h"
#define _PRIME_SIZE 64
#define _CO_PRIME_SIZE 3

const uint8_t co_prime_e[] = {1, 0, 1};
const uint8_t _d[] = {17, 197, 180, 138, 14, 253, 219, 223, 135, 224, 22, 178, 3, 191, 210, 84, 59, 234, 187, 135, 160, 217, 255, 65, 227, 244, 96, 112, 80, 235, 59, 65};
/**
 *  init global variables
 */
void init_program() {
  Init(&_one);
  _one._ptr[0] = 1;
  _one._length = 1;
  _neg(&_one, &_minus_one);
  srand(time(NULL));
  for (int i = 0; i < _CO_PRIME_SIZE; ++i){
	e._ptr[i] = co_prime_e[i];
  }
  e._length = _CO_PRIME_SIZE;
  for (int i = 0; i < 32; ++i){
	d._ptr[i] = _d[31-i];
  }
  d._length = 32;
}

/**
 *
 * @param _ptr
 * @param _base
 * @return
 */
int _witness(const Number *_ptr, const Number *_base) {
  Number u, t, x0, cur, prev, _base_dec;
  int pow;
  Init(&u), Init(&t), Init(&x0), Init(&cur), Init(&prev), Init(&_base_dec);
  _sub(_base, &_one, &_base_dec, 0, 0);
  _compose(&_base_dec, &u, &t, &pow);
  _modular_exp(_ptr, &u, _base, &x0);
  _copy(&prev, &x0);
  _copy(&cur, &x0);

  for (int i = 1; i <= pow; ++i) {
	_copy(&prev, &cur);
	_mult(&cur, &cur, &cur);

	_modulo(&cur, _base, &cur);
	if (eq(&cur, &_one) && (!eq(&prev, &_one)) && (!eq(&prev, &_base_dec))) {
	  return 1;
	}
  }
  if (!eq(&cur, &_one)) {
	return 1;
  }
  return 0;

}

/**
 * Miller rabin algorithm
 * @param _ptr
 * @param _iter
 * @Complexity:
 * @return
 */
int _miller_rabin(const Number *_ptr, int _iter) {

  Number random;
  if (!_ptr->_length){
	printf("error\n");
	return 0;
  }
  for (int i = 0; i < _iter; ++i) {
	_random(_ptr, &random);
	if (_witness(&random, _ptr)) {
	  return 0;
	}



  }
  return 1;
}

/**
 * generate a random number
 * @param _res
 * @param size
 */
void _generate_random(Number *_res, int size){


  for (int i = 0; i < size; ++i){

	_res->_ptr[i] = rand();
	if (_res->_ptr[i] != 0){
	  _res->_length = i + 1;
	}
  }
  while (_res->_ptr[size-1] == 0){
	_res->_ptr[size-1] = rand();
  }
  while(_res->_ptr[0] %2 == 0){
	_res->_ptr[0] = rand();
  }
}

/**
 * generate a prime
 * @param _res
 * @param size
 */
void _generate_prime(Number *_res, int size){
  int i = 1;
  Number prime_dec, temp;
  while (1){
	_generate_random(_res, size);
	if (_miller_rabin(_res, 7)){
	  // make sure prime and e are co-prime
	  Init(&temp);
	  _sub(_res, &_one, &prime_dec, 0, 0);
	  _modulo(&prime_dec, &e, &temp);
	  if (temp._length != 0){
		return;
	  }
	}
	printf("again %d\n", i++);
  }
}

/**
 * Generate RSA keys
 * @param length
 * @param _N
 * @param _e
 * @param _d
 */
void _generate_keys(int length, Number *_N, Number *_e, Number *_d){
  Number p, q, res, p_dec, q_dec, phi_N;
  Init(&p), Init(&q), Init(&res);
  // generate p, q, N
  _generate_prime(&p, length);
  _generate_prime(&q, length);
  _mult(&p, &q, _N);
  _sub(&p, &_one, &p_dec, 0, 0);
  _sub(&q, &_one, &q_dec, 0, 0);
  _mult(&p_dec, &q_dec, &phi_N);
  // generate e,d
  _copy(_e, &e);
  _inverse(_e, &phi_N, _d);
}
