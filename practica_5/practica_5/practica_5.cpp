// pr5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IOManage.h"

int main()
{
	const char fileName[] = { "myFile.txt" };
	const char mode[] = "w";

	fileID idFile = openFile(fileName, mode);
	if (idFile) {
		printf("Fichero abierto\n");
	}
	else {
		printf("Error en la apertura de fichero\n");
	}

	const char buffWrite[] = "Soy Aragorn, hijo de Arathorn, heredero de Isildur";
	const int numCharactersW = writeFile(idFile, buffWrite);
	
	if (numCharactersW != -1) {
		printf("El texto completo es '%s'\n", buffWrite);
		printf("Numero de caracteres escritos = %d\n", numCharactersW);
	}
	else {
		printf("Identificador de fichero erróneo\n");
	}

	closeFile(idFile);

	const char mode2[] = "r";
	fileID idFile2 = openFile(fileName, mode2);
	if (idFile2) {
		printf("Fichero abierto\n");
	}
	else {
		printf("Error en la apertura de fichero 2\n");
	}

	const int charsToRead = 10;
	char *buffRead = new char[charsToRead + 1];
	const int numCharactersR = readFile(idFile, charsToRead, buffRead);

	if (numCharactersR != -1) {
		printf("Numero de caracteres leidos = %d y el texto leido es '%s'\n", numCharactersR, buffRead);
	}
	else {
		printf("Identificador de fichero erróneo\n");
	}

	delete[]buffRead;

	closeFile(idFile);
	printf("Fichero cerrado\n");

	return 0;
}

