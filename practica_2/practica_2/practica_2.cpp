// Practica 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myFunctions.h"
#include <string.h>

int main()
{
	const int number = 30111991;
	getAllBytes(number);

	const int tabla[] = { 1, 3, 2, 5, 3, static_cast<signed int>(0xFFFFFFFF), 2 };
	getMaxInt(tabla);
	getMaxByte(tabla);

	const char str[] = "alistate en la marina";
	reverseString(str);

	return 0;
}