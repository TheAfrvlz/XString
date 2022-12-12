#include "Word.h"

typedef unsigned char boolean;


int*LinePos;

int Texlen(unsigned char* StringC, char StopC){
    int len = 0;
    while (*(StringC + len) != StopC)
    {
        len++;
    }
    // printf("%d \n",len);
    return len;
}
void LinesAddress(unsigned char* MainS){

    int Size = 1;
    int len = 0;

    LinePos = (int*) calloc(1,sizeof(int));
    LinePos[0]= 0;
    while (*(MainS + len) != '\0'){

        if (*(MainS + len) == '\n'){
            Size++;
            printf("Dim of Size: %d\n",Size);
            LinePos = (int*) realloc(LinePos, Size * sizeof(int));
            LinePos[Size-1] = len+1;
        }
        len++;
    }
    printf("After\n");

    // printf("%c content - %d Addres\n",*(MainS + p[0]),(MainS + p[0]));
    // printf("%c content - %d Addres\n",*(MainS + p[1]),(MainS + p[1]));
    // printf("%c content - %d Addres\n",*(MainS + p[2]),(MainS + p[2]));
    // printf("%c content - %d Addres\n",*(MainS + p[3]),(MainS + p[3]));


    for (int i = 0; i < Size; i++){
        printf("%c content - %d Address, location in : %d\n",*(MainS + LinePos[i]),(MainS + LinePos[i]),LinePos[i]);
    }
    
}
int numLines(unsigned char* MainS){
    int lin = 1;
    int len = 0;
    while (*(MainS + len) != '\0')
    {
        if (*(MainS + len) == '\n')
        {
            lin++;
        }
        len++;
    }

    return lin;
}
unsigned char* AppendL(unsigned char* StringC, char C){

    int StrLng = Texlen(StringC,'\0');
    int size = StrLng + 1;

    char *buffer = (char *)calloc(size, sizeof(char));

    for (int i = 0; i < StrLng; i++)
        buffer[i] = StringC[i];

    buffer[StrLng] = C;

    buffer[size] = '\0';

    printf("%c char added:\n", buffer[StrLng]);

    return buffer;
}
unsigned char* AppendW(unsigned char* StringC1, unsigned char* StringC2)
{

    int StrLng = Texlen(StringC1,'\0');
    int StrLng1 = Texlen(StringC2,'\0');
    int size = StrLng + 1 + StrLng1;

    char *buffer = (char *)calloc(size, sizeof(char));

    for (int i = 0; i < StrLng; i++)
        buffer[i] = StringC1[i];

    for (int i = 0; i < StrLng1; i++)
        buffer[i + StrLng] = StringC2[i];

    buffer[size] = '\0';

    return buffer;
}
unsigned char* toUpperCaseW(unsigned char* StringC){
    // 97 // 122
    int len = 0;
    int StrLng = Texlen(StringC,'\0');
    char *buffer = (char *)calloc(StrLng, sizeof(char));

    int size = StrLng;
    while (*(StringC + len) != '\0')
    {
        if ((*(StringC + len) >= 'a' && *(StringC + len) <= 'z') || (*(StringC + len) >= 'A' && *(StringC + len) <= 'Z'))
        {
            if ((*(StringC + len) >= 'a' && *(StringC + len) <= 'z'))
            {
                *(buffer + len) = *(StringC + len) - 32;
            }
            else
            {
                *(buffer + len) = *(StringC + len);
            }
        }

        len += 1;
    }
    return buffer;
}
unsigned char* toLowerCaseW(unsigned char* StringC){
    // 97 // 122
    int len = 0;
    int StrLng = Texlen(StringC,'\0');
    char *buffer = (char *)calloc(StrLng, sizeof(char));

    int size = StrLng;
    while (*(StringC + len) != '\0')
    {
        if ((*(StringC + len) >= 'a' && *(StringC + len) <= 'z') || (*(StringC + len) >= 'A' && *(StringC + len) <= 'Z'))
        {
            if ((*(StringC + len) >= 'A' && *(StringC + len) <= 'Z'))
            {
                *(buffer + len) = *(StringC + len) + 32;
            }
            else
            {
                *(buffer + len) = *(StringC + len);
            }
        }

        len += 1;
    }
    return buffer;
}
char toUpperCaseL(char C){
    // 97 // 122
    char buffer;

    if ((C >= 'a' && C <= 'z') || (C >= 'A' && C <= 'Z'))
    {
        if ((C >= 'a' && C <= 'z'))
        {
            buffer = C - 32;
        }
    }
    return buffer;
}
char toLowerCaseL(char C){
    // 97 // 122
    char buffer;
    if ((C >= 'a' && C <= 'z') || (C >= 'A' && C <= 'Z'))
    {
        if ((C >= 'A') && (C <= 'Z'))
        {
            buffer = C + 32;
        }
    }
    return buffer;
}
void CompareStringW(unsigned char* StringRef, unsigned char* String2C){
    int len = 0;
    int StLen = Texlen(StringRef,'\0');
    while (len < StLen){

        if(*(StringRef + len) == *(String2C+len)){
            len++;
        }
        else{
            printf("Not Same\n");
            break;
        }
    }
}
void ClearT(unsigned char* StringC){
    free(StringC);
}

boolean Findchar(char C, unsigned char* StringC){    boolean buffer = 0u;
    int len = 0;
    while (*(StringC + len) != '\0')
    {
        if (*(StringC + len) == C)
        {
            buffer = 1u;
            break;
        }
        else
        {
            len++;
        }
    }

    return buffer;
}

boolean FindString(unsigned char* Origin,unsigned char* toFind){
    boolean buffer = 0u;
    int len = 0;
    while (*(Origin + len) != '\0')
    {
        if (*(Origin + len) == *(toFind + 0))
        {
            buffer = 1u;
            break;
        }
        else
        {
            len++;
        }
    }

    return buffer;
}

boolean FindSymbol(char S, unsigned char* StringC){
    boolean buffer = 0u;
    int len = 0;
    while (*(StringC + len) != '\0')
    {
        if (*(StringC + len) == S)
        {
            buffer = 1u;
            break;
        }
        else
        {
            len++;
        }
    }

    return buffer;
}
void ReplaceW(char *OriginString, char *toReplace, char *newS){
    int len = 0;
    int OriginLen;
    char *NewOrigin;
    
    while (*(OriginString + len) != '\0')
    {
        if (*(OriginString + len) == *(toReplace + 0)){
            
        }else
        {
            len++;
        }
    }

    OriginLen = Texlen(OriginLen,'\0') + Texlen(newS,'\0') - 1 - Texlen(toReplace,' ') -1; 

}
// TODO

// void DeleteSpace(char *StringC, char StopC){
//     while (*(StringC) != StopC)
//     {

//     }
// }
// unsigned char* getAfterSymbol(char *StartAddC, char S, char StopC){
//      unsigned char Var = ' ';
//     return &Var;
// }
// unsigned char* getBeforeSymbol(char *StartAddC, char S, char StopC){
//      unsigned char Var = ' ';
//     return &Var;
// }
// unsigned char* getAfterchar(char *StartAddC, char L, char StopC){
//      unsigned char Var = ' ';
//     return &Var;
// }
// unsigned char* getBeforechar(char *StartAddC, char L, char StopC){
//     unsigned char Var = ' ';
//     return &Var;
// }
// unsigned char* getAfterW(char *StartAddC, char StringC, char StopC){
//      unsigned char Var = ' ';
//     return &Var;
// }
// unsigned char* getBeforeW(char *StartAddC, char StringC, char StopC){
//      unsigned char Var = ' ';
//     return &Var;
// }
// unsigned char* getBeforeLine(int line){
//      unsigned char Var = ' ';
//     return &Var;
// }
// unsigned char* getAfterLine(int line){
//      unsigned char Var = ' ';
//     return &Var;
// }
// unsigned char* getLine(int line){
//      unsigned char Var = ' ';
//     return &Var;
// }
// unsigned char* getBetweenSymbols(char *StartAddC,char *symbol){
//  unsigned char Var = ' ';
//     return &Var;
// }
// void ShiftLeftString(char *lineAdd, int len, char *String2Shift){
// }
// void ShiftRightString(char *lineAdd, int len, char *String2Shift){
// }
// int W2I(unsigned char* Ref){
//     return 0;
// }

// unsigned char* I2W(int Var){
//     unsigned char Var = ' ';
//     return &Var;
// }