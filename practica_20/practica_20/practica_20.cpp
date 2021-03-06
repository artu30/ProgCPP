// practica_20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
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
	int m_life;
	funcEntity *m_funcs;
	TEntity(funcEntity *funcs, int x, int y)
	{
		m_life = rand() % 51;
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;
	}
};

void pinta1(TEntity *p) {
	//printf("++++");
}

void pinta2(TEntity *p) {
	//printf("----");
}

void pinta3(TEntity *p) {
	//printf("::::");
}

void pinta4(TEntity *p) {
	//printf("()()()()");
}

void pinta5(TEntity *p) {
	//printf("------>>");
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

	//gotoxy(static_cast<short>(p->m_ix), static_cast<short>(p->m_iy));
}

void mover2(TEntity *p) {
	if (p->m_ix == 50) {
		p->m_ix = 10;
	}
	else {
		p->m_ix += 10;
	}

	//gotoxy(static_cast<short>(p->m_ix), static_cast<short>(p->m_iy));
}

void mover3(TEntity *p) {
	if (p->m_iy == 50) {
		p->m_iy = 10;
	}
	else {
		p->m_iy += 10;
	}

	//gotoxy(static_cast<short>(p->m_ix), static_cast<short>(p->m_iy));
}

void mover4(TEntity *p) {
	if (p->m_ix == 50) {
		p->m_ix = 0;
	}
	else {
		p->m_ix += 10;
	}

	//gotoxy(static_cast<short>(p->m_ix), static_cast<short>(p->m_iy));
}

void mover5(TEntity *p) {
	if (p->m_ix == 60) {
		p->m_ix = 0;
	}
	else {
		p->m_ix += 10;
	}

	//gotoxy(static_cast<short>(p->m_ix), static_cast<short>(p->m_iy));
}

unsigned int uKey;
int main() {
	std::list<TEntity> myEntities;

	funcEntity tFuncs1[2] = { &pinta1, &mover1 };
	TEntity t1(tFuncs1, 10, 10);

	funcEntity tFuncs2[2] = { &pinta2, &mover2 };
	TEntity t2(tFuncs2, 10, 30);

	funcEntity tFuncs3[2] = { &pinta3, &mover3 };
	TEntity t3(tFuncs3, 10, 10);

	funcEntity tFuncs4[2] = { &pinta4, &mover4 };
	TEntity t4(tFuncs4, 10, 50);

	funcEntity tFuncs5[2] = { &pinta5, &mover5 };
	TEntity t5(tFuncs5, 10, 50);

	funcEntity* myFunctions[5] = { tFuncs1 ,tFuncs2 ,tFuncs3 ,tFuncs4 ,tFuncs5 };

	myEntities.push_back(t1);
	myEntities.push_back(t2);
	myEntities.push_back(t3);
	myEntities.push_back(t4);
	myEntities.push_back(t5);

	while (true) {
		clear();

		for (auto it = myEntities.begin(); it != myEntities.end();) {
			it->m_life--;
			if (it->m_life <= 0) {
				printf("Se elimina la entidad\n");
				it = myEntities.erase(it);
			}
			else {
				printf("Vida de la entidad -> %d\n", it->m_life);
				TEntity *eAux = &(*it);
				it->m_funcs[1](eAux);
				it->m_funcs[0](eAux);
				++it;
			}
		}

		if (myEntities.size() < 5) {
			int newEntities = 5 - myEntities.size();

			for (int i = 0; i < newEntities; i++) {
				int randomFuncts = rand() % 5;

				TEntity t(myFunctions[randomFuncts], 10, 10);
				printf("Se crea una nueva entidad\n");
				myEntities.push_back(t);
			}
		}

		Sleep(1000);
	}

	for (auto it = myEntities.begin(); it != myEntities.end();) {
		it = myEntities.erase(it);
	}

    return 0;
}

