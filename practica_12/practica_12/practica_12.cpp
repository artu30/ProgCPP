// practica_12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TList.h"
#include "ListFunctions.h"

int main()
{
	const char *list[] = { "Gerald", "Ciri", "Yennefer", "Triss Merigold", "Jaskier", "Dijkstra" };
	const int listSize = sizeof(list) / sizeof(*list);

	TList miLista(list, listSize);

	TList inverseList = GetReverseList(miLista);

	int count = 0;
	while (miLista.next() != NULL) {
		printf("El elemento de la lista normal en la posicion %d es %s\n", count, miLista.getList()[count]);
		count++;
	}

	int count2 = 0;
	while (inverseList.next() != NULL) {
		printf("El elemento de la lista invertida en la posicion %d es %s\n", count2, inverseList.getList()[count2]);
		count2++;
	}

	TList* inverseList2 = GetReverseList2(miLista);

	int count3 = 0;
	while (miLista.next() != NULL) {
		printf("El elemento de la lista normal en la posicion %d es %s\n", count3, miLista.getList()[count3]);
		count3++;
	}

	int count4 = 0;
	while (inverseList2->next() != NULL) {
		printf("El elemento de la lista invertida en la posicion %d es %s\n", count4, inverseList2->getList()[count4]);
		count4++;
	}

	miLista.reset();
	inverseList.reset();
	inverseList2->reset();

	delete[] inverseList2;

	return 0;
}

