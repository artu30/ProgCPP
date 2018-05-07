#include "stdafx.h"
#include "IntList.h"

IntList::IntList(int n) { 
	mNumber = n;  
}

void IntList::printVar() const {
	printf("Entero: %d\n", mNumber); 
}