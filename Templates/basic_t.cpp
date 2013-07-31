#include <iostream>
#include <string>
#include "temp.h"

int main(int argc, char* argv[]){
	if (argc > 4) {
		double a = atof(argv[1]);
		double b = atof(argv[2]);
		long d = atol(argv[3]);
		long e = atol(argv[4]);

		swap(a, b);

		std::cout << "Swapped values: " << a << " and " << b << std::endl;

		std::cout << "swapped values: " << d << " and " << e << std::endl;
	}

	return 0;
}