//============================================================================
// Name        : workshop.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "crc32.h"
using namespace std;

int main() {

	char data[] = "testing crc32";
	u32 mycrc = CRC32( (const void*)data, sizeof(data) );

	cout << "crc32 sum of \""<< data <<  "\": " << mycrc << endl; // prints !!!Hello World!!!
	return 0;
}
