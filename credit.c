#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long number = get_long("Enter the card number \n");
    long temp = number; // to copy number, shall be used later in the code for calculations.
    long temp1 = number;
    int b = 0; // To store values for digits not in for multiplication
    int d = 0; 
    int e = 0; // To store sum values for digits with multipiications.
    int digits = 0;


    while (temp > 0) // This loop shall first validate the card using Luhn’s Algorithm
    {
        for (int i = 0; i < 1; i++) 
        {
            int a = temp % 10; // to get remainder
            b = b + a; // B stores the sum value of remaining digits.
            temp /= 10; // To knock the last number off
            d = 0;


            for (int j = 0; j < 1; j++)
            {
                int c = temp % 10; // to get remainder
                d = c * 2; // d store temp value of remainder * by 2
                temp /= 10; // To knock the last number off
            
                if (d > 9) // to add units if > than 2 digits
                {
                    int sumd, sumd1;
                    sumd = d % 10;
                    sumd1 = d / 10;
                    d = sumd + sumd1;
                }
                e = e + d; // e sums the value of d for every repeatation.
                 
                i = 0;
            }

        }
    
    }
    if ((b + e) % 10 == 0) // Final validation, Last digit should be 0.
    {
        while (temp1 > 0) // loop to calculate digits.
        {
            temp1 /= 10;
            digits ++;
        }
    
        if (digits == 16)
        {
            int card = number / 100000000000000; // to get the last 2 digits
            
            if ((card / 10) == 4)
            {
                printf("VISA\n");
            }
            else if (card == 51 || card == 52 || card == 53 || card == 54 || card == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
               
            }
            
        }    
            
        else if (digits == 13)
        {
            int card1 = number / 1000000000000; // to get the last digits
            if (card1 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
          
        else if (digits == 15)
        {
            int card2 = number / 10000000000000; // to get the last 2 digits
            if (card2 == 34 || card2 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
