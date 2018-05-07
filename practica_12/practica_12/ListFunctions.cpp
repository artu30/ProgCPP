#include "stdafx.h"
#include "TList.h"
#include "ListFunctions.h"

TList GetReverseList(TList lstSrc) {
	TList inverseList;

	const int listSize = lstSrc.getSize() - 1;

	for (int i = listSize; i >= 0; --i) {
		inverseList.push(lstSrc.getList()[i]);
	}

	return inverseList;
}

TList* GetReverseList2(const TList &lstSrc) {
	TList *inverseList = new TList();

	const int listSize = lstSrc.getSize() - 1;

	for (int i = listSize; i >= 0; --i) {
		inverseList->push(lstSrc.getList()[i]);
	}

	return inverseList;
}