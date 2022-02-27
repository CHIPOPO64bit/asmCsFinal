#include <stdio.h>
#include "modulo.h"
#include "rsa.h"

// TODO: problem: 255 fails, considered as 0, assume the cause is overflow
int main() {
  Number a;
  Number b;
  Number c, s, t;
  Number base;
  b._length = 0;
  a._length  = 0;
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
  init_program();
  _generate_keys(32, &a, &b, &c);

  s._ptr[0] = 255;
  s._ptr[1] = 255;
  s._length = 2;
  _mult(&b, &c, &t);
  _modular_exp(&s, &t, &a, &base);

  printf("\n");
  _print_number(&a);
  _print_number(&b);
  _print_number(&c);
  _print_number(&base);
  return 0;
}
