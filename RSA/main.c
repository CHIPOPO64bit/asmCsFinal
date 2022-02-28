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
#define _DESCRIPTION_MSG "This is the encryption decryption big brother.\nWe \
use RSA (miller rabin variation) in order to ensure your privacy.\nBe ware, \
generation of \
primes is not an easy task and might take a couple of minuets.\n"
#define _GENERATE_KEYS 'g'
#define _ENCRYPT_CHAR 'e'
#define _DECRYPT_CHAR 'd'
#define _BRIEF_DESC 'b'
#define _MAX_PATH_SIZE 100
#define _MAX_LINE_LENGTH 200

// Huge problem. Code doesn't work!!!!

void get_path(char *path){
  char cur, i = 0;
  path[(int)i] = '\0';
  cur = fgetc(stdin);
  while (cur != '\n'  && i < _MAX_PATH_SIZE - 1){
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

char convert_to_value(char value){
  if (value >= 'a'){
	return 10 + (value % 'a');
  }
  return value - 48;
}

void _read_key(const char*line, Number *key){
  int i = 0, j = 0;
  char ah , al, cur;
  while (line[i] && line[i] != '\n' && i < _MAX_LINE_LENGTH){
	ah = line[i++];
	al = line[i++];
	++i;
	ah = convert_to_value(ah);
	al = convert_to_value(al);
	cur = (ah << 4) | al;
	key->_ptr[j] = cur;
	key->_length = ++j;
  }
}

void _read_encryption_file(FILE *key_file, Number *N, Number *e){
  char line[_MAX_LINE_LENGTH];
  fgets(line, _MAX_LINE_LENGTH, key_file);
  fgets(line, _MAX_LINE_LENGTH, key_file);
  fgets(line, _MAX_LINE_LENGTH, key_file);
  _read_key(line, N);
  fgets(line, _MAX_LINE_LENGTH, key_file);
  fgets(line, _MAX_LINE_LENGTH, key_file);
  _read_key(line, e);
}

void _read_decryption_file(FILE *key_file, Number *N, Number *d){
  char line[_MAX_LINE_LENGTH];
  fgets(line, _MAX_LINE_LENGTH, key_file);
  fgets(line, _MAX_LINE_LENGTH, key_file);
  fgets(line, _MAX_LINE_LENGTH, key_file);
  _read_key(line, d);
}

int _open_file(FILE **file, const char *msg, const char *mode){
  char path[_MAX_PATH_SIZE];
  printf("%s\n", msg);
  get_path(path);
  *file = fopen(path, mode);
  if (*file == NULL){
	fprintf(stderr, "Error, file doesn't exists\n");
	return 0;
  }
  return 1;
}
void _write_data(FILE *file, const Number *data){
  for (int i = 0; i < data->_length; ++i){
	printf("%02x\n", data->_ptr[i]);
	fprintf(file, "%02x", data->_ptr[i]);
  }
}
void _write_decrypted(FILE *file, const Number *data){
  for (int i = 0; i < data->_length; ++i){
	fprintf(file, "%c", data->_ptr[i]);
  }
}

void _encrypt(FILE *data, FILE *encrypted, const Number *N, const Number *e){
  Number temp, res;
  Init(&res);
  char line[_MAX_SEGMENT+1];
  int i, length;
  while ((length = fread(line, sizeof(char), _MAX_SEGMENT, data))){
	i = 0;
	line[length] = '\0';
	printf("%s\n", line);
	Init(&temp);
	while (i < length){
	  temp._ptr[i] = line[i];
	  temp._length = ++i;
	}
	Init(&res);
	_modular_exp(&temp, e, N, &res);
	for (int i = res._length; i < _MAX_SEGMENT; ++i){
	  res._ptr[i] = 0;
	}
	printf("%d %d\n", res._length, res._ptr[_MAX_SEGMENT-1]);
	res._length =_MAX_SEGMENT;

	_print_number(&res);
	_write_data(encrypted, &res);
	Init(&temp);
	_modular_exp(&res, &d, N, &temp);
	printf("m^ed mod n = 1?\n");
	_print_number(&temp);
  }
}
void _handle_encrypt(){
  Number N, e;
  Init(&N), Init(&e);
  FILE *key_file, *data_file, *encrypted_file;
  if (!_open_file(&key_file, "Enter the path for the encryption key. Note, "
							"this file must have "
						"been generated by the editor, or, at least be in the same format, "
						"otherwise it won't work: ", "r")){
	exit(EXIT_FAILURE);
  }
  else if (!_open_file(&data_file, "Please enter path for the data file",
					   "r")){
	fclose(key_file);
	exit(EXIT_FAILURE);
  } else if (! _open_file(&encrypted_file, "Please enter the path for the "
										   "encrypted file", "w")){
	fclose(key_file);
	fclose(data_file);
  }
  _read_encryption_file(key_file, &N, &e);
  _print_number(&N);

  _encrypt(data_file, encrypted_file, &N, &e);
  fclose(key_file);
  fclose(data_file);
  fclose(encrypted_file);
}
void _decrypt(FILE *encrypted, FILE *decrypted, const Number *N, const Number
*d){
  Number temp, res;
  Init(&res);
  char line[2*_MAX_SEGMENT], ah, al;
  int i, length,j;
  while ((length = fread(line, sizeof(char),
											 _MAX_SEGMENT*2,
							   encrypted))){
	i = 0, j =0;
	line[length] = '\0';
	printf("%s\n", line);
	Init(&temp);
	while (i < length){
	  ah = convert_to_value(line[i++]);
	  al = convert_to_value(line[i++]);
	  printf("%d %d\n", ah, al);
	  temp._ptr[j] = al | ah << 4;
	  //printf("%d\n", temp._ptr[j]);
	  if (temp._ptr[j] != 0){
		temp._length = ++j;
	  }
	}
	Init(&res);
	_print_number(&temp);
	_modular_exp(&temp, d, N, &res);
	_print_number(&res);
	_write_decrypted(decrypted, &res);
  }
}
void _handle_decrypt(){
  Number d, N;
  Init(&d), Init(&N);
  FILE *key_file, *encrypted_file, *decrypted_file;
  if (!_open_file(&key_file, "Enter the path for the decryption key. Note, "
							 "this file must have "
							 "been generated by the editor, or, at least be in the same format, "
							 "otherwise it won't work: ", "r")){
	exit(EXIT_FAILURE);
  }
  else if (!_open_file(&encrypted_file, "Please enter path for the encrypted"
										" file",
					   "r")){
	fclose(key_file);
	exit(EXIT_FAILURE);
  } else if (! _open_file(&decrypted_file, "Please enter the path for the "
										   "decrypted file", "w")){
	fclose(key_file);
	fclose(encrypted_file);
	exit(EXIT_FAILURE);
  }
  _read_encryption_file(key_file, &N, &d);
  _print_number(&d);
  _decrypt(encrypted_file, decrypted_file, &N, &d);
  fclose(key_file);
  fclose(decrypted_file);
  fclose(encrypted_file);

}

void _handle_description(){

  printf("%s\n", _DESCRIPTION_MSG);

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
  fgetc(stdin);
  _handle_request(ctrl);
init_program();
Number _N, en, res, _d;
Init(&res), Init(&_N), Init(&en), Init(&_d);
//
//uint8_t enc[] ={28, 116, 161, 87, 211, 32, 128, 106, 163, 229, 235, 42, 147,
//			   192,
//		  36, 36, 59, 5, 221, 214, 2, 16, 238, 109, 51, 117, 205, 251, 121,
//		  199, 242, 60};
//uint8_t N[] = {34, 128, 45, 166, 83, 112, 183, 19, 156, 74, 205, 14, 23, 58,
//			128, 233, 166, 205, 186, 125, 52, 103, 50, 133, 241, 207, 207, 228, 3, 236, 170, 21};
uint8_t d[] = {17, 133, 247, 41, 190, 193, 198, 75, 48, 156, 17, 144, 177, 157,
			166, 114, 37, 201, 140, 72, 179, 177, 54, 108, 194, 13, 45, 121, 217, 148, 167, 97};

for (int i = 0; i < 32; ++i){
//  en._ptr[i] = enc[31-i];
//  _N._ptr[i] = N[31-i];
  _d._ptr[i] = d[31-i];
}
//  en._length = 32;
//  _N._length = 32;
//  _d._length = 32;
//  _modular_exp(&en, &_d, &_N, &res);
//  _print_number(&res);
//  _write_decrypted(stdout, &res);
//FILE *private = fopen("private.txt", "r");
//Number N, e;
//Init(&N), Init(&e);
//  _read_decryption_file(private, &e);
//  fclose(private);
  return 0;
}
