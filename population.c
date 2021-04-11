#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    
    // Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    
    // Calculate number of years until we reach threshold
    int years = 0;
    int current_size = 0;
    current_size = start_size;
    while (current_size < end_size)
    {
        int dead = (float) current_size / 4;
        int born = (float) current_size / 3;
        current_size = current_size + born - dead;
        years = years + 1;
    }
    
    // Print number of years
    printf("Years: %i\n", years);
}
