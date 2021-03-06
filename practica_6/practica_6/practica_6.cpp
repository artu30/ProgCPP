// practica_6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringUtilities.h"
#include "IOManage.h"

int main()
{
	const char fileName[] = { "mifichero.txt" };
	const char mode[] = "r";

	const char *strToSearch = "adios";

	fileID myFileID = openFile(fileName, mode);

	if (myFileID) {
		printf("Fichero 1 abierto\n");
	}
	else {
		printf("Error en la apertura de fichero\n");
	}

	int apparitions = getStrApparitions(myFileID, strToSearch);

	closeFile(myFileID);

	printf("La cadena %s aparece %d veces\n", strToSearch, apparitions);

	const char fileName2[] = { "mifichero2.txt" };

	fileID myFileID2 = openFile(fileName2, mode);

	if (myFileID2) {
		printf("Fichero 2 abierto\n");
	}
	else {
		printf("Error en la apertura de fichero\n");
	}

	signed int intCounter = getStrCounter(myFileID2);

	closeFile(myFileID2);

	printf("El valor acumulado es %d\n", intCounter);

	return 0;
}

