// Class declaration for Simpletron virtual computer

class Simpletron
{
public:
	Simpletron();  // default constructor
	void enter_instructions();
	void set_instruction_register();
	void set_operation_code();
	void set_operand();
	void execute_program();
	void print_dump();
	int get_instruction();
	int get_operation_code();
	int get_operand();
	int load_accumulator( );
	static const int SIZE = 1000;
	static const int READ = 10;
	static const int WRITE = 11;
	static const int LOAD = 20;
	static const int STORE = 21;
	static const int ADD = 30;
	static const int SUBTRACT = 31;
	static const int DIVIDE = 32;
	static const int MULTIPLY = 33;
	static const int MODULUS = 34;
	static const int BRANCH = 40;
	static const int BRANCHNEG = 41;
	static const int BRANCHZERO = 42;
	static const int HALT = 43;
	
private:
	int accumulator;  // accumulator register
	int instruction_counter; // memory location of current instruction
	int instruction_register; //
	int instruction;
	int operation_code; //
	int operand; //
	int memory[ SIZE ];
	int *p_memory;
};


