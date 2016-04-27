/*HW10_Furkan_Erdol_131044065_Test3.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on May 25, 2015                                     */
/*                                                                            */
/*                                                                            */
/*          To test "HW10_Furkan_Erdol_131044065_Part3.h" library             */
/*                                                                            */
/*                                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#include "HW10_Furkan_Erdol_131044065_Part1.h"
#include "HW10_Furkan_Erdol_131044065_Part2.h"
#include "HW10_Furkan_Erdol_131044065_Part3.h"


int
main(int argc, char* argv[])
{
	Appointment_t* appointments; /*Array of appointments*/
	int size; /*Number of appointments*/
	node_t *copy, *real; /*Linked list of appointments and one of the copy*/
	
	/*Takes main arguments and change hours and file names*/	
	get_main_arguments(argc, argv, &hours, &files);
	
	/*Reads records and writes into the array them*/
	/*Size is a records number*/
	appointments=getRequests(&files, &size);

	/*Takes array of appointments and creates linked list of appointments*/
	real=build_ll(appointments,  size, &hours);
	
	/*Takes linked list of appointments and patient informations*/
	/*Reads personal data and records them into the linked list*/ 
	add_personal_data(real, &files);
	
	/*Takes linked list of appointments and creates creates its copy*/
	copy=make_independent_copy_ll(real);

	/*Sample*/
	
	/*Prints the screen node informations*/
	write_appo_node(real);
	/*Change the history information*/
	change_history(copy, "NEW HISTORY");
	/*Prints the screen node informations*/
	write_appo_node(copy);
	
	/*Frees reserved place in memory for linked list of appointments*/
	free_list(copy);
	
	/*Frees reserved place in memory for linked list of appointments*/
	free_list(real);
	
	return 0;
}

/*############################################################################*/
/*               End of HW10_Furkan_Erdol_131044065_Test3.c                   */
/*############################################################################*/
