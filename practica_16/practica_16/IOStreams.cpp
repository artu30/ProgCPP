#include "stdafx.h"
#include "IOStreams.h"

/* ------------------------------------------------ */
/* --------------------- FILE --------------------- */
/* ------------------------------------------------ */
int CFile::Open(const char *pszName, TMode nMode) {
	switch (nMode) {
		case EMode_Read:
			printf("Se abre el stream para un fichero con nombre %s en modo lectura\n", pszName);
			break;
		case EMode_Write:
			printf("Se abre el stream para un fichero con nombre %s en modo escritura\n", pszName);
			break;
		case Emode_ReadWrite:
			printf("Se abre el stream para un fichero con nombre %s en modo lectura y escritura\n", pszName);
			break;
	}

	return 1;
}
int CFile::Close(int iIdStream) {
	printf("Se cierra el stream para un fichero con identificador %d\n", iIdStream);

	return 0;
}
int CFile::Read(int iId, unsigned char *buffer, unsigned int uSize) {
	printf("Leemos el fichero con identificador %d y espacio de buffer %d\n", iId, uSize);

	return uSize;
}
int CFile::Write(int iId, unsigned char *buffer, unsigned int uSize) {
	printf("Escribimos el fichero con identificador %d y espacio de buffer %d\n", iId, uSize);

	return uSize;
}

/* ------------------------------------------------ */
/* --------------------- COM ---------------------- */
/* ------------------------------------------------ */
int CCom::Open(const char *pszName, TMode nMode) {
	switch (nMode) {
	case EMode_Read:
		printf("Se abre el stream para un puerto serie con nombre %s en modo lectura\n", pszName);
		break;
	case EMode_Write:
		printf("Se abre el stream para un puerto serie con nombre %s en modo escritura\n", pszName);
		break;
	case Emode_ReadWrite:
		printf("Se abre el stream para un puerto serie con nombre %s en modo lectura y escritura\n", pszName);
		break;
	}

	return 2;
}
int CCom::Close(int iIdStream) {
	printf("Se cierra el stream para un puerto serie con identificador %d\n", iIdStream);

	return 0;
}
int CCom::Read(int iId, unsigned char *buffer, unsigned int uSize) {
	printf("Leemos el puerto serie con identificador %d y espacio de buffer %d\n", iId, uSize);

	return uSize;
}
int CCom::Write(int iId, unsigned char *buffer, unsigned int uSize) {
	printf("Escribimos el puerto serie con identificador %d y espacio de buffer %d\n", iId, uSize);

	return uSize;
}

/* ------------------------------------------------ */
/* --------------------- TCP ---------------------- */
/* ------------------------------------------------ */
int CTCP::Open(const char *pszName, TMode nMode) {
	switch (nMode) {
	case EMode_Read:
		printf("Se abre el stream para una conexion TC con nombre %s en modo lectura\n", pszName);
		break;
	case EMode_Write:
		printf("Se abre el stream para una conexion TC con nombre %s en modo escritura\n", pszName);
		break;
	case Emode_ReadWrite:
		printf("Se abre el stream para una conexion TC con nombre %s en modo lectura y escritura\n", pszName);
		break;
	}

	return 3;
}
int CTCP::Close(int iIdStream) {
	printf("Se cierra el stream para una conexion TC con identificador %d\n", iIdStream);

	return 0;
}
int CTCP::Read(int iId, unsigned char *buffer, unsigned int uSize) {
	printf("Leemos la conexion TC con identificador %d y espacio de buffer %d\n", iId, uSize);

	return uSize;
}
int CTCP::Write(int iId, unsigned char *buffer, unsigned int uSize) {
	printf("Escribimos la conexion TC con identificador %d y espacio de buffer %d\n", iId, uSize);

	return uSize;
}