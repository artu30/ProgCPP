#include "stdafx.h"
#include "TList.h"
#include "IONamespace.h"
#include "stringsNamespace.h"

int main() {
	fileID myFileID = IONamespace::openFile("mifichero2.txt", "r");
	
	TList integerList;
	StringNamespace::getIntegerListFromFile(myFileID, integerList);

	IONamespace::closeFile(myFileID);
	printf("Fichero cerrado\n");

	int count = 0;
	while (integerList.next() != NULL) {
		printf("El entero en la posicion %d es %s\n", count, integerList.getList()[count]);
		count++;
	}

	return 0;
}