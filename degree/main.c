/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include "degree.h"

int main()
{
    int c_degree = 28;
    int f_degree = 85;
    
    printf("%d° celcius is equal to %d° fahrenheit\n", c_degree, cel_to_far(c_degree));
    printf("%d° fahrenheit is equal to %d° celcius\n", f_degree, far_to_cel(f_degree));

    return 0;
}
