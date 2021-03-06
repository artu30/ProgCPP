// pr4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "consola.h"

struct TEntity;
typedef void(*funcEntity)(TEntity *);

// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	int m_ix;
	int m_iy;
	funcEntity *m_funcs;
	TEntity(funcEntity *funcs, int x, int y)
	{
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;
	}
};

void pinta1(TEntity *p) {
	printf("++++");
}

void pinta2(TEntity *p) {
	printf("----");
}

void pinta3(TEntity *p) {
	printf("::::");
}

void pinta4(TEntity *p) {
	printf("()()()()");
}

void mover1(TEntity *p) {
	if (p->m_ix == 50) {
		p->m_ix = 10;
		p->m_iy = 10;
	}
	else {
		p->m_ix += 10;
		p->m_iy += 10;
	}

	gotoxy(static_cast<short>(p->m_ix), static_cast<short>(p->m_iy));
}

void mover2(TEntity *p) {
	if (p->m_ix == 50) {
		p->m_ix = 10;
	}
	else {
		p->m_ix += 10;
	}

	gotoxy(static_cast<short>(p->m_ix), static_cast<short>(p->m_iy));
}

void mover3(TEntity *p) {
	if (p->m_iy == 50) {
		p->m_iy = 10;
	}
	else {
		p->m_iy += 10;
	}

	gotoxy(static_cast<short>(p->m_ix), static_cast<short>(p->m_iy));
}

void mover4(TEntity *p) {
	if (p->m_ix == 50) {
		p->m_ix = 0;
	}
	else {
		p->m_ix += 10;
	}

	gotoxy(static_cast<short>(p->m_ix), static_cast<short>(p->m_iy));
}

// ***************************************************************************************
// MAIN
// ***************************************************************************************
unsigned int uKey;
int main(int argc, char* argv[]) {
	funcEntity tFuncs1[2] = { &pinta1, &mover1 };
	TEntity *t1 = new TEntity(tFuncs1, 10, 10);

	funcEntity tFuncs2[2] = { &pinta2, &mover2 };
	TEntity *t2 = new TEntity(tFuncs2, 10, 30);

	funcEntity tFuncs3[2] = { &pinta3, &mover3 };
	TEntity *t3 = new TEntity(tFuncs3, 10, 10);

	funcEntity tFuncs4[2] = { &pinta4, &mover4 };
	TEntity *t4 = new TEntity(tFuncs4, 10, 50);

	TEntity *tableEntity[] = { t1, t2, t3, t4 };

	while (true) {
		clear();
		for (int i = 0; i < 4; i++) {
			TEntity *auxEntity = tableEntity[i];
			auxEntity->m_funcs[1](auxEntity);
			auxEntity->m_funcs[0](auxEntity);
		}
		Sleep(1000);
	}

	delete[]t1;
	delete[]t2;
	delete[]t3;
	delete[]t4;

	return 0;
}



