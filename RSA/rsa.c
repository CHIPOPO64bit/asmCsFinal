//
// Created by David Keisar on 2/26/22.
//
#include "rsa.h"

/**
 *
 * @param _ptr
 * @param _base
 * @return
 */
int _witness(const Number *_ptr, const Number *_base){
  Number u,t, x0, cur, prev;
  Init(&u);
  Init(&t);
  Init(&x0);
  Init(&cur);
  Init(&prev);
  int pow = 2;
  // TODO: compose _ptr - 1 and not _ptr!!
  _compose(_ptr, &u, &t, &pow);
  _print_number(_ptr);
  printf("composition\n");
  _print_number(&u);

  _modular_exp(_ptr, &u, _base, &x0);
  _print_number(&x0);

  _copy(&prev, &x0);

  _copy(&cur, &prev);
  for (int i = 1; i <= pow; ++i){
	_mult(&prev, &prev, &cur);
	if (eq(&cur, &_one) && (!eq(&prev, &_one)) && (!eq(&prev, &_minus_one))){

	  return 1;
	}
  }
  if (!eq(&cur, &_one)){
	printf("bad outside loop miller rabin\n");
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
int _miller_rabin(const Number *_ptr, int _iter){
  Number random;
  for (int i = 0; i < _iter; ++i){
	_random(_ptr, &random);
	if (_witness(&random, _ptr)){
	  printf("bad\n");
	  return 0;
	}
  }
  return 1;
}

/**
 * Generate RSA keys
 * @param length
 * @param _N
 * @param _e
 * @param _d
 */
void _generate_keys(int length, Number *_N, Number *_e, Number *_d);