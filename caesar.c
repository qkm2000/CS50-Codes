#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check for number of arguments
    if (argc != 2)
    {
        printf("Incorrect number of command-line arguments\n");
        return 1;
    }
    
    // check for key = int
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        // ascii numbers are from 48 to 57
        int tempnum = argv[1][i]; 
        if (48 > tempnum || tempnum > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    // obtaining the actual key number
    int key = atoi((argv[1]));
    key = key % 26;

    // get plaintext from user
    string s = get_string("plaintext: ");
    
    // print for display
    printf("ciphertext: ");

    // encrypting and printing characters
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // encrypt and print uppercase letters using the ascii table
        if (isupper(s[i]))
        {
            int char_num = ((int) s[i]) + key;
            if (char_num > 90)
            {
                char_num -= 26;
            }
            printf("%c", char_num);
        }
        
        // encrypt and print lowercase letters using the ascii table
        else if (islower(s[i]))
        {
            int char_num = ((int) s[i]) + key;
            if (char_num > 122)
            {
                char_num -= 26;
            }
            printf("%c", char_num);
        }
        
        // print special characters
        else
        {
            int char_num = ((int) s[i]);
            printf("%c", char_num);
        }
    }
    
    // print final newline character
    printf("\n");
}
