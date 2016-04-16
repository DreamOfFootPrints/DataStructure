#include"PostfixExpression.h"


void Test1()
{
	Cell RPNArray[]=
	{
		{ OP_NUM, 12 },
		{ OP_NUM, 3 },
		{ OP_NUM, 4 },
		{ OP_SYMBOL, ADD },
		{ OP_SYMBOL, MUL },
		{OP_NUM,6},
		{OP_SYMBOL,SUB},
		{OP_NUM,8},
		{OP_NUM,2},
		{OP_SYMBOL,DIV},
		{OP_SYMBOL,ADD}
	};
	cout << RPNCount(RPNArray, sizeof(RPNArray) / sizeof(Cell)) << endl;
}

int main()
{
	Test1();
	system("pause");
	return 0;
}