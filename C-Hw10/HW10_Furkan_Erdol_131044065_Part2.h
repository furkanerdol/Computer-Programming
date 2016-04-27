/* HW10_Furkan_Erdol_131044065_Part2.h
 * 
 * Operators:
 *		check_time, 
 *		build_ll, 
 *		write_accepted_app,
 *		search_in_ll,
 *		add_personal_data,
 *		delete_appointments,
 *		free_list,
 *		write_appo_node,
 */

/*Structer of personal data*/
typedef struct node_t{
	int app_id;
	int patient_id;
	char name[50];
	char* history;
	int hour;
	struct node_t* next;
}node_t;	


/*Takes array of appointments and creates linked list of appointments*/
extern node_t* build_ll(Appointment_t appointments[], int size, const Working_hours_t* hours);

/*Takes linked list of appointments and writes them into the file as cvs file*/
extern void write_accepted_app(node_t* head, const Files_t* files);

/*Takes linked list of appointments and patient informations*/
/*Reads personal data and records them into the linked list*/
extern void add_personal_data(node_t* head, const Files_t* files);

/*Deletes all records in the delete file from the linked list*/
/*Returns the number of appointments deleted*/
extern int delete_appointments(node_t** head, const Files_t* files);

/*Frees reserved place in memory for linked list of appointments*/
extern void free_list(node_t* head);

/*Takes an integer array and hour searches whether hour*/
extern int check_time(int time[], int size, int hour);

/*Takes linked list and integer id searches id into the linled list*/
extern int search_in_ll(node_t* head, int id);

/*Takes linked list and prints the screen first node*/
extern void write_appo_node(node_t* head);

/*############################################################################*/
/*                HW10_Furkan_Erdol_131044065_Part2.h                         */
/*############################################################################*/
