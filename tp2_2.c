#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 20

int main()
{
    int i;
    double vt[N];
    double *pvt = vt;
    for (i = 0; i < N; i++)
    {
        *pvt = 1 + rand() % 100;
        printf("%f", *pvt);
        pvt++;
        printf("\n");
    }
}
