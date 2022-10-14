#include <cs50.h>
#include <stdio.h>

unsigned long long CC_num;
int num1, num2, num3, num4, num5, num6, num7, num8;
int num9, num10, num11, num12, num13, num14, num15, num16;
int mastercard, amex, visa1, visa2;
int sum1, sum2, sum3;
int main(void)
{
//Prompt card input
do
CC_num = get_long_long("Number: ");
while(CC_num < 0);

//Get every odd number from right to left and multiply by 2
num1 = ((CC_num % 100) / 10) * 2;
num2 = ((CC_num % 10000) / 1000) * 2;
num3 = ((CC_num % 1000000) / 100000) * 2;
num4 = ((CC_num % 100000000) / 10000000) * 2;
num5 = ((CC_num % 10000000000) / 1000000000) * 2;
num6 = ((CC_num % 1000000000000) / 100000000000) * 2;
num7 = ((CC_num % 100000000000000) / 10000000000000) * 2;
num8 = ((CC_num % 10000000000000000) / 1000000000000000) * 2;

//Splice any sum > 10 (13 = 1 + 3)
num1 = (num1 % 10) + (num1 / 10);
num2 = (num2 % 10) + (num2 / 10);
num3 = (num3 % 10) + (num3 / 10);
num4 = (num4 % 10) + (num4 / 10);
num5 = (num5 % 10) + (num5 / 10);
num6 = (num6 % 10) + (num6 / 10);
num7 = (num7 % 10) + (num7 / 10);
num8 = (num8 % 10) + (num8 / 10);
sum1 = (num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8);

//Get every even number from right to left
num9 = (CC_num % 10) / 1;
num10 = (CC_num % 1000) / 100;
num11 = (CC_num % 100000) / 10000;
num12 = (CC_num % 10000000) / 1000000;
num13 = (CC_num % 1000000000) /100000000;
num14 = (CC_num % 100000000000) / 10000000000;
num15 = (CC_num % 10000000000000) / 1000000000000;
num16 = (CC_num % 1000000000000000) / 100000000000000;

//Sum multiplication from odd numbers and add to even numbers, CHECK VALIDITY: Last number == 0
sum2 = (sum1 + (num9 + num10 + num11 + num12 + num13 + num14 + num15 + num16)) % 10;


//Mastercard (Numbers: 16)
mastercard = CC_num / 100000000000000;

//Amex (Numbers: 15) Prve dve 34 || 37
amex = CC_num / 10000000000000;

//Visa (Numbers: 13)
visa1 = CC_num / 1000000000000000;

//Visa(Numbers: 16)
visa2 = CC_num / 1000000000000;

if (sum2 != 0)
{
    printf("INVALID\n");
    return 0;
}

//Check if MASTERCARD
else if (51 <= mastercard && mastercard <= 55)
printf("MASTERCARD\n");

//Check if AMEX
else if (amex == 34 || amex == 37)
printf("AMEX\n");

//Check if VISA
else if (visa1 == 4 || visa2 == 4)
printf("VISA\n");

//Numbers add up to 0 but don't belong to any card; Print INVALID and exit code
else
{
    printf("INVALID\n");
    return 0;
}

}
