/*############################################################################*/
/*HW00_Furkan_Erdol_131044065_part2.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on February 16, 2015                                */
/*Description                                                                 */
/*____________                                                                */
/*Takes 2 polynomials of 2nd degree and outputs the multiplication of them    */
/*Inputs:                                                                     */
/*  -Coefficients of the 2nd degree two polynomials                           */
/*Outputs:                                                                    */
/*   -Resultng 4th degree polynomial                                          */
/*                                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>

int 
main(void)
{
	double ia1, ia2, ia3, /*coefficients of input first polynomial*/
           ib1, ib2, ib3, /*coefficients of input second polynomial*/
           ra1, ra2, ra3, ra4, ra5; /*coefficients of the resulting polynomial*/

    /*Get the 2nd degree input first polynomial*/
    printf("\nEnter the coefficients of the first polynomial (from higher to"
            " lower order)\n\n");
    scanf("%lf%lf%lf", &ia1, &ia2, &ia3);

    /*Get the 2nd degree input second polynomial*/
    printf("\nEnter the coefficients of the second polynomial (from higher to"
            " lower order)\n\n");
    scanf("%lf%lf%lf", &ib1, &ib2, &ib3);
    
    /*Calculate the resulting polynomial*/
    ra1 = ia1*ib1;
    ra2 = (ia1*ib2)+(ia2*ib1);
    ra3 = (ia1*ib3)+(ia2*ib2)+(ia3*ib1);
    ra4 = (ia2*ib3)+(ia3*ib2);
    ra5 = (ia3*ib3);

    /*Output the resulting polynom*/
    printf("\nThe resulting polynomial is %3.1f x^4 + %3.1f x^3 + %3.1f x^2"
            " +%3.1f x + %3.1f\n", ra1, ra2, ra3, ra4, ra5);

    return 0;
}

/*############################################################################*/
/*               End of HW00_Furkan_Erdol_131044065_part2.c                   */
/*############################################################################*/
