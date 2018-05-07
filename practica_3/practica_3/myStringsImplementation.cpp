#include "stdafx.h"
#include "myStringFunctions.h"

// Devuelve la cadena con indice indicado
const char * getStrForIndex(const char *c[], const int index, const int tableSize) {
	if (c != nullptr) {
		if (index < tableSize && index >= 0) {
			const char *p = c[index];
			return p;
		}
		else {
			return "Indice fuera de rango en la tabla";
		}
	}
	else {
		return nullptr;
	}
}

// Devuelve la cadena con indice indicado dada la vuelta
char * getRevertStrForIndex(const char *c[], const int index, const int tableSize) {
	if (c != nullptr) {
		if (index < tableSize && index >= 0) {
			const char *p = c[index];
			return reverseString(p);
		}
		else {
			return "Indice fuera de rango en la tabla";
		}
	}
	else {
		return nullptr;
	}
}

char * reverseString(const char c[]) {
	int length = 0;

	while (*(c + length) != '\0') {
		length++;
	}

	const char *cAux = (c + length);

	char *newStr = new char[length + 1];
	char *newStrAux = newStr;

	for (int i = (length - 1); i >= 0; i--) {
		*(newStr++) = *(--cAux);
	}
	*(newStr++) = '\0';

	newStr = newStrAux;

	return newStr;
}