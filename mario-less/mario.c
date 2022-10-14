#include <stdio.h>
#include <cs50.h>

int n;

int main(void)
{
    do
        n = get_int("height: ");
    while (n <= 0 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = (n - 2); j >= i; j--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}