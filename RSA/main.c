#include <stdio.h>
#include "modulo.h"

// TODO: problem: 255 fails, considered as 0, assume the cause is overflow
int main() {
  Number a;
  Number b;
  Number c;
  Number base;
  a._length = 2;
  b._length = 1;
  base._length = 1;
  c._length = 0;
  for (int i = 0; i <_DEFAULT_SIZE; ++i){
	a._ptr[i] = 0;
	b._ptr[i] = 0;
	c._ptr[i] = 0;
	base._ptr[i] = 0;
  }

  a._ptr[0] = 225;
  a._ptr[1] = 7;
  b._ptr[0] = 72;
  _mult(&b, &b, &c);
  b._ptr[1] = 0;
  base._ptr[0] = 127;
  base._ptr[1] = 0;
  _modular_exp(&b, &a, &base, &c);
  // TODO: need to fix modular exp
  //_modular_exp(&a, &b, &base, &c);

  for (int i = 0; i < 10; ++i){
	printf("%d\n", c._ptr[i]);
  }
  //printf("%d\n", c._length);

  return 0;
}
