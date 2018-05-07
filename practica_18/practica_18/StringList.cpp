#include "stdafx.h"
#include "StringList.h"

StringList::StringList(const char * text) {
	str = text;
}

StringList::~StringList() {
	delete str;
	str = nullptr;
}

void StringList::printVar() const {
	printf("Cadena: %s\n", str);
}
