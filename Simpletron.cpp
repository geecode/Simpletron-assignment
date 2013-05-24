// member function definitions for class Simpletron
#include "stdafx.h"
#include "Simpletron.h"
#include <iostream>
#include <iomanip>
using namespace std;

Simpletron::Simpletron()
{
	accumulator = 0;
	instruction_counter = 0;
	instruction_register = 0;
	operation_code = 0;
	operand = 0;
	
	for ( int m = 0; m < SIZE; ++m )
		memory[ m ] = 0;

	cout << "*** Welcome to Simpletron! ***\n\n";
	cout << "*** Please enter your program one instruction ***\n";
	cout << "*** (or data word) at a time. I will type the ***\n";
	cout << "*** location number and a question mark (?).  ***\n";
	cout << "*** You then type the word for that location. ***\n";
	cout << "*** Type the sentinel -99999 to stop entering ***\n";
	cout << "*** your program.                             ***\n\n";
}

void Simpletron::enter_instructions()
{
	while( instruction != -99999 ) {

		cout << setw( 2 ) << setfill( '0' ) << instruction_counter
			 << setw( 3 ) << " ? ";
		cin >> instruction;

		if ( -9999 <= instruction && instruction <= 9999 ) {
			memory[ instruction_counter ] = instruction;
			++instruction_counter;
		} else if ( instruction != -99999 ) {
			cout << "Please enter a 4 digit interger\n";
		} else {}
		
	} // end while
	cout << memory[ --instruction_counter ] << endl;
} // end function enter_instructions

void Simpletron::set_instruction_register()
{
	instruction_register = memory[ instruction_counter ];
}

void Simpletron::set_operation_code()
{
	operation_code = instruction_register / 100;
}

void Simpletron::set_operand()
{
	operand = instruction_register % 100;
} 

void Simpletron::execute_program()
{
	cout << "*** Program loading completed ***\n";
	cout << "***  Begin program execution  ***\n\n";
	instruction_counter = 0;
	for ( ; operation_code != 43; ++instruction_counter ) {
		set_instruction_register();
		set_operation_code();
		set_operand();
		switch ( operation_code )
		{
		case READ:
			cout << "? ";
			cin >> memory[ operand ];
			break;
		case WRITE:
			cout << memory[ operand ] << "\n\n";
			break;
		case LOAD:
			accumulator = memory[ operand ];
			break;
		case STORE:
			memory[ operand ] = accumulator;
			break;
		case ADD:
			if ( accumulator + memory[ operand ] <= 9999
				 && -9999 <= accumulator + memory[ operand ] ) {
			    accumulator += memory[ operand ];
				break;
			} else {
				cout << "***   x Fatal error!: accumulator overflow!    ***\n";
				cout << "*** Simpletron execution abnormally terminated ***\n";
				operation_code = 43;
				break;
			}
			break;
		case SUBTRACT:
			if ( 9999 >= accumulator - memory[ operand ]
   			     && -9999 <= accumulator - memory[ operand ] ) {
			    accumulator -= memory[ operand ];
				break;
			} else {
				cout << "***     Fatal error!: accumulator overflow!    ***\n";
				cout << "*** Simpletron execution abnormally terminated ***\n";
				operation_code = 43;
				break;
			}
		case DIVIDE:
			if ( memory[ operand ] && accumulator / memory[ operand ] <= 9999
				 && -9999 <= accumulator / memory[ operand ] ) {
				accumulator /= memory[ operand ];
				break;
			} else {
				cout << "***  Fatal error!: Attempt to divide by zero!  ***\n";
				cout << "*** Simpletron execution abnormally terminated ***\n";
				operation_code = 43;
				break;
			}
		case MULTIPLY:
			if ( 9999 >= accumulator * memory[ operand ]
			     && -9999 <= accumulator * memory[ operand ] ) {
			    accumulator *= memory[ operand ];
				break;
			} else {
				cout << "***     Fatal error!: accumulator overflow!    ***\n";
				cout << "*** Simpletron execution abnormally terminated ***\n";
				operation_code = 43;
				break;
			}
		case MODULUS:
			if ( memory[ operand ] && accumulator % memory[ operand ] <= 9999
				 && -9999 <= accumulator % memory[ operand ] ) {
				accumulator %= memory[ operand ];
				break;
			} else {
				cout << "***  Fatal error!: Attempt to divide by zero!  ***\n";
				cout << "*** Simpletron execution abnormally terminated ***\n";
				operation_code = 43;
				break;
			}
		case BRANCH:
			instruction_counter = operand;
			break;
		case BRANCHNEG:
			if ( accumulator < 0 ) {
				instruction_counter = operand;
				break;
			} else
				break;
		case BRANCHZERO:
			if ( !accumulator ) {
				instruction_counter = operand;
				break;
			} else
				break;
		case HALT:
			cout << "*** Simpletron execution terminated ***\n\n";
			break;
		default:
			cout << "*** Fatal error!: Illegal instruction encountered ***\n";
			cout << "***   Simpletron execution abnormally terminated  ***\n";
			operation_code = 43;
			break;
		} // end switch
	}// end for
} // end function

void Simpletron::print_dump()
{
	cout << setfill( ' ' );
	cout << setw( 22 ) << left << "REGISTERS:" << endl << endl;
	cout << setw( 22 ) << left << "accumulator"
		 << setw( 5 ) << showpos << setfill( '0' ) << internal 
		 << accumulator << endl;
	if ( instruction_counter < 10 ) {
		cout << setw( 22 ) << left << setfill( ' ' ) << "instruction_counter"
			 << setw( 4 ) << right << noshowpos   
			 << "0" << instruction_counter << endl;
	} else {
		cout << setw( 22 ) << left << setfill( ' ' ) << "instruction_counter"
			 << setw( 5 ) << right << noshowpos   
			 << instruction_counter << endl;
	}
	cout << setw( 22 ) << left << "instruction_register"
		 << setw( 5 ) << right << showpos << setfill( '0' ) << internal 
		 << instruction_register << endl;
	if ( operation_code < 10 ) {
		cout << setw( 22 ) << left << setfill( ' ' ) << "operation_code"
			 << setw( 4 ) << right << noshowpos //<< internal 
			 << '0' << operation_code << endl;
	} else {
		cout << setw( 22 ) << left << setfill( ' ' ) << "operation_code"
			 << setw( 5 ) << right << noshowpos //<< internal 
			 << operation_code << endl;
	}
	if ( operand < 10 ) {
		cout << setw( 22 ) << left << "operand"
			 << setw( 4 ) << right << noshowpos //<< internal 
			 << '0' << operand << endl << endl;
	} else {
		cout << setw( 22 ) << left << "operand"
			 << setw( 5 ) << right << noshowpos //<< internal 
			 << operand << endl << endl;
	}
	cout << "MEMORY:\n";
	cout << setw( 3 ) << " "; 
	for ( int k = 0; k < 10; ++k ) {
		cout << setw( 5 ) << right << k << " ";
	}
	cout << endl;
	for ( int i = 0; i < 100; ++i ) {
		if ( !i )
			cout << noshowpos << setw( 3 ) << i << " ";
		if ( i ) 
			cout << noshowpos << setfill( ' ' ) << setw( 3 ) << i * 10 << " ";
		for ( int j = 0; j < 10; ++j ) {
			
			cout << setw( 5 ) << right << showpos << setfill( '0' )
				 << internal << memory[ j +  ( i * 10 ) ] << " ";
			
			
		}
		cout << endl;
	} 
}

int Simpletron::get_instruction()
{
	return instruction_register;
}

int Simpletron::get_operation_code()
{
	return operation_code;
}

int Simpletron::get_operand()
{
	return operand;
}