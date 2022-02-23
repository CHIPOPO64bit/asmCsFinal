#include <stdio.h>
#include "modulo.h"

// TODO: problem: 255 fails, considered as 0, assume the cause is overflow
int main() {
  Number a;
  Number b;
  Number c;
  Number base;
  a._length = 3;
  b._length = 1;
  base._length = 1;
  c._length = 0;
  for (int i = 0; i <_DEFAULT_SIZE; ++i){
	a._ptr[i] = 0;
	b._ptr[i] = 0;
	c._ptr[i] = 0;
	base._ptr[i] = 0;
  }
  a._ptr[0] = 255;
  a._ptr[1] = 255;
  a._ptr[2] = 255;
//  a._ptr[2] = 134;
//  a._ptr[3] = 248;


  _shift_right(&a, &c, 3, 0);
  for (int i = 0; i < 10; ++i){
	printf("%d\n", c._ptr[i]);
  }
  //printf("%d\n", c._length);

  return 0;
}
