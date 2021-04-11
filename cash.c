#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    
    // obtaining the amount owed
    do 
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    
    // converting dollars to cents
    int cents = round(dollars * 100);

    int coins = 0;
    while (cents != 0)
    {
        // check if the value is more than 25
        // if yes, minus 25, and add one coin
        if (cents - 25 >= 0)
        {
            cents = cents - 25;
            coins = coins + 1;
            continue;
        }
        
        // check if the value is more than 10
        // if yes, minus 10, and add one coin
        if (cents - 10 >= 0)
        {
            cents = cents - 10;
            coins = coins + 1;
            continue;
        }
        
        // check if the value is more than 5
        // if yes, minus 5, and add one coin
        if (cents - 5 >= 0)
        {
            cents = cents - 5;
            coins = coins + 1;
            continue;
        }
        
        // check if the value is more than 1
        // if yes, minus 1, and add one coin
        if (cents - 1 >= 0)
        {
            cents = cents - 1;
            coins = coins + 1;
            continue;
        }
    }
    
    // print the number of coins
    printf("%i", coins);
}
