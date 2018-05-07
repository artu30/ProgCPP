#include "stdafx.h"
#include "IONamespace.h"
#include <stdio.h>

fileID IONamespace::openFile(const char *file, const char *mode) {
	fileID idFile;
	fopen_s(&idFile, file, mode);

	if (idFile) {
		return idFile;
	}
	else {
		return nullptr;
	}
}

void IONamespace::closeFile(fileID idFile) {
	if (idFile) {
		fclose(idFile);
		idFile = nullptr;
	}
}

const int IONamespace::readFile(fileID fileId, unsigned const int numCharacters, char *readBuffer) {
	if (fileId) {
		rewind(fileId);
		fseek(fileId, 0, SEEK_END);
		long lSize = ftell(fileId);
		rewind(fileId);

		const int result = fread(readBuffer, sizeof(char), numCharacters, fileId);

		*(readBuffer + numCharacters) = '\0';

		return result;
	}
	else {
		return 0;
	}
	
}

const int IONamespace::writeFile(fileID fileId, const char writeBuffer[], int bufferSize) {
	if (fileId) {
		if (bufferSize == 0) {
			bufferSize = getStringSize(writeBuffer);
		}
		const int result = fwrite(writeBuffer, sizeof(char), bufferSize, fileId);

		return result;
	}
	else {
		return 0;
	}
}

int IONamespace::getStringSize(const char myStr[]) {
	int size = 0;
	while (*(myStr++) != '\0') {
		size++;
	}

	return size;
}