/*############################################################################*/
/*HW01_Furkan_Erdol_131044065_part2.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on February 22, 2015                                */
/*Description                                                                 */
/*____________                                                                */
/*Finds x and y using the linear equations with two unknowns                  */ 
/*Calculates f (x,y)                                                          */
/*Coefficients of the equation  ​​read from EqCoefficients.txt                  */
/*Coefficients of the function  read from FuncCoefficients.txt                */
/*Results of equations and result of function are written to Results2.txt     */ 
/*                                                                            */
/*Inputs:                                                                     */
/*  -Coefficients of the equation and equation results                        */
/*  -Coefficients of the function                                             */
/*Outputs:                                                                    */
/*  -Values of x and y                                                        */
/*  -Results of equation1 and equation2                                       */
/*  -Result of function f(x, y)                                               */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>


int
main(void)
{
    	
	double x1, y1, r1, /*Coefficients of equation1 an result of equation1     */
		   x2, y2, r2, /*Coefficients of equation2 an result of equation2     */
		   x3, y3, r3, /*Coefficients of function an result of function       */
		   x, y; /*Value of x and y*/
    
	FILE *fp1, *fp2, *fp3;

	
	/*Open EqCoefficients.txt and read input equation coefficients*/
	/*Print the display equation1 and equation2*/ 
	fp1 = fopen("EqCoefficients.txt", "r");
	fscanf(fp1, "%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1,&x2, &y2, &r2);
    printf("\nEntered Equation1 > %.1fx +%.1fy = %.0f", x1, y1, r1);
	printf("\nEntered Equation2 > %.1fx +%.1fy = %.0f", x2, y2, r2);

	fclose(fp1);

	/*Calculate x and y value*/
	y = (r1+r2*(-x1/x2))/(y1+y2*(-x1/x2));
	x = (r1-y1*y)/x1;
	
	/*Print the display x and y result*/
	printf("\nResult x = %.0f\nResult y = %.0f", x, y);

	/*Open FuncCoefficients.txt and read input function coefficients*/
	/*Print the display function*/
	fp2 = fopen("FuncCoefficients.txt", "r");
	fscanf(fp2, "%lf %lf", &x3, &y3);
	printf("\nFunction f(x, y) = %.0fx + %.0fy", x3, y3);

	fclose(fp2);

	/*Calculate result of function*/	
	r3 = x3*x+y3*y;

	/*Print the display result of function*/
	printf("\nResult of function f(x, y)= %.0f\n\n", r3);
	
	/*Open Results2.txt and write output result of equations and function*/
	fp3 = fopen("Results2.txt", "w");
	fprintf(fp3, "%0.f %0.f %0.f", r1, r2, r3);

	fclose(fp3);
	
	
	return 0;
}

/*############################################################################*/
/*               End of HW01_Furkan_Erdol_131044065_part2.c                   */
/*############################################################################*/
