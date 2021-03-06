// practica_14.cpp : Defines the entry point for the console application.
//

#include <vector>
#include "stdafx.h"
#include "Jpg.h"
#include "Png.h"

void PrintImageInfo(const CImagen &oImagen);

int main() {
	CPng *pPng = new CPng();
	CPng *pPng2 = new CPng();
	CJpg *pJpg = new CJpg;
	CJpg *pJpg2 = new CJpg;
	CPng *pPng3 = new CPng();

	pPng->SetPngFile("Fichero.png");
	pPng2->SetPngFile("Fichero.png");
	pJpg->SetJpgFile("Fichero.jpg");
	pJpg2->SetJpgFile("Fichero.jpg");
	pPng3->SetPngFile("Fichero.png");

	PrintImageInfo(*pPng);
	PrintImageInfo(*pJpg);
	
	CImagen* images[5] = { pPng, pPng2, pJpg, pJpg2, pPng3 };
	for (int i = 0; i < 5; i++) {
		CImagen *pImagen = images[i];
		CPng *pPng = dynamic_cast<CPng *>(pImagen);
		if (pPng) {
			pPng->removeAlphaChanel();
		}
	}

	return 0;
}

void PrintImageInfo(const CImagen &oImagen) {
	printf("NumPixels: %d \nSize: %d\n", oImagen.GetNumPixels(), oImagen.GetUncompressedSize());
}