#include <stdio.h>
#include <cs50.h>

int only_positive(void); 

int main(void)
{
    int n = only_positive(); // This shall capture positive results between 1 to 8

    for (int i = 0; i < n; i++) 
    {

        for (int k = i + 1; k < n ; k++) // Loop to add spaces
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++) //Loop to add #s
        {

            printf("#");
        }

        printf("\n");
    }

}

int only_positive(void)
{
    int v; 
    do
    {
        v = get_int("Height\n");  //Input for the height
        
    }
    while (v < 1 || v > 8); // condition to get results between 1 to 8
    return v;
}