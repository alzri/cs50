#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long n = number;
    int position = 0;
    int digits = 0;
    int sum = 0;

    while (n != 0)
    {
        int checksum = n % 10;

        if (position % 2 == 0)
        {
            sum += checksum;
        }
        else
        {
            int doubleNumber = checksum * 2;
            sum += (doubleNumber / 10) + (doubleNumber % 10);
        }

        n /= 10;
        position++;
        digits++;
    }

    bool luhn_valid = (sum % 10) == 0;
    long firstDigits = number;

    while (firstDigits >= 100)
    {
        firstDigits /= 10;
    }

    int firstTwo = (int) firstDigits;
    int firstOne = firstTwo / 10;

    if (luhn_valid && digits == 15 && (firstTwo == 34 || firstTwo == 37))
    {
        printf("AMEX\n");
    }
    else if (luhn_valid && digits == 16 && (firstTwo == 51 || firstTwo == 55 || firstTwo == 22))
    {
        printf("MASTERCARD\n");
    }
    else if (luhn_valid && (digits == 13 || digits == 16) && firstOne == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
