#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool is_dup(string s); // Function to check for duplicate values

int main(int argc, string argv[])
{
    if (argc == 2 && is_dup(argv[1]) == false) // validation for only 1 argument and no duplication
    {
        if (strlen(argv[1]) == 26) // Validation got 26 leters.
        {
            int l = strlen(argv[1]);
            char x [l]; // x will store the key in Capital.
            int co = 32;
            x[l] = '\0'; // this is to insure te string values return corrent amoutn.
            char y [l]; // y will store the key in lowercase.
            y[l] = '\0';
            for (int i = 0; i < l; i++) // Loop to insert 2 copy of the ley in x (upper case) y (lower case).
            {
                if (isupper(argv[1][i]))
                {
                    x[i] = (argv[1][i]);
                    y[i] = (argv[1][i] + co);
                }
                else if (islower(argv[1][i]))
                {
                    x[i] = (argv[1][i] - co);
                    y[i] = (argv[1][i]);
                }
                else
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }
            string pt = get_string("plaintext:");
            int a = strlen(pt);
            char ct[a];
            ct[a] = '\0';
            for (int i = 0; i < a; i++)
            {
                if (isupper(pt[i]))
                {
                    int te = pt[i] - 65; // -65 to get the proper index number from local variable in case of uppercase letter.
                    ct[i] = x[te];
                }
                else if (islower(pt[i]))
                {
                    int tes = pt[i] - 97;// -97 to get the proper index number from local variable in case of lowercase letter.
                    ct[i] = y[tes];
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
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    return 0;
}


bool is_dup(string s) 
{
    int p = -1, i, j;
    /*
    This loop should compare first letter of the string with every other letter to find duplication.
    If no duplication is found in the first letter it will switch to 2nd then 3rd etc depending upon string length.
    As soon as it find any duplicate, it shall stop and return true otherwise false.
    */
    for (i = 0; i < strlen(s); i++)
    {
        for (j = i + 1; j < strlen(s); j++) 
        {
            if (s[i] == s[j])
            {
                p = s[i];
            }
        }
    }

    if (p > -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}