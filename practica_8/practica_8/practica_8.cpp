// pr5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IONamespace.h"
#include "stringsNamespace.h"

int main()
{
	/* --------------------------------------------------------------------------------------------- */
	/* --------------------------------------- Practica 5 ------------------------------------------ */
	/* --------------------------------------------------------------------------------------------- */

	const char fileName[] = { "myFile.txt" };
	const char mode[] = "w";

	fileID idFile = IONamespace::openFile(fileName, mode);
	if (idFile) {
		printf("Fichero abierto\n");
	}
	else {
		printf("Error en la apertura de fichero\n");
	}

	const char buffWrite[] = "Soy Aragorn, hijo de Arathorn, heredero de Isildur";
	const int numCharactersW = IONamespace::writeFile(idFile, buffWrite);

	printf("El texto completo es '%s'\n", buffWrite);
	printf("Numero de caracteres escritos = %d\n", numCharactersW);

	IONamespace::closeFile(idFile);
	printf("Fichero cerrado\n");

	const char mode2[] = "r";
	fileID idFile2 = IONamespace::openFile(fileName, mode2);
	if (idFile2) {
		printf("Fichero abierto\n");
	}
	else {
		printf("Error en la apertura de fichero 2\n");
	}

	const int charsToRead = 10;
	char *buffRead = new char[charsToRead + 1];
	const int numCharactersR = IONamespace::readFile(idFile, charsToRead, buffRead);

	printf("Numero de caracteres leidos = %d y el texto leido es '%s'\n", numCharactersR, buffRead);

	delete[]buffRead;

	IONamespace::closeFile(idFile);
	printf("Fichero cerrado\n");

	/* --------------------------------------------------------------------------------------------- */
	/* --------------------------------------- Practica 6 ------------------------------------------ */
	/* --------------------------------------------------------------------------------------------- */

	const char fileName2[] = { "mifichero.txt" };
	const char mode3[] = "r";

	const char *strToSearch = "adios";

	fileID myFileID = IONamespace::openFile(fileName2, mode3);

	if (myFileID) {
		printf("Fichero 1 abierto\n");
	}
	else {
		printf("Error en la apertura de fichero 1\n");
	}

	int apparitions = stringNamespace::getStrApparitions(myFileID, strToSearch);

	printf("La cadena %s aparece %d veces\n", strToSearch, apparitions);

	const char fileName3[] = { "mifichero2.txt" };

	fileID myFileID2 = IONamespace::openFile(fileName3, mode3);

	if (myFileID2) {
		printf("Fichero 2 abierto\n");
	}
	else {
		printf("Error en la apertura de fichero 2\n");
	}

	signed int intCounter = stringNamespace::getStrCounter(myFileID2);

	printf("El valor acumulado es %d\n", intCounter);

	return 0;
}

