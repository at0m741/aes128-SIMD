#include "aes.h"

__attribute__((always_inline))
inline void Columns(uint8_t state[4][Nb]) {
	uint8_t temp_state[4][Nb];
	for (int c = 0; c < Nb; ++c) {
		temp_state[0][c] = g_mult(0x02, state[0][c]) ^ g_mult(0x03, state[1][c]) ^ state[2][c] ^ state[3][c];
		temp_state[1][c] = state[0][c] ^ g_mult(0x02, state[1][c]) ^ g_mult(0x03, state[2][c]) ^ state[3][c];
		temp_state[2][c] = state[0][c] ^ state[1][c] ^ g_mult(0x02, state[2][c]) ^ g_mult(0x03, state[3][c]);
		temp_state[3][c] = g_mult(0x03, state[0][c]) ^ state[1][c] ^ state[2][c] ^ g_mult(0x02, state[3][c]);
	}
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < Nb; ++j)
			state[i][j] = temp_state[i][j];
}

__attribute__((always_inline))
inline void InvColumns(uint8_t state[4][Nb]) {
	uint8_t temp_state[4][Nb];
	for (int c = 0; c < Nb; ++c) {
		temp_state[0][c] = g_mult(0x0e, state[0][c]) ^ g_mult(0x0b, state[1][c]) ^ g_mult(0x0d, state[2][c]) ^ g_mult(0x09, state[3][c]);
		temp_state[1][c] = g_mult(0x09, state[0][c]) ^ g_mult(0x0e, state[1][c]) ^ g_mult(0x0b, state[2][c]) ^ g_mult(0x0d, state[3][c]);
		temp_state[2][c] = g_mult(0x0d, state[0][c]) ^ g_mult(0x09, state[1][c]) ^ g_mult(0x0e, state[2][c]) ^ g_mult(0x0b, state[3][c]);
		temp_state[3][c] = g_mult(0x0b, state[0][c]) ^ g_mult(0x0d, state[1][c]) ^ g_mult(0x09, state[2][c]) ^ g_mult(0x0e, state[3][c]);
	}
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < Nb; ++j)
			state[i][j] = temp_state[i][j];
}


