#include <stdio.h>
#include "modulo.h"

// TODO: problem: 255 fails, considered as 0, assume the cause is overflow
int main() {
  Number a;
  Number b;
  Number c, s, t;
  Number base;
  a._length = 2;
  b._length = 0;
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
  a._ptr[0] = 0;
  a._ptr[1] = 248;

  _compose(&a, &b, &c);
  _print_number(&b);
  _print_number(&c);


  return 0;
}
