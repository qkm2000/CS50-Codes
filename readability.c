#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

int main(void)
{
    // get user input, treat string as an array, where every letter is one place
    string input = get_string("Text: ");

    // total number of words, sentences and letters
    int num_words = 1, num_sentences = 0, num_letters = 0; 
    
    // at a space, add one to num_words
    // at a fullstop, add one to num_sentences
    // at every letter, add one to num_letters
    
    int convo = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        //printf("%c\n", input[i]);
        
        // uppercase letter
        if (65 <= (int) input[i] && (int) input[i] <= 90)
        {
            num_letters = num_letters + 1;
        }
        
        // lowercase letter
        else if (97 <= (int) input[i] && (int) input[i] <= 122)
        {
            num_letters = num_letters + 1;
        }
        
        // space
        else if ((int) input[i] == 32)
        {
            num_words = num_words + 1;
        }
        
        // end of sentence, for eg. fullstop, exclamation mark etc
        else if ((int) input[i] == 46 || (int) input[i] == 33 || (int) input[i] == 63)
        {
            num_sentences = num_sentences + 1;
        }
    } 
    
    // calculating the Coleman-Liau index
    float L = ((float) num_letters / num_words) * 100.0;
    float S = ((float) num_sentences / num_words) * 100.0;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    // printing the results
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
