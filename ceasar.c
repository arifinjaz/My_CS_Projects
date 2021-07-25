#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int s = strlen(argv[1]); // to get the length of input.
        char key[s]; // to get the number in string
        
        
        for (int i = 0; i < s; i++)
        {
            if (isdigit(argv[1][i])) // Validation for digit
            {
                key[i] = (argv[1][i]); // inserting digits to string
            }
            else // exit if input was not digit
            {
                printf("Usage: ./caesar key\n"); 
                exit(1);
            }
        }
        
        int keys = atoi(key); // convert string to int.
        string pt = get_string("plaintext:"); // feed plian text
        int a = strlen(pt); // Charector of plain text.
        char ct[a]; 
        ct[a] = '\0'; // to compile char to string by difining this at the last index.

        for (int i = 0; i < a; i++)
        {
            if (isupper(pt[i]))
            {
                ct[i] =  ((((int)pt[i] - 'A') + keys) % 26) + 'A'; // Formula to right output.
            }
            else if (islower(pt[i]))
            {
                ct[i] = ((((int)pt[i] - 'a') + keys) % 26) + 'a';
            }
            else
            {
                ct[i] = pt[i];
            }
        }   
        printf("ciphertext:%s\n", ct);
    }
    else
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }
    return 0;
}