#include "myFunctions.h"
#include <string.h>
#include <stdio.h>
#include "stdafx.h"

typedef unsigned const char* arrayBytes;

// Devuelve el entero por bytes, ene ste caso 4 bytes
void getAllBytes(const int n) {
	unsigned const int intSize = sizeof(n);
	arrayBytes p = reinterpret_cast<arrayBytes>(&n);
	for (int i = 0; i < intSize; i++) {
		printf("El byte en la posicion %d es %x\n", i, *(p + i));
	}
}

// Devuelve el entero mayor de una lista de enteros
void getMaxInt(const int t[]) {
	int max = 0;
	const int *p = t;
	for (int i = 0; i <= 6; i++) {

		if (max < *(p + i)) {
			max = *(p + i);
		}
	}

	printf("El mayor en decimal es %d\n", max);
}

// Devuelve el byte mayor de una lista de enteros
void getMaxByte(const int t[]) {
	int max = 0;
	unsigned const int elemSize = sizeof(t[0]);
	arrayBytes number = reinterpret_cast<arrayBytes>(&t[0]);
	for (int i = 0; i <= (6 * elemSize); i++) {
		if (max <  *(number + i)) {
			max = *(number + i);
		}
	}

	printf("El Byte mayor es %d\n", max);
}

// Da la vuelta a una cadena
void reverseString(const char c[]) {
	int length = 0;
	while (*(c + length) != '\0') {
		length++;
	}

	const char *cAux = (c + length);

	char *newStr = new char[length + 1];
	char *auxStr = newStr;

	for (int i = (length - 1); i >= 0; i--) {
		*(newStr++) = *(--cAux);
	}
	*(newStr) = '\0';

	printf("La cadena original es %s\n", c);
	printf("La cadena dada la vuelta es %s\n", auxStr);

	delete[]newStr;
}