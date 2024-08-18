#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main(int argc, char* argv[])
{
    double numbers[ARSIZE];
    double value;
    const char * file = "numbers.dat";
    int i;
    long pos;
    FILE* iofile;
    
    if (argc < 2) 
    {
        fprintf(stderr, "Please, add indexes to the command line after program name");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i<ARSIZE; i++)
        numbers[i] = 100.0*i+1.0/(i+1);
    if ((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Can't open file %s for output stream. M~M\n");
        exit(EXIT_FAILURE);
    }
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    if ((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "Can't open file %s for an arbitrary reading access. m_m\n", file);
        exit(EXIT_FAILURE);
    }

    printf("Enter enter indexes from 0 to $d.\n", ARSIZE);
    for (int i = 1; i<argc; i++)
    {
        static int num;
        num = atoi(argv[i]);
        fprintf(stdout, "%d ", num);
        if (num<0 || num>(ARSIZE-1))
        {
            fprintf(stderr, "Index no. %d is ignored. Reason: out of index");
            exit(EXIT_FAILURE);
        }
        pos = (long) num * sizeof(double);
        fseek(iofile, pos, SEEK_SET);
        fread(&value, sizeof(double), 1, iofile);
        fprintf(stdout, "By the index no. %d lies %lf value.\n", i, value);
    }
    fclose(iofile);
    fprintf(stdout, "Program has ended it's work succesfully.\n");
    return 0;
}