/*
 * HW10_Furkan_Erdol_131044065_Part1.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HW10_Furkan_Erdol_131044065_Part1.h"

/*Define default files and hours as global variables*/
Files_t files={RECORDSBIN,PATIENTS,DELETE,RECORDSXML,APPOINTMENTS,PARAMETERS};
Working_hours_t hours={START,END};

/*Reads records and writes into the array them*/
/*Size is a records number*/
Appointment_t* getRequests(const Files_t* files, int* size)
{
	Appointment_t* appointments;
	FILE* fptr;
	int i;
	
	fptr=fopen(files->records_file_n, "rb");
	
	/*Reads number of records*/
	fread(size, sizeof(int), 1, fptr);
	
	/*Allocates memory for array of appointments*/
	appointments=(Appointment_t *)calloc((*size),sizeof(Appointment_t));
	
	/*Reads appointments*/
	for(i=0; i<(*size); i++)
		fread(&appointments[i], sizeof(Appointment_t), 1, fptr);
		
	fclose(fptr);
	
	return appointments;
	
}

/*Takes array of records and writes records into the file as xml file*/
void write_appointments(Appointment_t appointments[], int size, const Files_t* files)
{
	FILE* fptr;
	int i;
	
	fptr=fopen(files->readable_records_file_n, "w");
	
	fprintf(fptr, "<Size>%d</Size>", size);
	fprintf(fptr, "\n<Records>");
	
	for(i=0; i<size; i++){
		fprintf(fptr, "\n%6c<Appointment>", ' ');
		fprintf(fptr, "\n%13c<app_id>%d</app_id>", ' ', appointments[i].app_id);
		fprintf(fptr, "\n%13c<patient_id>%d</patient_id>", ' ', appointments[i].patient_id);
		fprintf(fptr, "\n%13c<hour>%d</hour>", ' ', appointments[i].hour);
		fprintf(fptr, "\n%6c</Appointment>", ' ');
		}
	
	fprintf(fptr, "\n</Records>");
}

/*Takes main arguments and change hours and file names*/
void get_main_arguments(int argc, char* argv[], Working_hours_t* hours, Files_t* files)
{
	int i;
	
	for(i=1; i<argc-1; i++){
		
		if(strcmp(argv[i],"-r")==0)
			files->records_file_n=argv[i+1];
		else if(strcmp(argv[i],"-p")==0)
			files->patients_file_n=argv[i+1];
		else if(strcmp(argv[i],"-d")==0)
			files->delete_file_n=argv[i+1];
		else if(strcmp(argv[i],"-x")==0)
			files->readable_records_file_n=argv[i+1];
		else if(strcmp(argv[i],"-c")==0)
			files->accepted_appo_file_n=argv[i+1];
		else if(strcmp(argv[i],"-t")==0)
			files->parameters_file_n=argv[i+1];
		else if(strcmp(argv[i],"-s")==0)
			hours->start=atoi(argv[i+1]);																		
		else if(strcmp(argv[i],"-e")==0)
			hours->end=atoi(argv[i+1]);
	}		
}

/*Writes file names and hours into the file*/	
void print_parameters(const Files_t* files, const Working_hours_t* hours)
{
	FILE* fptr;
	
	fptr=fopen(files->parameters_file_n, "w");
	
	fprintf(fptr, "%s\n", files->records_file_n);
	fprintf(fptr, "%s\n", files->patients_file_n);	
	fprintf(fptr, "%s\n", files->delete_file_n);
	fprintf(fptr, "%s\n", files->readable_records_file_n);
	fprintf(fptr, "%s\n", files->accepted_appo_file_n);
	fprintf(fptr, "%s\n", files->parameters_file_n);
	fprintf(fptr, "%d\n", hours->start);	
	fprintf(fptr, "%d\n", hours->end);
	
	fclose(fptr);
}

/*############################################################################*/
/*                HW10_Furkan_Erdol_131044065_Part1.c                         */
/*############################################################################*/		
