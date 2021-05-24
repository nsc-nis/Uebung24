#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//define constants
#define MAXLENGTH 255
#define PATH "/media/nsc/Daten_512GB/Projects/C_Projects/3BHIT_Uebung24_CSV/input/"

//********************************************************************
//
// Program        : Übung 24 - CSV
//
// Author         : Niklas Schachl
//
// Date           : 20.5.2021
//
// Description    : Program to give students in a CSV-file their grades
//
//********************************************************************

//declare variables


//declare functions
char* readLine(char* filename);

//main program
int main()
{
    //declare variables
    char* filename = malloc(2048);
    char* currentLine = "Hello";

    printf("***************************\n");
    printf("* Easy Student Grader 1.0 *\n");
    printf("***************************\n");

    printf("* Please type in the filename:\n");
    printf("./FILE/");
    fflush(stdin);
    //scanf("%s", &filename);
    gets(filename);
    printf("\n%s\n", filename);

    if(strstr(filename, ".csv") == NULL)
        printf("* [ERROR] Only .csv files are supported\n");
    else
        printf("* [OK] File read: %s\n", filename);

    printf("%s", readLine(filename));
}

char* readLine(char* filename)
{
    //declare variables
    FILE *fp;
    char* string = NULL;
    char* file = PATH;
    printf("\n%s\n", file);
    printf("\n%s\n", filename);

    //get path to file
    /*
    printf("\nstrcat\n");
    strcat(file, filename);
    printf("%s", file);
     */

    //open file
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("* [ERROR] Could not open file\n");
        return NULL;
    }
    else
        fgets(string, MAXLENGTH, fp);

    //return
    return string;
}
