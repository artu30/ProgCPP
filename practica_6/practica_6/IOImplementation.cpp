#include "stdafx.h"
#include <stdlib.h>
#include "StringUtilities.h"
#include "IOManage.h"

fileID openFile(const char *file, const char *mode) {
	if (file) {
		fileID idFile;
		fopen_s(&idFile, file, mode);

		if (idFile != nullptr) {
			return idFile;
		}
		else {
			return nullptr;
		}
	}
	return nullptr;
}

void closeFile(fileID idFile) {
	if (idFile) {
		fclose(idFile);
	}
}

const int readFile(fileID fileId, unsigned const int numCharacters, char *readBuffer) {
	if (fileId) {
		rewind(fileId);
		fseek(fileId, 0, SEEK_END);
		long lSize = ftell(fileId);
		rewind(fileId);

		const int result = fread(readBuffer, sizeof(char), numCharacters, fileId);

		return result;
	}
	else {
		return 0;
	}
}

const int writeFile(fileID fileId, const char writeBuffer[], int bufferSize) {
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