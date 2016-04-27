/*
 * complex.c
 */

#include <stdio.h>
#include <math.h>
#include "complex.h"

/* 
 * Complex number input function returns standard scanning 
 * error code 
 */
int scan_complex(complex_t *c) 
{ 
	int status;
	int control; 

	printf("Enter complex number:");
	status=scanf("%lf%lf", &c->real, &c->imag); 

	if(status==2) 
		control=1; 
	else if(status!=EOF) 
		control=0; 

	return control; 
}

/*
 * Complex output function displays value as a + bi or a - bi. 
 * Displays only a if imaginary part is 0. 
 * Displays only bi if real part is 0. 
 */
void print_complex(complex_t c)
{ 
	double a, b; 
	char sign; 

	a=c.real; 
	b=c.imag; 

 	printf("("); 

 	if(fabs(a) < .005 && fabs(b) < .005) 
		printf("%.2f", 0.0); 
	else if(fabs(b) < .005) 
		printf("%.2f", a); 
	else if(fabs(a) < .005) 
		printf("%.2fi", b); 
	else{ 

 		if(b<0) 
			sign='-'; 
		else 
			sign='+'; 

 		printf("%.2f %c %.2fi", a, sign, fabs(b)); 
	} 

 	printf(")"); 
}

/* 
 * Returns sum of complex values c1 and c2 
 */
complex_t add_complex(complex_t c1, complex_t c2)
{
	complex_t csum; 

	csum.real=c1.real+c2.real; 

	csum.imag=c1.imag+c2.imag; 

	return csum;
}

/*
 * Returns difference c1 - c2 
 */
complex_t subtract_complex(complex_t c1, complex_t c2)
{ 
	complex_t cdiff; 
	
	cdiff.real=c1.real-c2.real; 
	
	cdiff.imag=c1.imag-c2.imag; 
 
 	return cdiff; 
}

/*
 * Returns multiply of complex values c1 - c2 
 */
complex_t multiply_complex(complex_t c1, complex_t c2)
{
	complex_t multi;
	
	multi.real=(c1.real*c2.real)-(c1.imag*c2.imag);
	
	multi.imag=(c1.real*c2.imag)+(c1.imag*c2.real);

	return multi;
}

/*
 * Returns quotient of complex values c1 - c2 
 */
complex_t divide_complex(complex_t c1, complex_t c2)
{
	complex_t div;
	
	div.real=((c1.real*c2.real)+(c1.imag*c2.imag))/((c2.real*c2.real)+(c2.imag*c2.imag));
	
	div.imag=((c1.imag*c2.real)-(c1.real*c2.imag))/((c2.real*c2.real)+(c2.imag*c2.imag));
}

/*
 * Returns absolute value of complex number c 
 */
complex_t abs_complex(complex_t c)
{ 
	complex_t cabs; 

	cabs.real=sqrt(c.real*c.real+c.imag*c.imag); 

	cabs.imag=0; 
	
	return cabs; 
}

/*############################################################################*/
/*                HW09_Furkan_Erdol_131044065_complex.c                       */
/*############################################################################*/		
