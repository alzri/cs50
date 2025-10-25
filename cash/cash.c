#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    int quarters = change / 25;
    int quatresChange = quarters * 25;

    int dimes = (change - quatresChange) / 10;
    int dimesChange = dimes * 10;

    int nickels = (change - quatresChange - dimesChange) / 5;
    int nickelsChange = nickels * 5;

    int pennies = (change - quatresChange - dimesChange - nickelsChange) / 1;

    int sum = quarters + dimes + nickels + pennies;
    printf("%i\n", sum);
}
