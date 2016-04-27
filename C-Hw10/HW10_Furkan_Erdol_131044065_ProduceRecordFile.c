/*############################################################################*/
/*HW10_Furkan_Erdol_131044065_ProduceRecordFile.c                             */
/*______________________________                                              */
/*Written by Furkan Erdol on May 25, 2015                                     */
/*                                                                            */
/*                                                                            */
/*                        To produce record file                              */
/*                                                                            */
/*                                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>


typedef struct{
	int app_id;
	int patient_id;
	int hour;
}Appointment_t;


int	main(void)
{

	FILE *fptr;
	Appointment_t a[5];

	int size=4;

	a[0].app_id=8;
	a[0].patient_id=2;
	a[0].hour=11;
	
	a[1].app_id=3;
	a[1].patient_id=5;
	a[1].hour=19;
	
	a[2].app_id=11;
	a[2].patient_id=2;
	a[2].hour=14;
	
	a[3].app_id=203;
	a[3].patient_id=20;
	a[3].hour=11;
	
	fptr=fopen("Records.bin", "wb");
	
	fwrite(&size, sizeof(int), 1, fptr);
	
	fwrite(a, sizeof(a), 1, fptr);
	
	fclose(fptr);

	
	return 0;
}

/*############################################################################*/
/*              HW10_Furkan_Erdol_131044065_ProduceRecordFile.c               */
/*############################################################################*/
