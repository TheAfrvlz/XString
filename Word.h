#ifndef STRINGIFY_H_INCLUDED
#define STRINGIFY_H_INCLUDED

#include <stdlib.h>
#include "Word.c"

typedef unsigned char boolean;

#define True (boolean)1u
#define False (boolean)0u


int Texlen(unsigned char* StringC,char StopC);
void LinesAddress(unsigned char* MainS);
unsigned char* AppendW(unsigned char* StringC1, unsigned char* StringC2);
unsigned char* AppendL(unsigned char* StringC, char C);
int numLines(unsigned char* MainS);
unsigned char* toUpperCaseW(unsigned char* StringC);
char toUpperCaseL(char C);

unsigned char* toLowerCaseW(unsigned char* StringC);
char toLowerCaseL(char C);

void CompareStringW(unsigned char* StringRef, unsigned char* String2C);
void ClearT(unsigned char* StringC);
boolean Findchar(char C, unsigned char* StringC);
boolean FindString(unsigned char* Origin, unsigned char* toFind);
boolean FindSymbol(char S, unsigned char* StringC);
void ReplaceW(char *OriginString, char *toReplace, char *newS);
// void DeleteSpace(char *StringC, char StopC);
// unsigned char *getAfterSymbol(char *StartAddC, char S, char StopC);
// unsigned char *getBeforeSymbol(char *StartAddC, char S, char StopC);
// unsigned char *getAfterchar(char *StartAddC, char L, char StopC);
// unsigned char *getBeforechar(char *StartAddC, char L, char StopC);
// unsigned char *getAfterW(char *StartAddC, char StringC, char StopC);
// unsigned char *getBeforeW(char *StartAddC, char StringC, char StopC);
// unsigned char *getBeforeLine(int line);
// unsigned char *getAfterLine(int line);
// unsigned char *getLine(int line);
// unsigned char *getBetweenSymbol(char *StartAddC,char *symbol);
// void ShiftLeftString(char *lineAdd, int len, char *String2Shift);
// void ShiftRightString(char *lineAdd, int len, char *String2Shift);
// int W2I(unsigned char*Ref);
// unsigned char* I2W(int Var);
#endif