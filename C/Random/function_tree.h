typedef char* string;

typedef struct f
{
	char type;
	void* content;

	struct f *opA;
	struct f *opB;
} Operation;

typedef struct d
{
	string fName;

	int varNum;
	char* varList;

	Operation op;
} Function;

int checkBrackets(string expression);