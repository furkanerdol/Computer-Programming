/*############################################################################*/
/*HW00_Furkan_Erdol_131044065_part1.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on February 16, 2015                                */
/*Description                                                                 */
/*____________                                                                */
/*Takes the Integral of a given 1st degree polynomial                         */
/*Inputs:                                                                     */
/*  -Coefficients of the 1st degree polynomial                                */
/*  -Zero input value of the resulting polynomial                             */
/*Outputs:                                                                    */
/*   -Resulting 2nd degree polynomial                                         */
/*                                                                            */
/*............................................................................*/
/*                                 Includes                                   */
/*............................................................................*/
#include <stdio.h>

int main(void)
 {
    double ia1, ia2, /*coefficients of input polynomial*/
           ra1, ra2; /*coefficients of the resulting polynomial*/

    /*Get the 1st degree input polynomial*/
    printf("\nEnter the coefficients of the polynomial (from higher to lower"
            " order)\n\n");
    scanf("%lf%lf", &ia1, &ia2);

    /*Calculate the resulting polynomial*/
    ra1 = (0.5) * ia1;
    ra2 = ia2;

    /*Output the resulting polynomial*/
    /*C is the constant term of the resulting polynomial*/
    printf("\nThe resulting polynomial is %3.1f x^2 + %3.1f x + C\n", ra1, ra2);

    return 0;
}

/*############################################################################*/
/*                End of HW00_Furkan_Erdol_131044065_part1.c                  */
/*############################################################################*/
