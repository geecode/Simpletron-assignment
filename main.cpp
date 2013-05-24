// Simpletron.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Simpletron.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	Simpletron computer;
	computer.enter_instructions();
	computer.execute_program();
	computer.print_dump();

	system( "pause" );
	return 0;
}



	

