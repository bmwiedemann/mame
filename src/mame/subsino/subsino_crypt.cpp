// license:BSD-3-Clause
// copyright-holders:Luca Elia, David Haywood, Angelo Salese, Roberto Fresca
/***************************************************************************

Subsino XOR + Bitswap Encryption
by David Haywood

***************************************************************************/

#include "emu.h"

// XORs:

extern const uint8_t crsbingo_xors[8] = { 0xbb, 0xcc, 0xcc, 0xdd, 0xaa, 0x11, 0x44, 0xee };
extern const uint8_t newhunterc_xors[8] = { 0x44, 0xcc, 0xcc, 0xbb, 0xff, 0x44, 0x77, 0xaa };
extern const uint8_t sharkpy_xors[8] = { 0xcc, 0xaa, 0x66, 0xaa, 0xee, 0x33, 0xff, 0xff };
extern const uint8_t tisubb_xors[8] = { 0x44, 0x99, 0x55, 0x77, 0xaa, 0x77, 0x88, 0x55 };
extern const uint8_t victor5_xors[8] = { 0x99, 0x99, 0x33, 0x44, 0xbb, 0x88, 0x88, 0xbb };
extern const uint8_t victor21_xors[8] = { 0x44, 0xbb, 0x66, 0x44, 0xaa, 0x55, 0x88, 0x22 };

// Bitswaps:

void crsbingo_bitswaps(uint8_t *decrypt, int i)
{
	if ((i & 7) == 0) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 5, 4, 3, 6, 1, 0);
	if ((i & 7) == 1) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 1, 0, 3, 6, 5, 4);
	if ((i & 7) == 2) decrypt[i] = bitswap<8>(decrypt[i], 3, 2, 5, 0, 7, 6, 1, 4);
	if ((i & 7) == 3) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 5, 0, 3, 6, 1, 4);
	if ((i & 7) == 4) decrypt[i] = bitswap<8>(decrypt[i], 7, 6, 5, 0, 3, 2, 1, 4);
	if ((i & 7) == 5) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 1, 4, 3, 6, 5, 0);
	if ((i & 7) == 6) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 1, 0, 3, 6, 5, 4);
	if ((i & 7) == 7) decrypt[i] = bitswap<8>(decrypt[i], 3, 2, 1, 0, 7, 6, 5, 4);
}

void newhunterc_bitswaps(uint8_t *decrypt, int i)
{
	if ((i & 7) == 0) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 1, 0, 3, 6, 5, 4);
	if ((i & 7) == 1) decrypt[i] = bitswap<8>(decrypt[i], 7, 6, 5, 0, 3, 2, 1, 4);
	if ((i & 7) == 2) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 1, 0, 3, 6, 5, 4); // TODO: verify 7,6
	if ((i & 7) == 3) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 1, 0, 3, 6, 5, 4);
	if ((i & 7) == 4) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 5, 4, 3, 6, 1, 0);
	if ((i & 7) == 5) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 5, 0, 3, 6, 1, 4);
	if ((i & 7) == 6) decrypt[i] = bitswap<8>(decrypt[i], 7, 6, 1, 0, 3, 2, 5, 4);
	if ((i & 7) == 7) decrypt[i] = bitswap<8>(decrypt[i], 3, 2, 5, 0, 7, 6, 1, 4);
}

void sharkpy_bitswaps(uint8_t *decrypt, int i)
{
	if ((i & 7) == 0) decrypt[i] = bitswap<8>(decrypt[i], 3, 2, 1, 0, 7, 6, 5, 4);
	if ((i & 7) == 1) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 5, 4, 3, 6, 1, 0);
	if ((i & 7) == 2) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 1, 4, 3, 6, 5, 0);
	if ((i & 7) == 3) decrypt[i] = bitswap<8>(decrypt[i], 3, 6, 1, 0, 7, 2, 5, 4);
	if ((i & 7) == 4) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 5, 4, 3, 6, 1, 0);
	if ((i & 7) == 5) decrypt[i] = bitswap<8>(decrypt[i], 3, 2, 5, 4, 7, 6, 1, 0);
	if ((i & 7) == 6) decrypt[i] = bitswap<8>(decrypt[i], 7, 6, 1, 4, 3, 2, 5, 0);
	if ((i & 7) == 7) decrypt[i] = bitswap<8>(decrypt[i], 3, 6, 1, 4, 7, 2, 5, 0);
}

void tisubb_bitswaps(uint8_t *decrypt, int i)
{
	if ((i & 7) == 0) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 1, 0, 3, 6, 5, 4);
	if ((i & 7) == 1) decrypt[i] = bitswap<8>(decrypt[i], 7, 6, 1, 4, 3, 2, 5, 0);
	if ((i & 7) == 2) decrypt[i] = bitswap<8>(decrypt[i], 3, 6, 5, 0, 7, 2, 1, 4);
	if ((i & 7) == 3) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 5, 4, 3, 6, 1, 0);
	if ((i & 7) == 4) decrypt[i] = bitswap<8>(decrypt[i], 3, 2, 5, 4, 7, 6, 1, 0);
	if ((i & 7) == 5) decrypt[i] = bitswap<8>(decrypt[i], 3, 6, 1, 0, 7, 2, 5, 4);
	if ((i & 7) == 6) decrypt[i] = bitswap<8>(decrypt[i], 3, 6, 1, 0, 7, 2, 5, 4);
	if ((i & 7) == 7) decrypt[i] = bitswap<8>(decrypt[i], 3, 2, 1, 0, 7, 6, 5, 4);
}

void victor5_bitswaps(uint8_t *decrypt, int i)
{
	if ((i & 7) == 0) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 5, 4, 3, 6, 1, 0);
	if ((i & 7) == 1) decrypt[i] = bitswap<8>(decrypt[i], 7, 6, 5, 0, 3, 2, 1, 4);
	if ((i & 7) == 2) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 1, 0, 3, 6, 5, 4);
	if ((i & 7) == 3) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 1, 0, 3, 6, 5, 4);
	if ((i & 7) == 4) decrypt[i] = bitswap<8>(decrypt[i], 3, 2, 1, 0, 7, 6, 5, 4);
	if ((i & 7) == 5) decrypt[i] = bitswap<8>(decrypt[i], 7, 6, 5, 0, 3, 2, 1, 4);
	if ((i & 7) == 6) decrypt[i] = bitswap<8>(decrypt[i], 3, 6, 1, 0, 7, 2, 5, 4);
	if ((i & 7) == 7) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 1, 4, 3, 6, 5, 0);
}

void victor21_bitswaps(uint8_t *decrypt, int i)
{
	if ((i & 7) == 0) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 1, 0, 3, 6, 5, 4);
	if ((i & 7) == 1) decrypt[i] = bitswap<8>(decrypt[i], 3, 6, 1, 4, 7, 2, 5, 0);
	if ((i & 7) == 2) decrypt[i] = bitswap<8>(decrypt[i], 3, 2, 1, 4, 7, 6, 5, 0);
	if ((i & 7) == 3) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 5, 4, 3, 6, 1, 0);
	if ((i & 7) == 4) decrypt[i] = bitswap<8>(decrypt[i], 7, 2, 5, 4, 3, 6, 1, 0);
	if ((i & 7) == 5) decrypt[i] = bitswap<8>(decrypt[i], 3, 6, 5, 0, 7, 2, 1, 4);
	if ((i & 7) == 6) decrypt[i] = bitswap<8>(decrypt[i], 7, 6, 5, 4, 3, 2, 1, 0);
	if ((i & 7) == 7) decrypt[i] = bitswap<8>(decrypt[i], 3, 2, 1, 4, 7, 6, 5, 0);
}

// Decrypt:

void subsino_decrypt(uint8_t *region, void (*bitswaps)(uint8_t *decrypt, int i), const uint8_t *xors, int size)
{
	std::unique_ptr<uint8_t[]> decrypt = std::make_unique<uint8_t[]>(size);

	for (int i = 0; i < size; i++)
	{
		decrypt[i] = region[i] ^ xors[i & 7];
		bitswaps(decrypt.get(), i);
	}
	memcpy(region, decrypt.get(), size);
}
