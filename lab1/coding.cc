#include "coding.h"

unsigned char Coding::encode(unsigned char c) {
	//cout << "Encoding char: " << c << endl;
	return c+10;
}

unsigned char Coding::decode(unsigned char c) {
	//cout << "Decoding char: " << c << endl;
	return c-10;
}
