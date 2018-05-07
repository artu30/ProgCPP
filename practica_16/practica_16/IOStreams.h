#pragma once
#include "stdafx.h"

struct IStream {
	enum TMode {
		EMode_Read,
		EMode_Write,
		Emode_ReadWrite
	};

	virtual int Open(const char *pszName, TMode nMode) = 0;
	virtual int Close(int iIdStream) = 0;
	virtual int Read(int iId, unsigned char *buffer, unsigned int uSize) = 0;
	virtual int Write(int iId, unsigned char *buffer, unsigned int uSize) = 0;
}; 

struct CFile : public IStream {
	int Open(const char *pszName, TMode nMode);
	int Close(int iIdStream);
	int Read(int iId, unsigned char *buffer, unsigned int uSize);
	int Write(int iId, unsigned char *buffer, unsigned int uSize);
};

struct CCom : public IStream {
	int Open(const char *pszName, TMode nMode);
	int Close(int iIdStream);
	int Read(int iId, unsigned char *buffer, unsigned int uSize);
	int Write(int iId, unsigned char *buffer, unsigned int uSize);
};

struct CTCP : public IStream {
	int Open(const char *pszName, TMode nMode);
	int Close(int iIdStream);
	int Read(int iId, unsigned char *buffer, unsigned int uSize);
	int Write(int iId, unsigned char *buffer, unsigned int uSize);
};