#ifndef _PTS_YY_H_
#define _PTS_YY_H_ 
#include <fstream.h>
//#include <iostream>
#include <stdio.h>
#include <string.h>

//Call lex
int yylex();

//Initialization which file to read 
int yyInitLexer(char *file);

//Close file
int yyCloseFile();

#endif