﻿#include "stdafx.h"
#include "Jpg.h"

int CJpg::SetJpgFile(const char *pszJpgFile)
{
	printf("Lectura del fichero comprimido JPG\n");
	UncompressImage();
	return 0;
}

int CJpg::UncompressImage()
{
	printf("Descompresion de Imagen JPG\n");
	m_uResX = 800;
	m_uResY = 600;
	m_uColorBytes = 4;
	m_uSize = m_uResX * m_uResY * m_uColorBytes;
	m_pBuffer = new unsigned char[m_uSize];
	strcpy_s(reinterpret_cast<char *>(m_pBuffer), m_uSize, "Bytes del buffer descomprimido desde JPG");
	return 0;
}