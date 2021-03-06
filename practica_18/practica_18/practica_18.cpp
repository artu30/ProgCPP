// practica_18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IntList.h"
#include "StringList.h"
#include "TList.h"

int main() {
	TList list;

	IntList *integerList = new IntList(10);
	StringList *stringList = new StringList("Gerald");
	StringList *stringList2 = new StringList("Ciri");
	StringList *stringList3 = new StringList("Triss");
	StringList *stringList4 = new StringList("Jaskier");
	IntList *integerList2 = new IntList(20);
	
	list.push(integerList);
	list.push(stringList);
	list.push(stringList2);
	list.push(stringList3);
	list.push(stringList4);
	list.push(integerList2);

	printf("Todos los elementos\n");
	while (IAlmacenable * element = list.next()) {
		element->printVar();
	}

	list.pop();

	printf("Eliminando el primer elemento\n");
	while (IAlmacenable * element = list.next()) {
		element->printVar();
	}

    return 0;
}

