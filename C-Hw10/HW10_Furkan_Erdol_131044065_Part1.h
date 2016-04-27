/* HW10_Furkan_Erdol_131044065_Part1.h
 * 
 * Operators:
 *		getRequests, 
 *		write_appointments, 
 *		get_main_arguments,
 *		print_parameters,
 */

/*Default file names*/
#define RECORDSBIN "Records.bin"
#define PATIENTS "Patients.xml"
#define DELETE "Delete.txt"
#define RECORDSXML "Records.xml"
#define APPOINTMENTS "Appointments.csv"
#define PARAMETERS "Parameters.txt"

/*Default working hours*/
#define START 9
#define END 19

/*Structer of appointment information*/
typedef struct{
	int app_id;
	int patient_id;
	int hour;
}Appointment_t;

/*Structer of files names*/
typedef struct{
	const char* records_file_n;
	const char* patients_file_n;
	const char* delete_file_n;
	const char* readable_records_file_n;
	const char* accepted_appo_file_n;
	const char* parameters_file_n;
}Files_t;

/*Structer of working hours*/
typedef struct{
	int start;
	int end;
}Working_hours_t;

/*Define default files and hours as global variables*/
extern Files_t files;
extern Working_hours_t hours;

/*Reads records and writes into the array them*/
/*Size is a records number*/
extern Appointment_t* getRequests(const Files_t* files, int* size);

/*Takes array of records and writes records into the file as xml file*/
extern void write_appointments(Appointment_t appointments[], int size, const Files_t* files);

/*Takes main arguments and change hours and file names*/
extern void get_main_arguments(int argc, char* argv[], Working_hours_t* hours, Files_t* files);

/*Writes file names and hours into the file*/
extern void print_parameters(const Files_t* files, const Working_hours_t* hours);

/*############################################################################*/
/*                HW10_Furkan_Erdol_131044065_Part1.h                         */
/*############################################################################*/
