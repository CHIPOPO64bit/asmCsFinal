#include <stdio.h>
#include "modulo.h"

int main() {
  Number a;
  Number b;
  Number c;
  Number base;
  a._length = 2;
  b._length = 3;
  base._length = 1;
  c._length = 0;
  for (int i = 0; i <_DEFAULT_SIZE; ++i){
	a._ptr[i] = 0;
	b._ptr[i] = 0;
	c._ptr[i] = 0;
	base._ptr[i] = 0;
  }

  a._ptr[0] = 2;
  a._ptr[1] = 1;
  b._ptr[0] = 2;
  b._ptr[1] = 3;
  b._ptr[2] = 3;
  base._ptr[0] = 121;
  _modulo(&b, &a, &c);
  //_modular_exp(&a, &b, &base, &c);

  for (int i = 0; i < 10; ++i){
	printf("%d\n", c._ptr[i]);
  }

  return 0;
}
