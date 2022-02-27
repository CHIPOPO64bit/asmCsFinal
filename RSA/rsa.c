//
// Created by David Keisar on 2/26/22.
//
#include "rsa.h"
#define _PRIME_SIZE 64
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
  //printf("n-1\n");
 // _print_number(&_base_dec);
  _compose(&_base_dec, &u, &t, &pow);
  _modular_exp(_ptr, &u, _base, &x0);
  _copy(&prev, &x0);
  _copy(&cur, &x0);

  for (int i = 1; i <= pow; ++i) {
	_copy(&prev, &cur);
	_mult(&cur, &cur, &cur);

	_modulo(&cur, _base, &cur);
	if (eq(&cur, &_one) && (!eq(&prev, &_one)) && (!eq(&prev, &_base_dec))) {
	//  printf("bad inside miler rabin loop\n");
	//  _print_number(_ptr);
	  return 1;
	}
  }
  if (!eq(&cur, &_one)) {
//	printf("bad outside miler rabin loop\n\n");
//	printf("x0\n");
//	_print_number(&x0);
//	printf("random \n");
//	_print_number(_ptr);
//	printf("cur\n");
//	_print_number(&cur);
//	printf("u: odd\n");
//	_print_number(&u);
//	printf("power: \n");
//	_print_number(&t);
//	printf("pow %d\n", pow);
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
	while (_res->_ptr[i] % 2 == 0){
	  _res->_ptr[i] = rand();
	}
	if (_res->_ptr[i] != 0){
	  _res->_length = i + 1;
	}
  }
}

/**
 * generate a prime
 * @param _res
 * @param size
 */
void _generate_prime(Number *_res, int size){

  int i = 1;
  while (1){
	_generate_random(_res, size);
	_print_number(_res);
	if (_miller_rabin(_res, 10)){
	  return;
	}
	++i;
	printf("again %d\n", i);
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
  Number p, q;
  _generate_prime(&p, _PRIME_SIZE / _BASE_UNIT);
  _generate_prime(&q, _PRIME_SIZE / _BASE_UNIT);
}