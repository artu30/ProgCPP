// practica_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void printRecursiveIncludes(const char* file, int level);

int main() {
	char* myFile = "Includes.cpp";
	printRecursiveIncludes(myFile, 0);

    return 0;
}

void printRecursiveIncludes(const char* file, int level) {
	ifstream myfile(file);
	string line;
	if (myfile) {
		while (getline(myfile, line)) {
			
		}
		myfile.close();
	}
}