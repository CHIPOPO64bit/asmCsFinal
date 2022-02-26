#include <stdio.h>
#include "modulo.h"
#include "rsa.h"

// TODO: problem: 255 fails, considered as 0, assume the cause is overflow
int main() {


  Number a;
  Number b;
  Number c, s, t;
  Number base;
  a._length = 2;
  b._length = 1;
  base._length = 2;
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
//  a._ptr[0] = 2;
//  a._ptr[1] = 3;
//  b._ptr[0] = 7;
//  base._ptr[0] = 121;


  init_program();
  a._ptr[0] = 17;
//  printf("i: %d result: %d\n", 17, _miller_rabin(&a, 10));
  for (int i = 2; i < 256; ++i){
	a._ptr[0] = i;
	for (int j = 1; j < 256; ++j){
	  a._ptr[1] = j;
	  if (_miller_rabin(&a, 10)){
		printf("%d %d\n ", i, j);
		printf("\n");
	  }
	}
	//printf("i: %d result: %d\n", i, _miller_rabin(&a, 10));
  }





  return 0;
}
