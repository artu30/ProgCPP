// practica_16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IOStreams.h"

int main() {
	unsigned char *buffer  = new unsigned char[256];
	unsigned char *buffer2 = new unsigned char[256];

	IStream *pFile = new CFile();
	IStream *pCom  = new CCom();
	IStream *pTCP  = new CTCP();

	IStream *p;

	/* ----------------------------------------------- */
	/* --------------------- FILE -------------------- */
	/* ----------------------------------------------- */
	p = pFile;

	int id1 = p->Open("fichero ficticio", IStream::EMode_Read);

	int elementsReaded = p->Read(id1, buffer, 256);

	int elementsWrited = p->Write(id1, buffer2, 256);

	int closeError = p->Close(id1);
	/* ----------------------------------------------- */

	/* ----------------------------------------------- */
	/* --------------------- COM --------------------- */
	/* ----------------------------------------------- */
	p = pCom;

	int id2 = p->Open("fichero ficticio", IStream::EMode_Read);

	int elementsReaded2 = p->Read(id2, buffer, 256);

	int elementsWrited2 = p->Write(id2, buffer2, 256);

	int closeError2 = p->Close(id2);
	/* ----------------------------------------------- */

	/* ----------------------------------------------- */
	/* --------------------- TCP --------------------- */
	/* ----------------------------------------------- */
	p = pTCP;

	int id3 = p->Open("fichero ficticio", IStream::EMode_Read);
	
	int elementsReaded3 = p->Read(id3, buffer, 256);

	int elementsWrited3 = p->Write(id3, buffer2, 256);

	int closeError3 = p->Close(id3);
	/* ----------------------------------------------- */

	delete[]buffer;
	delete[]buffer2;

	delete[]pFile;
	delete[]pCom;
	delete[]pTCP;

    return 0;
}

