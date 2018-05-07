#include "stdafx.h"
#include "TList.h"

TList::TList(const char *list[], const int size) {
	Init(list, size);
}

TList::TList() {
	Init(nullptr, 0);
}

TList::~TList() {
	delete[]m_list;
	m_list = nullptr;
}

const char** TList::getList() {
	return m_list;
}

void TList::Init(const char *list[], const int size) {
	if (list) {
		m_list = new const char* [size];

		for (int i = 0; i < size; i++) {
			m_list[i] = list[i];
		}

		m_size = size;
		m_needle = 0;
	}
	else {
		m_list = nullptr;
		m_size = 0;
		m_needle = 0;
	}
}

int TList::size() {
	return m_size;
}

int TList::push(const char *psz) {
	if (psz) {
		const unsigned int oldSize = m_size;

		const unsigned int newSize = m_size + 1;

		const char **newList = new const char*[newSize];

		for (unsigned int i = 0; i < oldSize; i++) {
			newList[i] = getList()[i];
		}
		newList[newSize - 1] = psz;

		if (m_list != nullptr) {
			delete[] m_list;
		}

		m_list = newList;
		m_size = newSize;

		return m_size;
	}
	else {
		return m_size;
	}
}

const char *TList::first() {
	if (this) {
		return getList()[0];
	}
	else {
		return nullptr;
	}
}

const char * TList::next() {
	if (this) {
		if (m_needle < m_size) {
			const char* strToReturn = getList()[m_needle];
			m_needle++;
			return strToReturn;
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

const char * TList::pop() {
	const int newSize = m_size - 1;
	const char **newList = new const char*[newSize];

	const char *strToReturn = getList()[0];

	for (unsigned int i = 0; i < m_size - 1; i++) {
		newList[i] = this->getList()[i + 1];
	}

	if (m_list != nullptr) {
		delete[] m_list;
	}

	m_list = newList;
	m_size = newSize;

	return strToReturn;
}

void TList::reset() {
	delete[] m_list;
	m_list = nullptr;
	m_size = 0;
	m_needle = 0;
}


