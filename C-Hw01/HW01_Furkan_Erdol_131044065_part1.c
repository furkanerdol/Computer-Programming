/*############################################################################*/
/*HW01_Furkan_Erdol_131044065_part1.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on February 22, 2015                                */
/*Description                                                                 */
/*____________                                                                */
/*Calculate the composite functions fog(x) and gof(x) using f(x) and g(x)     */
/*Input value ​​read from Variables.txt                                         */
/*Output values ​​are written to Results1.txt                                   */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Integer value of x                                                       */
/*Outputs:                                                                    */
/*   -Resulting fog(x), gof(x), f(x) and g(x) values                          */
/*                                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#include <math.h>
#define PI 3.14
#define RA (PI/180) /*Convert degree to radian*/

double gx(int x, double y);
double fx(int x, double y);
	
int
main(void)
{
    int x; /*Value of input*/	
	double fogx, gofx, f, g; /*Functions*/
	double const y = 8.0; /*y is a constant macro*/
    FILE *fp1, *fp2;

	/*Open Variables.txt and read input value from Variables.txt*/
	fp1 = fopen("Variables.txt", "r");
	fscanf(fp1, "%d", &x);
    printf("\nEntered integer x = %d", x);

	fclose(fp1);
	
	/*Calculate resulting composite functions*/
	gofx = fx(x, y)+(1.0/(fx(x, y)+(y/(2.0*fx(x, y)))));
	fogx = sin(pow(((gx(x, y)+y)/gx(x, y))+sqrt(log10(pow(3.0, gx(x, y))/
	(2.0*gx(x, y)+1.0))), 2.5)*RA);
	
	g = gx(x, y);
	f = fx(x, y);
	
    /*Open Results1.txt and write functions result to Results1.txt*/	
	fp2 = fopen("Results1.txt", "w");
	fprintf(fp2, "%f %f %f %f", fogx, gofx, f, g);

	fclose(fp2);

	/*Output the function results*/
	printf("\n\nThe result of the function f(x) = %f\nThe result of the"
	        " function g(x) = %f\n", f, g);
	printf("\nThe result of the function fog(x) = %f\nThe result of the"
	        " function gof(x) = %f\n\n", fogx, gofx);
	
    return 0;
}

double fx(int x, double y) /*Define the function of f(x)*/
{
	double fx;
	fx = sin(pow(((x+y)/x)+sqrt(log10(pow(3.0, x)/(2.0*x+1.0))), 2.5)*RA);
	return fx;
}

double gx(int x, double y) /*Define the function of g(x)*/
{
	double gx;
	gx = x+(1.0/(x+(y/(2.0*x))));
	return gx;
}
/*############################################################################*/
/*               End of HW01_Furkan_Erdol_131044065_part1.c                   */
/*############################################################################*/
