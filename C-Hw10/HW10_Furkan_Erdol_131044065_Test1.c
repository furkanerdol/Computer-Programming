/*############################################################################*/
/*HW10_Furkan_Erdol_131044065_Test1.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on May 25, 2015                                     */
/*                                                                            */
/*                                                                            */
/*         To test "HW10_Furkan_Erdol_131044065_Part1.h" library              */
/*                                                                            */
/*                                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#include "HW10_Furkan_Erdol_131044065_Part1.h"


int	main(int argc, char* argv[])
{
	Appointment_t* appointments; /*Array of records*/
	int size; /*Number of records*/
	
	/*Takes main arguments and change hours and file names*/
	get_main_arguments(argc, argv, &hours, &files);
	
	/*Reads records and writes into the array them*/
	/*Size is a records number*/
	appointments=getRequests(&files, &size);
	
	/*Takes array of records and writes records into the file as xml file*/
	write_appointments(appointments, size, &files);
	
	/*Writes file names and hours into the file*/
	print_parameters(&files, &hours);

	return 0;
}

/*############################################################################*/
/*               End of HW10_Furkan_Erdol_131044065_Test1.c                   */
/*############################################################################*/
