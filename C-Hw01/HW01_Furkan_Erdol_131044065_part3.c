/*############################################################################*/
/*HW01_Furkan_Erdol_131044065_part3.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on February 22, 2015                                */
/*Description                                                                 */
/*____________                                                                */
/*Reads car information from Cars.txt and calculate output total fuel costs   */
/*Total fuel costs are written to TotalFuelCosts.txt                          */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Car informations                                                         */
/*     Amount (lt) of fuel consumed per km                                    */
/*     Price of fuel                                                          */
/*     Total km taken by car                                                  */
/*Outputs:                                                                    */
/*   -Total fuel cost of the cars                                             */
/*                                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#include <stdlib.h>

int
main (void) {

	int n1, n2, n3, /*Car numbers*/
	    w1, w2, w3,
	    m1, m2, m3;
	
	float a1, b1, c1, /*1st car informationss*/
		  a2, b2, c2, /*2nd car informationss*/
		  a3, b3, c3, /*3rd car informationss*/
		  r1, r2, r3,
		  k1, k2, k3;
    
    FILE *fp1, *fp2;

    /*Open Cars.txt and read input car informations*/
    fp1 = fopen("Cars.txt", "r");
	fscanf(fp1, "%d %f %f %f", &n1, &a1, &b1, &c1);
	fscanf(fp1, "%d %f %f %f", &n2, &a2, &b2, &c2);
	fscanf(fp1, "%d %f %f %f", &n3, &a3, &b3, &c3);
	
	fclose(fp1);
    
    /*Calculate total fuel cost of the cars*/
	r1 = a1*b1*c1;
	r2 = a2*b2*c2;
	r3 = a3*b3*c3;
	
	/*Calculate number of after the point*/
	w1 = r1;
	k1 = r1-w1;
	m1 = k1*100;
	/*Calculate number of after the point*/
	w2 = r2;
	k2 = r2-w2;
	m2 = k2*100;
	/*Calculate number of after the point*/
	w3 = r3;
	k3 = r3-w3;
	m3 = k3*100;
	
    /*Open TotalFuelCosts.txt and write output total fuel cost of the cars*/
	fp2 = fopen("TotalFuelCosts.txt", "w");
	fprintf(fp2, "%d %.2f\n%d %.2f\n%d %.2f", n1, r1, n2, r2, n3, r3);
	
	fclose(fp2);

    /*Print the display output total fuel cost of the cars*/
	printf("The total fuel cost of the car %d is %d TL and %d Kurus\n",n1,w1,m1);
	printf("The total fuel cost of the car %d is %d TL and %d Kurus\n",n2,w2,m2);
	printf("The total fuel cost of the car %d is %d TL and %d Kurus\n",n3,w3,m3);

    return 0;
}
/*############################################################################*/
/*               End of HW01_Furkan_Erdol_131044065_part3.c                   */
/*############################################################################*/
