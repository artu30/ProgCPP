#include "stdafx.h"
#include "IONamespace.h"
#include "TList.h"
#include "stringsNamespace.h"

void StringNamespace::getIntegerListFromFile(fileID fileId, TList& list) {
	if (fileId) {
		rewind(fileId);
		fseek(fileId, 0, SEEK_END);
		long lSize = ftell(fileId);
		rewind(fileId);

		int pieces = static_cast<int>(lSize / 256);
		int lastPiece = lSize % 256;

		signed int acumulate = 0;
		char *myNumber;

		for (int j = 1; j <= pieces; j++) {
			myNumber = new char[256];
			char* context = NULL;
			fgets(myNumber, 256, fileId);
			const char * pch;
			pch = strtok_s(myNumber, ",", &context);
			while (pch != NULL) {
				list.push(pch);
				pch = strtok_s(NULL, ",", &context);
			}
		}
		if (lastPiece > 0) {
			myNumber = new char[lastPiece];
			char* context = NULL;
			fgets(myNumber, lastPiece, fileId);
			const char * pch;
			pch = strtok_s(myNumber, ",", &context);
			while (pch != NULL) {
				list.push(pch);
				pch = strtok_s(NULL, ",", &context);
			}
		}

		myNumber = nullptr;
	}
}