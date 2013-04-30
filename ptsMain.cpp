//#include"stdafx.h"
#include "global.h"
#include "pts.yy.h"
#include "pts.tab.h"

//Delete with input and output 
int PtsMain(char *fileName)
{
	int result = 0;
	//char *inputFile = const_cast<char*>(fileName.c_str());
	char *inputFile = fileName;
	result = yyInitLexer(inputFile);
	result = yyparse();
	if(result != 0)
	{
		return 1;
	}
	result = yyCloseFile();
	if(result != 0)
	{
		return 2;
	}
	return 0;
}
