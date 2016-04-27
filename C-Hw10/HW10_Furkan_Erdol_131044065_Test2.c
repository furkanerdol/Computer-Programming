/*############################################################################*/
/*HW10_Furkan_Erdol_131044065_Test2.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on May 25, 2015                                     */
/*                                                                            */
/*                                                                            */
/*          To test "HW10_Furkan_Erdol_131044065_Part2.h" library             */
/*                                                                            */
/*                                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#include "HW10_Furkan_Erdol_131044065_Part1.h"
#include "HW10_Furkan_Erdol_131044065_Part2.h"


int
main(int argc, char* argv[])
{
	Appointment_t* appointments; /*Array of appointments*/
	int size; /*Number of appointments*/
	node_t* head; /*Linked list of appointments*/
	
	/*Takes main arguments and change hours and file names*/
	get_main_arguments(argc, argv, &hours, &files);
	
	/*Reads records and writes into the array them*/
	/*Size is a records number*/
	appointments=getRequests(&files, &size);

	/*Takes array of appointments and creates linked list of appointments*/
	head=build_ll(appointments,  size, &hours);
	
	/*Takes linked list of appointments and writes them into the file as cvs file*/
	write_accepted_app(head, &files);
	
	/*Takes linked list of appointments and patient informations*/
	/*Reads personal data and records them into the linked list*/ 
	add_personal_data(head, &files);
	
	/*Deletes all records in the delete file from the linked list*/
	/*Returns the number of appointments deleted*/
	delete_appointments(&head, &files);
	
	/*Frees reserved place in memory for linked list of appointments*/
	free_list(head);

	return 0;
}

/*############################################################################*/
/*               End of HW10_Furkan_Erdol_131044065_Test2.c                   */
/*############################################################################*/
