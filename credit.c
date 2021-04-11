#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <cs50.h>

int validate(char array[CHAR_MAX]);


int main(void)
{
    // get card number
    long cardnum;
    do
    {
        cardnum = get_long("Number: ");
    }
    while (cardnum < 0);

    // making a new array to hold the string values of all the numbers
    char array[CHAR_MAX];
    
    // converting integer to string using sprintf
    sprintf(array, "%ld", cardnum);
    
    // check for valid card lengths
    if (strlen(array) != 13 && strlen(array) != 15 && strlen(array) != 16)
    {
        // invalid card number length
        printf("INVALID\n");
        return 0;
    }
    
    // validate card num, passing array of chars into validate
    int result = validate(array);
    
    // check checksum
    if (result != 0)
    {
        // invalid checksum
        printf("INVALID\n");
        return 0;
    }
    
    // check for company
    // check for num length 13 VISA
    if (strlen(array) == 13 && array[0] == '4')
    {
        printf("VISA\n");
        return 0;
    }
    
    // check for num length 15 AMEX
    else if (strlen(array) == 15 && array[0] == '3')
    {
        if (array[1] == '4' || array[1] == '7')
        {
            printf("AMEX\n");
            return 0;
        }
        
        else
        {
            printf("INVALID\n");
        }
    }
    
    // check for num length 16 VISA
    else if (strlen(array) == 16 && array[0] == '4')
    {
        printf("VISA\n");
        return 0;
    }
    
    // check for num length 16 MASTERCARD
    else if (strlen(array) == 16 && array[0] == '5')
    {
        char tempnum_str = array[1];
        int tempnum = atoi(&tempnum_str);
        if (0 < tempnum && tempnum < 6)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    else
    {
        printf("INVALID\n");
        return 0;
    }
    
}

int validate(char array[CHAR_MAX])
{
    // declaring all needed variables
    int total = 0;
    int to_multiply = 0;
    
    for (int i = strlen(array) - 1; i >= 0; i--)
    {
        // convert from string to int
        char tempnum_str = array[i];
        int tempnum = atoi(&tempnum_str);
        
        // no need to multiply
        if (to_multiply == 0)
        {
            total = total + tempnum;
            to_multiply = 1;
        }
        
        // need to multiply
        else
        {
            tempnum = tempnum * 2;
            char x2_arr[2];
            
            // converting the multiplied number to an array
            sprintf(x2_arr, "%d", tempnum);
            
            // multiplied number is 2 digits or more:
            if (strlen(x2_arr) >= 2)
            {
                // loop through and add both digits separately
                for (int j = 0; j < strlen(x2_arr); j++)
                {
                    char x2_chr = x2_arr[j];
                    int x2_int = atoi(&x2_chr);
                    total = total + x2_int;
                }
            }
            
            else
            {
                total = total + tempnum;
            }
            
            to_multiply = 0;
        }
    }
    
    
    return total % 10;
}
