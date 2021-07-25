#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string words);
int count_words(string words);
int count_sentense(string sentense);

int main(void)
{
    string text = get_string("TEXT: ");
    int letters = count_letters(text);  // to get the count of letters from the function.
    int words = count_words(text);      // to get the count of Words from the function.
    int sentense = count_sentense(text);// to get the count of Sentense from the function.

    //printf("letters:%i\nwords:%i\nsentense:%i\n",letters,words,sentense);
    
    float L = ((float)letters / words) * 100; // L is the average number of letters per 100 words.

    float S = ((float) sentense / words) * 100; // S is the average number of sentences per 100 words.

    float index = 0.0588 * L - 0.296 * S - 15.8; // Coleman-Liau index.

    if (index > 1 && index < 16)
    {
        printf("Grade %.f\n", round(index));
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
}







int count_sentense(string sentense)
{
    int digit = strlen(sentense);
    int count = 0;

    for (int i = 0; i < digit; i++)
    {

        if (sentense[i] == '.' || sentense[i] == '!' || sentense[i] == '?') // condition to check sentense.
        {
            count ++;
        }
    }
    return count;
}



int count_words(string words)
{
    int digit = strlen(words);
    int count = 1;

    for (int i = 0; i < digit; i++)
    {

        if (words[i] == ' ' && words[i + 1] != ' ') // condition to check word i.e. an alphabet after space.
        {
            count ++;
        }
    }

    return count;
}



int count_letters(string letters)
{
    int digit = strlen(letters);
    int count = 0;
    for (int i = 0; i < digit; i++)
    {
        if (isalpha(letters[i]) > 0) // Condition to check letter i.e. any alphabet.
        {
            count ++;
        }
    }

    return count;
}