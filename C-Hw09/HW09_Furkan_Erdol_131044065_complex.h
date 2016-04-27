/* complex.h
 * 
 * Abstract data type complex numbers
 *
 * Type complex_t has these components:
 *		real and imag
 *
 * Operators:
 *		scan_complex, 
 *		print_complex, 
 *		complex_t add_complex,
 *		complex_t subtract_complex,
 *		complex_t multiply_complex,
 *		complex_t divide_complex,
 *		complex_t abs_complex
 */
 
/* User-defined complex number type */
typedef struct{
	double real; /* Real portion of complex number */
	double imag; /* Imaginary portion of complex number */
}complex_t;	

/* 
 * Complex number input function returns standard scanning 
 * error code 
 */
extern int scan_complex(complex_t *c); 

/*
 * Complex output function displays value as a + bi or a - bi. 
 * Displays only a if imaginary part is 0. 
 * Displays only bi if real part is 0. 
 */
extern void print_complex(complex_t c); 

/* 
 * Returns sum of complex values c1 and c2 
 */
extern complex_t add_complex(complex_t c1, complex_t c2); 

/*
 * Returns difference c1 - c2 
 */
extern complex_t subtract_complex(complex_t c1, complex_t c2); 

/*
 * Returns multiply of complex values c1 - c2 
 */
extern complex_t multiply_complex(complex_t c1, complex_t c2); 

/*
 * Returns quotient of complex values c1 - c2 
 */
extern complex_t divide_complex(complex_t c1, complex_t c2); 

/*
 * Returns absolute value of complex number c 
 */
extern complex_t abs_complex(complex_t c);

/*############################################################################*/
/*                HW09_Furkan_Erdol_131044065_complex.h                       */
/*############################################################################*/
