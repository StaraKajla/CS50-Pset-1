#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollar;
    int coins = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0, dollarnum = 0, cents = 0;

    do
    {
        dollar = get_float("Enter amount: ");
    }
    while (dollar <= 0);

    cents = dollar * 100;

    while (cents >= 100)
    {
        cents -= 100;
        dollarnum += 1;
    }

    while (cents >= 25)
    {
        cents -= 25;
        quarters += 1;
        coins += 1;
    }

    while (cents >= 10)
    {
        cents -= 10;
        dimes += 1;
        coins += 1;
    }

    while (cents >= 5)
    {
        cents -= 5;
        nickels += 1;
        coins += 1;
    }

    while (cents > 1)
    {
        cents -= 1;
        pennies += 1;
        coins += 1;
    }

    printf("Total amount to return is %0.2f$.\n", dollar);
    printf("Return %i dollars, %i quarters, %i dimes, %i nickels and %i pennies. Total coins: %i\n",
           dollarnum, quarters, dimes, nickels, pennies, coins);
}