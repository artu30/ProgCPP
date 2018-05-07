#include "stdafx.h"
#include "Png.h"

int CPng::SetPngFile(const char *pszPngFile)
{
	printf("Lectura del fichero comprimido Png\n");
	UncompressImage();
	return 0;
}

int CPng::UncompressImage()
{
	printf("Descompresion de Imagen Png\n");
	m_uResX = 480;
	m_uResY = 320;
	m_uColorBytes = 4;
	m_uSize = m_uResX * m_uResY * m_uColorBytes;
	m_pBuffer = new unsigned char[m_uSize];
	strcpy_s(reinterpret_cast<char *>(m_pBuffer), m_uSize, "Bytes del buffer descomprimido desde Png");
	return 0;
}

int CPng::removeAlphaChanel() {
	printf("Eliminacion del canal alpha de Imagen Png\n");
	
	int alphaPosition = 1;
	for (unsigned int i = 1; i <= m_uSize; i++) {
		if (alphaPosition == 4) {
			alphaPosition = 1;
			m_pBuffer[i - 1] = 0;
		}
		else {
			alphaPosition++;
		}
	}

	printf("Eliminacion correcta del canal alpha\n");
	
	return 0;
}