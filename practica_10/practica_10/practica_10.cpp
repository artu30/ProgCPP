// practica_10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TList.h"


int main()
{
	const char *list[] = { "Gerald", "Ciri", "Yennefer", "Triss Merigold", "Jaskier", "Dijkstra" };
	const int listSize = sizeof(list) / sizeof(*list);

	TList miLista (list, listSize);

	printf("La longitud de la lista es de %d\n", miLista.size());
	
	int newSize = miLista.push("Avalach");
	printf("La longitud de la lista tras incluir la cadena 'Avalach' es de %d\n", newSize);

	const char * firstElem = miLista.first();
	printf("El primer elemento es %s\n", firstElem);

	int count = 0;
	while (miLista.next() != NULL) {
		printf("El elemento en la posicion %d es %s\n", count, miLista.getList()[count]);
		count++;
	}

	const char * popElem = miLista.pop();
	printf("El elemento sacado es %s\n", popElem);
	printf("La longitud de la lista ahora es de %d\n", miLista.size());

	int count2 = 0;
	while (miLista.next() != NULL) {
		printf("El elemento en la posicion %d es %s\n", count2, miLista.getList()[count2]);
		count2++;
	}

	miLista.reset();

    return 0;
}

