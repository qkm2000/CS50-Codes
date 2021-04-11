#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// ASCII numbers for each alphabet in small letters and capital letters
int small_letters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
int capital_letters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};

// Prototypes
int compute_score(string word);

// Main code
int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    
    // Player 1 win
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    
    // Player 2 win
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    
    // Tie
    else
    {
        printf("Tie!\n");
    }
    
}

// Defining prototype
int compute_score(string word)
{
    // Initialise the score
    int score = 0;
    
    // Iterate through all letters and process them
    for (int i = 0; i < strlen(word); i++)
    {
        // If uppercase letter, go through the ASCII numbers to compare and locate the letter
        // Then add the respective score at the respective positions 
        if (isupper(word[i]))
        {
            for (int j = 0; j < sizeof(POINTS); j++)
            {
                if (word[i] == capital_letters[j])
                {
                    score = score + POINTS[j];
                }
            }
        }
        
        // If lowercase letter, go through the ASCII numbers to compare and locate the letter
        // Then add the respective score at the respective positions
        if (islower(word[i]))
        {
            for (int j = 0; j < sizeof(POINTS); j++)
            {
                if (word[i] == small_letters[j])
                {
                    score = score + POINTS[j];
                }
            } 
        }
    }
    return score;
}
