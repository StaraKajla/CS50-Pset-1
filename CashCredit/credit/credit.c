#include <stdio.h>
#include <cs50.h>

bool checksum(long card);
void print_credit_card_brand(long card);
int find_length(long card);
bool check_validity(long card);

int main(void)
{
    long card;
    //Get Credit Card Number
    do
    {
    card = get_long("Card number: ");
    }
    while (card <= 0);

    //Check validity
    if (check_validity(card) == true)
    {
        print_credit_card_brand(card);
    }
    else
    printf("INVALID\n");
}

//Vrni T/F(bool)
bool check_validity(long card)
{
    int len = find_length(card);
    return ((len == 13 || len == 15 || len == 16) && checksum(card)); // (ni potrebe po IF stavku in potem return true, else false)
}

//izracun dolzine
int find_length(long card)
{
    int len;
    for (len = 0; card != 0; card /= 10, len++);
    return len;
}

bool checksum(long card) //Luhn's Algorithm
{
    int sum = 0;
    for(int i = 0; card != 0; i++, card /= 10) //za vsako iteracijo dokler CARD ni 0, zmanjšuj CARD za eno decimalno mesto (/10)
    {
        //ali je index deljiv z 2?
        if (i % 2 == 0)
            sum += card % 10;
        else
        {
            int digit = 2 * (card % 10);
            //digit can be > 10, split into two numbers
            sum += digit / 10 + digit % 10;
        }
    }
    //s tem preveri če je seštevek zadnjih dveh števil = 0
    return (sum % 10) == 0;
}

//void pomeni da funkcija ne vrne ničesar, se pa vseeno izvede
void print_credit_card_brand(long card)
{
    //1e9 pomeni številka 1 in 9 nicel -> 1 000 000 000
    if ((card >= 34e13 && card < 35e13) || (card >= 37e13 && card < 38e13))
        printf("AMEX\n");

    else if (card >= 51e14 && card <= 56e14)
        printf("MASTERCARD\n");

    else if ((card >= 4e12 && card < 5e12) || (card >= 4e15 && card < 5e15))
        printf("VISA\n");

    else
        printf("INVALID\n");
}