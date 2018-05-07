#include "stdafx.h"
#include "IONamespace.h"
#include "stringsNamespace.h"

int stringNamespace::getStrApparitions(fileID fileId, const char *strToSearch) {
	char c;
	int n = 0;
	int count = 0;
	int charApparittions = 0;
	int charToSearchSize = IONamespace::getStringSize(strToSearch);
	do {
		c = fgetc(fileId);
		if ((c == *(strToSearch + count)) && (*(strToSearch + count) != '\0')) {
			charApparittions++;
			count++;
		}
		else {
			count = 0;
			charApparittions = 0;
		}

		if (charApparittions == charToSearchSize) {
			charApparittions = 0;
			count = 0;
			n++;
		}
	} while (c != EOF);

	IONamespace::closeFile(fileId);

	printf("Fichero 1 cerrado\n");

	return n;
}

signed int stringNamespace::getStrCounter(fileID fileId) {
	int pCount = 0;
	signed int acumulate = 0;
	char *myNumber = new char[256];
	char* context = NULL;

	while (fgets(myNumber, 256, fileId)) {
		char * pch;
		pch = strtok_s(myNumber, ",", &context);
		while (pch != NULL) {
			acumulate += atoi(pch);
			pch = strtok_s(NULL, ",", &context);
		}
	}

	IONamespace::closeFile(fileId);

	printf("Fichero 2 cerrado\n");

	delete[]myNumber;

	return acumulate;
}