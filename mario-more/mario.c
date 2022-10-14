#include <stdio.h>
#include <cs50.h>

int n;

int main(void)
{
    //dobi user input
    do
        n = get_int("height: ");
    while (n <= 0 || n > 8);
    //naredi vrstico(dodaj novo vrsto)
    for (int i = 0; i < n; i++)
    {
        //dodaj potrebne presledke
        for (int j = (n - 2); j >= i; j--)
        {
            printf(" ");
        }
        // natisni število #
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        //presledek med piramidama
        printf("  ");
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}