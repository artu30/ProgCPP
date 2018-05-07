#include "Imagen.h"

class CPng : public CImagen {
public:
	int SetPngFile(const char *pszFile);
	int removeAlphaChanel();
private:
	int UncompressImage();
};