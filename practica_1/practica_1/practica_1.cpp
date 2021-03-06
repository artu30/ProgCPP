// Pr1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "characterFunctions.h"

int main()
{
	// Vit -> 01011101
	// Bullets -> 01000101
	// Companions -> 0011
	// Berseker -> 0, Shield -> 1, Infinite bullets -> 1, Invulnerable -> 0 == 0110
	unsigned int characterBits = 0x5D453006;

	// Calls getBullets function and returns the actual number of bullets
	unsigned int numBullets = getBullets(characterBits);
	printf("The number of bullets is = %d\n", numBullets);

	// Calls addBullets function and returns the new bullets
	addBullets(characterBits, 20);
	printf("The new number of bullets is = %x\n", characterBits);

	// Calls haveInfiniteBullets function and returns if i have infinite bullets or not
	bool haveInfBulletsRequest = haveInfiniteBullets(characterBits);
	if (haveInfBulletsRequest) {
		printf("You have infinite bullets!!!\n");
	}
	else {
		printf("You dont have infinite bullets :(\n");
	}

	// Reset my bits to remove infinite bullets
	// Vit -> 01011101
	// Bullets -> 01000101
	// Companions -> 0011
	// Berseker -> 0, Shield -> 1, Infinite bullets -> 0, Invulnerable -> 0 == 0010
	characterBits = 0x5D453004;

	activeBullets(characterBits);

	printf("The hexadecimal now is = %x and you have infinite bullets!!!\n", characterBits);

	return 0;
}

unsigned int getBullets(unsigned int charBits) {
	// Get my bites with the 8 bits bullets in first and second position (4 and 4)
	charBits = charBits >> 16;

	// Get the number of bullets with this mask and the "and" operation (needs 2 ones to set 1 in the bit value)
	charBits &= 0x000000FF;

	return charBits;
}

void addBullets(unsigned int &charBits, unsigned const int numToAdd) {
	unsigned int bulletsManage = charBits >> 16;

	// Get my copy of the original bits value and set bullets to 0
	charBits &= 0xFF00FFFF;

	// Let alone the bullets bits to plus the new bullets var
	bulletsManage &= 0x000000FF;
	if (bulletsManage + numToAdd >= 0x000000FF) {
		bulletsManage = 0x000000FF;
	}
	else {
		bulletsManage += numToAdd;
	}

	// Relocate bullets bits to the original position
	bulletsManage = bulletsManage << 16;

	// Set the copy of the original bits value with the new number of bullets
	bulletsManage |= charBits;

	charBits = bulletsManage;
}

bool haveInfiniteBullets(unsigned int charBits) {
	// Mask to compare if i have infinite bullets
	unsigned const int bitsToCompare = 0x00000002;

	// Get my second bit and if the "and" comparation is 2 it´s true, if not, false
	charBits &= bitsToCompare;

	if (charBits == 0) {
		return false;
	}

	return true;
}

void activeBullets(unsigned int &charBits) {
	// Mask to set infinite bullets to 1
	unsigned const int bitsToActiveBullets = 0x00000002;

	// With or operation set my bit that is in second position
	charBits |= bitsToActiveBullets;
}
