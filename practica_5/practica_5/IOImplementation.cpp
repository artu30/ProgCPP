#include "stdafx.h"
#include "IOManage.h"

fileID openFile(const char *file, const char *mode) {
	if (!file) {
		return NULL;
	}

	fileID idFile;
	fopen_s(&idFile, file, mode);

	if (idFile != NULL) {
		return idFile;
	}
	else {
		return NULL;
	}
}

void closeFile(fileID idFile) {
	if (idFile) {
		fclose(idFile);
		printf("Fichero cerrado correctamente\n");
	}
	else {
		printf("Error al cerrar el fichero\n");
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
		return -1;
	}
}

const int writeFile(fileID fileId, const char writeBuffer[]) {
	if (fileId) {
		const int result = fwrite(writeBuffer, sizeof(char), getStringSize(writeBuffer), fileId);

		return result;
	}
	else {
		return -1;
	}
}

int getStringSize(const char myStr[]) {
	int size = 0;
	while (*(myStr++) != '\0') {
		size++;
	}

	return size;
}