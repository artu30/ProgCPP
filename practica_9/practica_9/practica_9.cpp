// practica_9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TFile.h"


int main()
{
	const char fileName[] = { "myFile.txt" };
	const char mode[] = "w";

	TFile myFileObject;

	const int openReturn = myFileObject.openFile(fileName, mode);
	if (openReturn) {
		printf("Fichero abierto\n");
	}
	else {
		printf("Error en la apertura de fichero\n");
	}

	const char buffWrite[] = "Soy Aragorn, hijo de Arathorn, heredero de Isildur";
	const int numCharactersW = myFileObject.writeFile(buffWrite);

	printf("El texto completo es '%s'\n", buffWrite);
	printf("Numero de caracteres escritos = %d\n", numCharactersW);

	myFileObject.closeFile();
	printf("Fichero cerrado\n");

	const char mode2[] = "r";
	const int openReturn2 = myFileObject.openFile(fileName, mode2);
	if (openReturn2) {
		printf("Fichero abierto\n");
	}
	else {
		printf("Error en la apertura de fichero\n");
	}

	const int charsToRead = 10;
	char *buffRead = new char[charsToRead + 1];
	const int numCharactersR = myFileObject.readFile(charsToRead, buffRead);

	printf("Numero de caracteres leidos = %d y el texto leido es '%s'\n", numCharactersR, buffRead);

	delete[]buffRead;

	myFileObject.closeFile();
	printf("Fichero cerrado\n");

	return 0;
}

