#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int limits[] = {10, 50, 100, 500, 1000, 5000, 10000, 100000};

    srand(time(NULL));

    FILE *f = fopen("randomNums.csv", "w");


        for(int i = 0; i < 1000; ++ i)
        {
            int r = rand() % 100;

            fprintf(f, "%d,", r);
        }
        fprintf(f, "\n\n");
    fclose(f);

    return 0;
}