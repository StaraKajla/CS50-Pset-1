#include <stdio.h>
#include <cs50.h>

int height;

int main(void)
{
    do
    {
        height = get_int("height: ");
    }
    while (height < 1 || height > 8);

    for(int i = 0; i < height; i++)
    {
        for(int j = height; (j - 1) > i; j--)
        {
            printf(" ");
        }
        for(int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}