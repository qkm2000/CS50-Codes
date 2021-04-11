#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get the user's name
    string name = get_string("What is your name? ");
    
    //print a greeting to the user, with the user's name
    printf("hello, %s!\n", name);
}
