/*############################################################################*/
/*HW09_Furkan_Erdol_131044065_part2.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on April 27, 2015                                   */
/*                                                                            */
/*                                                                            */
/*                      To test "complex.h" library                           */
/*                                                                            */
/*                                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#include "complex.h"

int
main(void)
{
	complex_t x,y,z;
	
	/*Reads complex numbers*/
	scan_complex(&x);
	scan_complex(&y);
	
	/*Divide complex numbers*/
	z=divide_complex(x,y); 
	printf("The result of the division -> ");
	print_complex(z);
	printf("\n");

	/*Multiply complex numbers*/
	z=multiply_complex(x,y); 
	printf("The result of the multiplication -> ");
	print_complex(z);
	printf("\n");
	
	return 0;
}

/*############################################################################*/
/*               End of HW09_Furkan_Erdol_131044065_part2.c                   */
/*############################################################################*/
