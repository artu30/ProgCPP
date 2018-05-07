#include "stdafx.h"
#include "TFile.h"

TFile::TFile() {
	m_file = nullptr;
}

TFile::~TFile() {
	if (m_file) {
		closeFile();
	}
	delete[]m_file;
	m_file = nullptr;
}

const int TFile::openFile(const char *file, const char *mode) {
	if (file) {
		fopen_s(&m_file, file, mode);

		if (m_file != NULL) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return -1;
	}
}

void TFile::closeFile() {
	if (m_file) {
		fclose(m_file);
		m_file = nullptr;
	}
}

const int TFile::readFile(unsigned const int numCharacters, char *readBuffer) {
	if (m_file) {
		rewind(m_file);
		fseek(m_file, 0, SEEK_END);
		long lSize = ftell(m_file);
		rewind(m_file);

		const int result = fread(readBuffer, sizeof(char), numCharacters, m_file);

		*(readBuffer + numCharacters) = '\0';

		return result;
	}
	else {
		return -1;
	}
}

const int TFile::writeFile(const char writeBuffer[], int bufferSize) {
	if (m_file) {
		if (bufferSize == 0) {
			bufferSize = getStringSize(writeBuffer);
		}

		const int result = fwrite(writeBuffer, sizeof(char), bufferSize, m_file);

		return result;
	}
	else {
		return -1;
	}
}

const int TFile::getStringSize(const char myStr[]) {
	int size = 0;
	while (*(myStr++) != '\0') {
		size++;
	}

	return size;
}