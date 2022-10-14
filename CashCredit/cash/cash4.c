#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_cents();
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents -= quarters * quarter;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents -= dimes * dime;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents -= nickels * nickel;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents -= pennies * penny;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("Total: %i coins.\n", coins);
}

int get_cents()
{
    int dollar;
    do
    dollar = get_int("Cents: ");
    while (dollar <= 0);
    return dollar;
}

int calculate_quarters(int cents)
{
    return cents / quarter;
}

int calculate_dimes(int cents)
{
    return cents / dime;
}

int calculate_nickels(int cents)
{
    return cents / nickel;
}

int calculate_pennies(int cents)
{
    return cents / penny;
}
