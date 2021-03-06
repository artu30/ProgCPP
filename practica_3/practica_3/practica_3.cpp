// Practica 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myStringFunctions.h"

int main()
{
	const char *str[] = { "Gerald", "Ciri", "Yenefer", "Triss", "Jaskier" };
	const int tableSize = sizeof(str) / sizeof(*str);
	
	const int i = 1; // "Ciri" | "iriC"

	const char *str1 = getStrForIndex(str, i, tableSize);

	if (str1 == nullptr) {
		printf("Puntero apunta a valor nulo\n");
	}
	else {
		printf("La cadena con indice %d es %s\n", i, str1);
	}

	char *str2 = getRevertStrForIndex(str, i, tableSize);

	if (str2 == nullptr) {
		printf("Puntero apunta a valor nulo\n");
	}
	else {
		printf("La cadena invertida con indice %d es %s\n", i, str2);
	}

	delete[]str2;

	return 0;
}