#include <stdio.h>
#include "modulo.h"
int main() {
  Number a;
  Number b;
  Number c;
  a._length = 4;
  b._length = 4;
  c._length = 1;
  for (int i = 0; i <_DEFAULT_SIZE; ++i){
	a._ptr[i] = 0;
	b._ptr[i] = 0;
	c._ptr[i] = 0;
  }

//  for (int i = 0; i < 3; ++i){
//	a._ptr[i] = 255;
//	b._ptr[i] = 255;
//  }



	for (int i = 0; i < 4; ++i){
	  a._ptr[i] = i;
	  b._ptr[i] = 2*i;
	  printf("%d %d\n", a._ptr[i], b._ptr[i]);
	}


  _mult(&a, &b, &c);

  //_add(&a, &b, &c);
  for (int i = 0; i < 10; ++i){
	printf("%d\n", c._ptr[i]);
  }

  return 0;
}
