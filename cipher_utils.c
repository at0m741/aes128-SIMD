#include "aes.h"

/*
	* g_mult is first function that multiplies two polynomials in GF(2^8) 
	* the polynomials are represented as 8-bit integers
	* the result is also an 8-bit integer
	* the function is used in the MixColumns and InvMixColumns functions
*/

__attribute__((always_inline))
inline uint8_t g_mult(uint8_t first, uint8_t second) {
	uint8_t p = 0;
	uint8_t hi_bit_set;
	for (int i = 0; i < 8; i++) {
		if (second & 1)
			p ^= first;
		hi_bit_set = first & 0x80;
		first <<= 1;
		if (hi_bit_set)
			first ^= 0x1b;
		second >>= 1;
	}
	return p;
}

/*
	* Sub and InvSub are functions that substitute the bytes of the state matrix 
	* the Sub function uses the sbox table
	* the InvSub function uses the rsbox table
	* the state matrix is first 4xNb matrix
	* the sbox and rsbox tables are 256-byte arrays
*/


__attribute__((always_inline))
inline void Sub(uint8_t state[4][Nb]) {
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < Nb; ++j)
			state[i][j] = sbox[state[i][j]];
}

__attribute__((always_inline))
inline void InvSub(uint8_t state[4][Nb]) {
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < Nb; ++j)
			state[i][j] = rsbox[state[i][j]];
}


