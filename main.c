#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
char* writeLine(char* string);

//main program
int main()
{
    //declare variables
    char* inputFilename = malloc(2048);
    char* inputFile = malloc(MAXLENGTH * 2);
    char* outputFilename = malloc(2048);
    char* outputFile = malloc(MAXLENGTH * 2);
    char* currentLine = malloc(MAXLENGTH + 1);
    bool isRunning = true;
    bool isError = true;

    inputFile = PATH;
    outputFile = PATH;

    //logo
    printf("***************************\n");
    printf("* Easy Student Grader 1.0 *\n");
    printf("***************************\n");

    printf("* Please type in the filename of the input file:\n");
    while(isError)
    {
        //Get name of input file
        printf("./FILE/INPUT/");
        fflush(stdin);
        //scanf("%s", &inputFilename);
        gets(inputFilename);

        //add inputFilename to path of input folder
        //strcat(inputFile, inputFilename); --> Funktioniert nicht


        //check if input file is a csv-File
        if (strstr(inputFilename, ".csv") == NULL)
            printf("* [ERROR] Only .csv files are supported\n");
        else
        {
            isError = false;
            printf("* [OK] File read: %s\n", inputFilename);
        }
    }

    //Get name of output file
    printf("* Please type in the filename of the output file:\n");
    printf("./FILE/OUTPUT/");
    fflush(stdin);
    //scanf("%s", &inputFilename);
    gets(outputFilename);

    //strcat(outputFile, outputFilename); --> Funktioniert nicht
    printf("* [OK] Output file created\n");

    //Create output file, open file stream
    FILE *out;
    out = fopen(outputFilename, "w");

    //Read input file, open file stream
    FILE *fp;
    fp = fopen(inputFilename, "r");

    printf("* Start grading your students with numbers from 1 to 5\n* Students who have no grade can get the number -1\n* Type in 0 to exit the program\n");

    while (currentLine != NULL && isRunning) //Die Schleife wird nie beendet, auch nicht wenn ich currentLine != EOF mache :(
    {
        char* name = malloc(MAXLENGTH + 1);
        char* br = "\n";
        char* cm = ",";
        int grade = 0;

        if(fp == NULL)
        {
            printf("* [ERROR] Could not open file\n");
            break;
        }
        else
            fgets(currentLine, MAXLENGTH + 1, fp);

        int count = 0;
        for (int i = 0; i < strlen(currentLine); ++i)
        {
            if(currentLine[i] != br[0])
                name[i] = currentLine[i];
        }

        bool isError = true;
        while(isError)
        {
            printf("./GRADE/%s/", name);
            fflush(stdin);
            scanf("%d", &grade);

            if(grade == 0)
            {
                //Damit die Schleife nach dem letzten Schüler auch beendet wird, ansonsten wird der letzte Schüler einfach immer wieder angezeigt
                //ich hab vieles probiert um das Problem zu lösen, hat alles nicht funktioniert :(
                //z.B. hab ich versucht immer die letzte Zeile zu speichern und wenn die neue die selbe wie die alte ist aufzuhören. Das hat nicht funktioniert
                printf("* [BREAK] \n");
                //currentLine = NULL;
                isRunning = false;
                break;
            }
            else if(grade < -1 || grade > 5)
                printf("* [ERROR] Only numbers from 1 to 5, -1 and 0 are possible inputs\n");
            else
                isError = false;
        }
        if(grade != 0)
        {
            fprintf(out, "%s,%d\n", name, grade);
        }
    }
    if(fclose(out) == EOF)
        printf("* [ERROR] Could not save grades\n");
    else
        printf("* [OK] All grades saved to %s\n", outputFilename);
}
