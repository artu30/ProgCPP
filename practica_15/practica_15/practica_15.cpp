// practica_15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IOStreams.h"

int main() {
	// P - ¿Cuánto espacio ocupa la tabla de funciones virtuales?

	// R - Ocupará tanto espacio como funciones virtuales tenga por el tamaño del puntero en esa
	// arquitectura


	// P - ¿Donde está situada la tabla de funciones virtuales?

	// R - Está situada en memoria, apuntada por un puntero que se coloca al inicio en la 
	// instanciación de una clase derivada para acceder a su tabla de funciones virtuales.


	// P - ¿Cuánto espacio ocupa adicionalmente un objeto por tener una tabla de funciones virtuales?
	IStream *pFileExampleSize = new CFile();
	// R - Ocupa el tamaño de un puntero que depende de la arquitectura del procesador mas lo que 
	// ya ocupase de por si la propia clase instanciada


	// P - ¿Qué pasa si llamo a un método virtual desde el constructor ?
	IStream *pFileExampleCrash = new CFile();
	// R - Que el constructor que se llama primero al instanciar una clase derivaba es el constructor
	// y para llamar al constructor de la clase derivada es necesario que el objeto este creado, por lo 
	// tanto no tiene siquiera constancia de la existencia de ninguna tabla de funciones virtuales


	// P - Comparar la llamada a una función virtual con la llamada a una función no virtual. 
	// ¿Cuántos pasos adicionales tienen que realizarse para llamar a una función cuando esta es virtual?
	CFile f;
	f.Open("fichero", IStream::EMode_Read);

	IStream *pFileExample = new CFile();
	IStream *pointer;
	pointer = pFileExample;
	int id1 = pointer->Open("fichero ficticio", IStream::EMode_Read);
	// La llamada a la funcion en el primer caso es directa, en el segundo caso, debe acceder a la tabla de
	// funciones virtuales mediante su puntero para devolver la referencia a dicha funcion y poder llamarla
	// con el tipo adecuado, hace dos pasos más (va a por la dirección en la tabla, y la devuelve)

	delete[]pFileExampleSize;
	delete[]pFileExampleCrash;
	delete[]pFileExample;

	return 0;
}

