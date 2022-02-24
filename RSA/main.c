#include <stdio.h>
#include "modulo.h"

// TODO: problem: 255 fails, considered as 0, assume the cause is overflow
int main() {
  Number a;
  Number b;
  Number c, s, t;
  Number base;
  a._length = 1;
  b._length = 1;
  base._length = 0;
  c._length = 0;
  s._length = 0, t._length = 0;

  for (int i = 0; i <_DEFAULT_SIZE; ++i){
	a._ptr[i] = 0;
	b._ptr[i] = 0;
	c._ptr[i] = 0;
	s._ptr[i] = 0;
	t._ptr[i] = 0;
	base._ptr[i] = 0;
  }
  a._ptr[0] = 4;
  b._ptr[0] = 123;
//	_mult(&a, &b, &c);
//
//  _print_number(&c);
  _inverse(&a, &b, &c);

  _print_number(&c);
//  _print_number(&base);
//  _print_number(&s);
//  _print_number(&t);


  //_shift_right(&a, &c, 3, 0);


  return 0;
}
