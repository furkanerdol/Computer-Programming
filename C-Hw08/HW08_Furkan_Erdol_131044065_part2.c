/*############################################################################*/
/*HW08_Furkan_Erdol_131044065_part2.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on April 19, 2015                                   */
/*Description                                                                 */
/*____________                                                                */
/*                                                                            */
/*  >This program program to handle the appointments of a doctor              */  
/*  >Reads the recorded people from a People.txt                              */
/*  >Reads the appointment requests from AppointmentReqs.txt                  */
/*  >Produces Appointments.txt including the detailed information about       */
/* approved appointments in order                                             */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Informations of recorded people                                          */
/*  -Appointment requests                                                     */
/*Outputs:                                                                    */
/*  -Appointments list                                                        */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#include <string.h>

#define MAXIMUM_SIZE 20

typedef enum
	{NONSET,JANUARY,FEBRUARY,MARCH,APRIL,MAY,JUNE,JULY,AUGUST
	,SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER}
Months_t;	

typedef enum
	{MALE,FEMALE}
Gender_t;	

typedef struct{
	int first_half;
	int second_half;
}TCId_no_t;

typedef struct{
	TCId_no_t id_no;
	char name[30];
	char surname[30];
	Gender_t gender;
}People_t;

typedef struct{
	int hour;
	int minute;
}Time_t;

typedef struct{
	int year;
	Months_t month;
	int day;
	Time_t time;
}Date_t;

typedef struct{
	People_t people;
	Date_t date;
}Appointment_t; 			

/*Funtion prototypes*/
int get_people(const char *file_name, People_t people[], int max_size);
int get_appointments(const char *file_name, Appointment_t appointments[], int max_size);			
void write_names(Appointment_t appointments[], int size_app, const People_t people[], int size_people);
int check_appointments(Appointment_t appointments[], int size);
void sort_appointments(Appointment_t appointments[], int size);
void write_appointments(const char *file_name, Appointment_t appointments[], int size);


int
main(void)
{
	People_t people[MAXIMUM_SIZE]; /*Informations of recorded people*/
	Appointment_t appointments[MAXIMUM_SIZE]; /*Appointments list*/
	int size_people, /*Number of recorded people*/
		size_app, /*Number of appointment requests*/
		new_app; /*Number of accepted appointment requests*/
	int i; /*For loops*/
	
	/*Reads all people from the file and record them into the array*/
	size_people=get_people("People.txt", people, MAXIMUM_SIZE);
	
	/*Reads all appointment records from the file and record them into the array*/
	size_app=get_appointments("AppointmentReqs.txt", appointments, MAXIMUM_SIZE);
	
	/*Fills the name and surname fields of people fields of appointments*/
	write_names(appointments, size_app, people, size_people);
	
	/*Considers all appointment requests, deletes the rejected ones*/
	new_app=check_appointments(appointments, size_app);
	
	/*Sort the appointments with respect to the date of the appointment*/
	sort_appointments(appointments, new_app);
	
	/*Writes all appointments to a text file*/
	write_appointments("Appointments.txt", appointments, new_app);
	
	return 0;
}

/*Reads all people from the file and record them into the array*/ 
/*Returns number records read*/
int get_people(const char *file_name, People_t people[], int max_size)
{
	FILE *fp; /*File pointer*/
	char gender; /*Gender*/
	int size=0; /*Number of people*/
	int status=0; /*Control value for loop*/
	
	/*Open file if file couldn't open writes a warning mesaage and function ends*/
	fp=fopen(file_name, "r");
	if(fp==NULL){
		printf("People.txt couldn't open...");
		return 0;
	}	

	/*Reads all informations recorded people*/
	while(fscanf(fp, "%6d", &people[size].id_no.first_half)!=EOF&&size<=max_size){
		fscanf(fp, "%5d", &people[size].id_no.second_half);
		fscanf(fp, "%s%s", people[size].name, people[size].surname);
		do{
			fscanf(fp, "%c", &gender);
			if(gender=='\n'||gender==' ')
				status=-1;
			else
				status=0;	
		}			
		while(status==-1);
		
		if(gender=='M')
			people[size].gender=MALE;
		else if(gender=='F')
			people[size].gender=FEMALE;
		
		size++;		
	}

	fclose(fp);

	return size;
}

/*Reads all appointment records from the file and record them into the array  *
 *leaving name and surname fields unassigned. Returns number records read     */
int get_appointments(const char *file_name, Appointment_t appointments[], int max_size)
{
	FILE *fp; /*File pointer*/
	int size=0; /*Number of recorded appointment requests*/
	char ch; /*For reads to ":" character*/
	int month; /*Month*/
	
	fp=fopen(file_name, "r");
	if(fp==NULL){
		printf("AppointmentReqs.txt couldn't open...");
		return 0;
	}
	
	/*Read all informations recorded appointment requests*/
	while(fscanf(fp, "%6d", &appointments[size].people.id_no.first_half)!=EOF&&size<=max_size){
		fscanf(fp, "%5d", &appointments[size].people.id_no.second_half);
		fscanf(fp, "%d", &appointments[size].date.year);
		fscanf(fp, "%d", &month);
		/*Switch case for enumataion months*/
		switch(month){
	
		case 1 : appointments[size].date.month=JANUARY;
			 	 break;
		case 2 : appointments[size].date.month=FEBRUARY;
			 	 break;
		case 3 : appointments[size].date.month=MARCH;
			 	 break;		 		 
		case 4 : appointments[size].date.month=APRIL;
			 	 break;		 	
		case 5 : appointments[size].date.month=MAY;
			 	 break;
		case 6 : appointments[size].date.month=JUNE;
			 	 break;
		case 7 : appointments[size].date.month=JULY;
			 	 break;
		case 8 : appointments[size].date.month=AUGUST;
			 	 break;
		case 9 : appointments[size].date.month=SEPTEMBER;
			 	 break;
		case 10 : appointments[size].date.month=OCTOBER;
			 	 break;
		case 11 : appointments[size].date.month=NOVEMBER;
			 	 break;
		case 12 : appointments[size].date.month=DECEMBER;
			 	 break;
	}		 
		fscanf(fp, "%d", &appointments[size].date.day);
		fscanf(fp, "%d", &appointments[size].date.time.hour);
		fscanf(fp, "%c", &ch); /*Reads ":"*/
		fscanf(fp, "%d", &appointments[size].date.time.minute);
		
		size++;		
	}
	
	fclose(fp);
	
	return size;
}

/*Fills the name and surname fields of people fields of appointments*/
void write_names(Appointment_t appointments[], int size_app, const People_t people[], int size_people)
{
	int i; /*For loops*/
	
	/*Fills the name and surname*/
	for(i=0;i<size_people;i++){
		strcpy(appointments[i].people.name, people[i].name);
		strcpy(appointments[i].people.surname, people[i].surname);
		appointments[i].people.gender=people[i].gender;
	}	
}

/*Considers all appointment requests, deletes the rejected ones and returns   *
 *the new size as the return value                                            */
int check_appointments(Appointment_t appointments[], int size)
{
	int i,j; /*For loops*/
	int accepted=1; /*Control value*/ 
	int new_size=1; /*Number of accepted appointment requests*/

	/*If appointment is different(as date) from other accept it*/
	for(i=1;i<size;i++){
		for(j=0;j<i;j++){
			if(appointments[i].date.year==appointments[j].date.year
			&&appointments[i].date.month==appointments[j].date.month
			&&appointments[i].date.day==appointments[j].date.day
			&&appointments[i].date.time.hour==appointments[j].date.time.hour
			&&appointments[i].date.time.minute==appointments[j].date.time.minute)
				accepted=0;
		}
		
		if(accepted==1)
			appointments[new_size++]=appointments[i];
		else
			accepted=1;
	}
	
	return new_size;			
}

/*Sort the array with respect to the date of the appointment*/
void sort_appointments(Appointment_t appointments[], int size)
{
	int i,j; /*for loops*/
	
	Appointment_t temp; /*Temporary appointment*/
	
	/*Sort by date*/
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(appointments[i].date.year>appointments[j].date.year){
				temp=appointments[i];
				appointments[i]=appointments[j];
				appointments[j]=temp;
			}
			else if(appointments[i].date.year==appointments[j].date.year
					&&appointments[i].date.month>appointments[j].date.month){
				temp=appointments[i];
				appointments[i]=appointments[j];
				appointments[j]=temp;
			}
			else if(appointments[i].date.year==appointments[j].date.year
					&&appointments[i].date.month==appointments[j].date.month
					&&appointments[i].date.day>appointments[j].date.day){
				temp=appointments[i];
				appointments[i]=appointments[j];
				appointments[j]=temp;
			}	
			else if(appointments[i].date.year==appointments[j].date.year
					&&appointments[i].date.month==appointments[j].date.month
					&&appointments[i].date.day==appointments[j].date.day
					&&appointments[i].date.time.hour>appointments[j].date.time.hour){
				temp=appointments[i];
				appointments[i]=appointments[j];
				appointments[j]=temp;
			}						
		}		
	}
}

/*Writes all appointments to a text file*/
void write_appointments(const char *file_name, Appointment_t appointments[], int size)
{
	FILE *fp; /*File pointer*/
	int i; /*For loop*/

	/*Open file if file couldn't open writes a warning mesaage and function ends*/
	fp=fopen(file_name, "w");
	if(fp==NULL)
		printf("Appointments.txt couldn't open...");
	else{	
		for(i=0;i<size;i++){
			fprintf(fp, "%d", appointments[i].date.year);
			fprintf(fp, " %d", appointments[i].date.month);
			fprintf(fp, " %d", appointments[i].date.day);
			fprintf(fp, " %d", appointments[i].date.time.hour);
			fprintf(fp, ":%d", appointments[i].date.time.minute);
			fprintf(fp, " %d", appointments[i].people.id_no.first_half);
			fprintf(fp, "%d", appointments[i].people.id_no.second_half);			
			fprintf(fp, " %s %s", appointments[i].people.name, appointments[i].people.surname);
			if(appointments[i].people.gender==0)
				fprintf(fp, " M\n");
			else if(appointments[i].people.gender==1)
				fprintf(fp, " F\n");				
		}
	}

	fclose(fp);
}

/*############################################################################*/
/*                End of HW08_Furkan_Erdol_131044065_part2.c                  */
/*############################################################################*/	
