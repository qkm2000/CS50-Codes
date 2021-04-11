#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get user input for 1<=height<=8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    // print the pyramid
    for (int i = 1 ; i < height + 1 ; i++)
    {
        // print first few spaces
        for (int j = 0 ; j < height - i ; j++)
        {
            printf(" ");
        }
        
        // print hexes
        for (int k = 0; k < i ; k++)
        {
            printf("#");
        }
        
        // print middle separator
        printf("  ");
        
        // print final hexes
        for (int l = 0 ; l < i ; l++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}
