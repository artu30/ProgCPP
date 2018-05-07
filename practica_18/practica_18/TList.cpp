#pragma once
#include "stdafx.h"
#include "TList.h"

TList::TList(const TList &copy) {
	m_list = new std::vector<IAlmacenable *>;
	m_needle = 0;

	int size = reinterpret_cast<std::vector<IAlmacenable *>*>(copy.m_list)->size();
	for (int i = 0; i < size; i++) {
		reinterpret_cast<std::vector<IAlmacenable *>*>(m_list)->push_back(reinterpret_cast<std::vector<IAlmacenable *>*>(copy.m_list)->at(i));
	}
}

TList::TList() {
	m_list = new std::vector<IAlmacenable*>;
	m_needle = 0;
}

TList::~TList() {
	delete[]m_list;
	m_list = nullptr;
}

int TList::size() {
	if (m_list) {
		return reinterpret_cast<std::vector<IAlmacenable*>*>(m_list)->size();
	}
	else {
		return 0;
	}
}

int TList::push(IAlmacenable *psz) {
	if (psz) {
		reinterpret_cast<std::vector<IAlmacenable *>*>(m_list)->push_back(psz);
		int listSize = size();
		return listSize;
	}
	else {
		int listSize = size();
		return listSize;
	}
}

IAlmacenable *TList::first() {
	if (this) {
		return reinterpret_cast<std::vector<IAlmacenable *>*>(m_list)->front();
	}
	else {
		return nullptr;
	}
}

IAlmacenable * TList::next() {
	if (this) {
		int listSize = size();
		if (m_needle < listSize) {
			int position = m_needle++;
			return reinterpret_cast<std::vector<IAlmacenable *>*>(m_list)->at(position);
		}
		else {
			m_needle = 0;
			return nullptr;
		}
	}
	else {
		return nullptr;
	}
}

IAlmacenable * TList::pop() {
	IAlmacenable *valueToReturn = this->first();

	std::vector<IAlmacenable *>::iterator it = reinterpret_cast<std::vector<IAlmacenable *>*>(m_list)->begin();
	reinterpret_cast<std::vector<IAlmacenable *>*>(m_list)->erase(it);

	m_needle = 0;

	return valueToReturn;
}

void TList::reset() {
	delete[] m_list;
	m_list = nullptr;
	m_needle = 0;
}


