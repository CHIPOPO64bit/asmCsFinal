#include <stdio.h>
#include "modulo.h"

int main() {
  Number a;
  Number b;
  Number c;
  a._length = 1;
  b._length = 1;
  c._length = 0;
  for (int i = 0; i <_DEFAULT_SIZE; ++i){
	a._ptr[i] = 0;
	b._ptr[i] = 0;
	c._ptr[i] = 0;
  }

  a._ptr[0] = 10;
  a._ptr[1] = 0;
  b._ptr[0] = 100;


  _modulo(&a, &b, &c);

  printf("\n\n");
  for (int i = 0; i < 10; ++i){
	printf("%d\n", c._ptr[i]);
  }
  //printf("%d\n", _find_distance(&a, &b));
  return 0;
}
