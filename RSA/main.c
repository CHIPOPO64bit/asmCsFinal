#include <stdio.h>
#include "modulo.h"
#include "rsa.h"
#define _PUBLIC_KEY_FILE_OPEN "The two streams below are N and e. from left \
to right you can find the digits in hex\n\n"
#define _PRIVATE_KEY_FILE_OPEN "The stream below is d. from left \
to right you can find the digits in hex\n\n"
#define _OPEN_MSG "Welcome to encryption decryption editor.\nFor generating \
keys, press 'g'.\nFor encryption via an existing key, press 'e'.\nFor \
decryption via an existing key, press 'd'.\nFor a brief description press \
'b'.\nPlease Enter g/e/d/b: "
#define _USAGE_ERROR "USAGE: <g for keys, e for encryption, d for \
decryption, b for brief description>\n"
#define _GENERATE_KEYS 'g'
#define _ENCRYPT_CHAR 'e'
#define _DECRYPT_CHAR 'd'
#define _BRIEF_DESC 'b'
#define _MAX_PATH_SIZE 100

void get_path(char *path){
  char cur, i = 0;
  path[(int)i] = '\0';
  cur = fgetc(stdin);
  while (cur != '\n' && cur != 10 && i < _MAX_PATH_SIZE - 1){
	path[(int)i] = cur;
	cur = fgetc(stdin);
	++i;
  }
  path[(int)i] = '\0';
}

void _write_key(FILE *file,  const Number *key){
  for (int i = 0; i<key->_length; ++i){
	fprintf(file, "%x ", (unsigned char) key->_ptr[i]);
  }
  fprintf(file, "\n\n");
}


void _write_public_key(FILE *file, const Number *N, const Number *e){
  fprintf(file, _PUBLIC_KEY_FILE_OPEN);
  _write_key(file, N);
  _write_key(file, e);
}

void _write_private_key(FILE *file, const Number *d){
  fprintf(file, _PRIVATE_KEY_FILE_OPEN);
  _write_key(file, d);
}

void _handle_generate_keys(){
  char path_public[_MAX_PATH_SIZE], path_private[_MAX_PATH_SIZE];
  // get path for
  printf("Enter the path for the public key: ");
  get_path(path_public);
  printf("Enter the path for the private key: ");
  get_path(path_private);
  printf("%s\n", path_public);
  printf("%s\n", path_private);
  FILE *public;
  FILE *private;
  public = fopen(path_public, "w");
  if (public == NULL){
	fprintf(stderr, "Wrong path for public key.\n");
	exit(EXIT_FAILURE);
  }
  private = fopen(path_private, "w");
  if (private == NULL){
	fclose(public);
	fprintf(stderr, "Wrong path for private key.\n");
	exit(EXIT_FAILURE);
  }
  Number e,d,N;
  Init(&e), Init(&d), Init(&N);
  _generate_keys(16, &N, &e, &d);
  _write_public_key(public, &N, &e);
  _write_private_key(private, &d);
  fclose(public);
  fclose(private);
}

void _handle_encrypt(){


}

void _handle_decrypt(){

}

void _handle_description(){

}

void _handle_request(const char ctrl){

  init_program();
  if (ctrl == _GENERATE_KEYS){
	_handle_generate_keys();
  } else if (ctrl == _ENCRYPT_CHAR){
	_handle_encrypt();
  } else if (ctrl == _DECRYPT_CHAR){
	_handle_decrypt();
  } else if (ctrl == _BRIEF_DESC){
	_handle_description();
  } else {
	printf("%s\n", _USAGE_ERROR);
  }
}

int main() {
  printf("%s\n", _OPEN_MSG);
  char ctrl;
  ctrl = fgetc(stdin);
  _handle_request(ctrl);
  return 0;
}
