#include <stdlib.h>
#include <stdio.h>
#include "XString.h"

int main(int argc, char **argv)
{
    unsigned char *Main = "Hello";
    unsigned char *txt1 = "erfsdgsd sgsdfgd ergerg ergerge";
    unsigned char *Example = "__Hello_Jesus, Hello_World\nWorld";
    unsigned char *txt = "__Hello_Jesus\nWorld\nfrom\nI am your father\nWelcome to\nFuck the\nSociety";
    unsigned char *h1 = "Hello";
    unsigned char *h2 = " World!";
    unsigned char *St = "12345";
    unsigned char l = '6';
    unsigned char Up = 'H';
    unsigned char Low = 'h';

    printf("%s :before append\n", St);
    printf("%s :after append\n", AppendLetter(St, l));
    printf("%s :new Text\n", AppendWord(h1, h2));
    printf("%d :Lenght\n", TxtLen(St, '\0'));
    printf("%d :Lenght\n", TxtLen(h1, '\0'));
    printf("%d :Num of Lines\n", numLines(txt));
    printf("%d :Num of Lines\n", numLines(h1));
    printf("%s :normal\n", h1);
    printf("%s :Upper\n", toUpperCaseWord(h1));
    printf("%s :low\n", toLowerCaseWord(h1));
    printf("----------------------------\n");
    CompareStrings(Main, h1);
    printf("----------------------------\n");
    LinesAddress(txt);
    printf("the word %s is %d in %s", txt1, FindWord(txt1, Main, '\0'), Main);
    printf("----------------------------\n");
    getAfterW(1, 0, Example, "o_Je", '\n');
    // printf("The pattern was %s", (RegexFind("/[A-Z]{12}/", Main,'\0') == 1u ? "found" : "not found") );

    // int i;
    // int total = 100;
    // for (i = 0; i <= total; i++) {
    //     printf("Progress: [");
    //     int j;
    //     for (j = 0; j < i; j++) {
    //         printf(".");
    //     }
    //     for (j = i; j < total; j++) {
    //         printf(" ");
    //     }
    //     printf("] %d%%\r", i);
    //     fflush(stdout);
    //     usleep(100000);
    //     printf("\033");
    // }
    // printf("\n");

    return 0;
}