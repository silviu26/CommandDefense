#include "Week1Header.h"
#include <stdio.h>
#include <fstream>

int Sum(int a, int b) { return a + b; }
int Dif(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }

void ParseSources()
{
	char input[38] = "---H***E+++L+++L///O---P+++O/+-**O---";
	func Operatori[4] = {Sum, Dif, Mul, Div};
	int S=0, V;
    Content x = {0,0};
	int idx;

	for (int i = 0; i < strlen(input); i++)
	{
		switch (input[i] - 42)
		{
			case INMULTIRE:
				idx = 2;
				x.p1 = 3;
				x.p2 = 3;
                break;
			case SUMA:
				idx = 0;
				x.p1 = 7;
				x.p2 = 5;
                break;
			case DIFERENTA:
				idx = 1;
				x.p1 = 10;
				x.p2 = 1;
                break;
			case IMPARTIRE:
				idx = 3;
				x.p1 = 8;
				x.p2 = 4;
                break;
		}

		S = S + Operatori[idx](x.p1, x.p2);
	}

	//S=337
	printf("S = %d\n", S);
}

// Week 1 - using C API
void ReadTopScore()
{
    // open file "UserScores.txt"

    // read line by line: Name Points

    // print the name with biggest points

    // close file
    FILE* fis_in;
    char nume_cstigator[30];
    int scor_castigator=0;
    char buff[255];
    int scor;
    //fis_in = fopen("UserScores.txt", "w");
    fopen_s(&fis_in, "UserScores.txt", "r");
    if (fis_in != NULL)
    {
        while (fscanf_s(fis_in, "%s", buff, unsigned int( _countof(buff))) != -1)
        {
            fscanf_s(fis_in, "%d", &scor);
            if (scor > scor_castigator)
            {
                scor_castigator = scor;
                strcpy_s(nume_cstigator, buff);
            }
        }

        printf("%s", nume_cstigator);

        fclose(fis_in);
    }
    else
        printf("fisier inexistent");
}