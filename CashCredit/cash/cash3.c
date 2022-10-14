#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_cents();
int calculate_coins(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int coins = calculate_coins(cents);

    // Print total number of coins to give the customer
    printf("Total: %i coins.\n", coins);
}

int get_cents()
{
    int dollar;
    do
    dollar = get_int("Cents: ");
    while (dollar < 0);
    return dollar;
}

int calculate_coins(int cents)
{
    int quarters;
    int dimes;
    int nickels;
    int pennies;
    quarters = cents / 25;
    cents -= quarters * 25;
    dimes = cents / 10;
    cents -= dimes * 10;
    nickels = cents / 5;
    cents -= nickels * 5;
    pennies = cents / 1;
    return quarters + dimes + nickels + pennies;
}

