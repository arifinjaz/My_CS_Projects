#include <cs50.h>
#include <stdio.h>
#include <math.h>

float only_positive(void); 

int main(void)

{
    float dollar = only_positive(); // This shall capture positive float number.
    int cent = round(dollar * 100); // This shall convert float into interger i.e. dollar to cent in this concept.
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int t = 0; // to count number of transaction

    
    // This loop shall first validate the quarters for the input. 
    // If the inpur is greater than quarters.it shall substract 25p till the remainder in lerr than 25p
    
    while (cent >= quarters) 

    {
        cent = (cent - quarters);
        t++;
    }

    while (cent >= dimes) // The loop will be activated once the value of cent is <25p.
    {
        cent = (cent - dimes);
        t++;
    }

    while (cent >= nickels) // The loop will be activated once the value of cent is <10p.
    {
        cent = (cent - nickels);
        t++;
    }
    
    while (cent >= pennies) // The loop will be activated once the value of cent is <5p.
    {
        cent = (cent - pennies);
        t++;
    }
    
    printf("%i \n", t);   
}


float only_positive(void)
{
    float v;
    do
    {
        v = get_float("Change owed: \n");
    }
    while (v < 0.00);
    return v;
}