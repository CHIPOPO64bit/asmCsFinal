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
  base._length = 1;
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
  _generate_prime(&c, 16);
  _generate_prime(&b, 16);
//  _print_number(&c);
	printf("%d\n", e._length);

  return 0;
}
