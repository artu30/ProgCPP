#include "stdafx.h"
#include "StringUtilities.h"
#include <stdlib.h>

int getStringSize(const char myStr[]) {
	int size = 0;
	while (*(myStr++) != '\0') {
		size++;
	}

	return size;
}

int getStrApparitions(fileID fileId, const char *strToSearch) {
	if (fileId) {
		char c;
		int n = 0;
		int count = 0;
		int charApparittions = 0;
		int charToSearchSize = getStringSize(strToSearch);
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

		return n;
	}
	else {
		return 0;
	}
}

signed int getStrCounter(fileID fileId) {
	if (fileId) {
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

		delete[]myNumber;

		return acumulate;
	}
	else {
		return 0;
	}
}