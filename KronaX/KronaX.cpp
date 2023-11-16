// KronaX.cpp : Defines the entry point for the application.
//

#include "KronaX.h"
#include "Global/CLI.hpp"

using namespace std;//I Don't care, Krona SOP allows and encourages this in .cpp files.

int main(int argc, char**argv, char**argz)
{
	if (!ParseCLI(argc, argv, argz)) {
		printf("Build stopped\r\n");
	}

	
	return 0;
}
