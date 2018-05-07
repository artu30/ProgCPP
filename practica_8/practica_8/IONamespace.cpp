#include "stdafx.h"
#include "IONamespace.h"
#include <stdio.h>

fileID IONamespace::openFile(const char *file, const char *mode) {
	fileID idFile;
	fopen_s(&idFile, file, mode);

	if (idFile != NULL) {
		return idFile;
	}
	else {
		return NULL;
	}
}

void IONamespace::closeFile(fileID idFile) {
	fclose(idFile);
}

const int IONamespace::readFile(fileID fileId, unsigned const int numCharacters, char *readBuffer) {
	rewind(fileId);
	fseek(fileId, 0, SEEK_END);
	long lSize = ftell(fileId);
	rewind(fileId);

	const int result = fread(readBuffer, sizeof(char), numCharacters, fileId);

	*(readBuffer + numCharacters) = '\0';

	return result;
}

const int IONamespace::writeFile(fileID fileId, const char writeBuffer[]) {
	const int result = fwrite(writeBuffer, sizeof(char), getStringSize(writeBuffer), fileId);

	return result;
}

int IONamespace::getStringSize(const char myStr[]) {
	int size = 0;
	while (*(myStr++) != '\0') {
		size++;
	}

	return size;
}