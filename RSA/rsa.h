//
// Created by David Keisar on 2/21/22.
//

#ifndef RSA__RSA_H_
#define RSA__RSA_H_
#include "modulo.h"

/**
 *
 * @param _ptr
 * @param _base
 * @return
 */
int _witness(const Number *_ptr, const Number *_base);

/**
 * Miller rabin algorithm
 * @param _ptr
 * @param _iter
 * @Complexity:
 * @return
 */
int _miller_rabin(const Number *_ptr, int _iter);

/**
 * generate a random number
 * @param _res
 * @param size
 */
void _generate_random(Number *_res, int size);

/**
 * generate a prime
 * @param _res
 * @param size
 */
void _generate_prime(Number *_res, int size);

/**
 * Generate RSA keys
 * @param length
 * @param _N
 * @param _e
 * @param _d
 */
void _generate_keys(int length, Number *_N, Number *_e, Number *_d);

#endif //RSA__RSA_H_