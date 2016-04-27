/*############################################################################*/
/*HW09_Furkan_Erdol_131044065_part1.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on April 23, 2015                                   */
/*Description                                                                 */
/*____________                                                                */
/**************This program for Gebze Technical University*********************/
/*Program calculates annual salary increase of a person in the university     */
/*Takes a person information and returns updates person information           */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Person information(as a text file)                                       */
/*Outputs:                                                                    */
/*  -Updated person information(as a binary file)                             */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#include <string.h>

/*Define maximum size array of person information*/
#define MAX_SIZE 10

typedef struct{
	char name[15];
	char surname[15];
	char department[25];
	char class_one[10];
	char class_two[10];
	double salary;
}type_I;

typedef struct{
	char name[15];
	char surname[15];
	double salary;
	char degree;
}type_E;

typedef union{
	type_I I; /*Instructor person*/
	type_E E; /*Employee person*/
}person_t;	

typedef struct{
	person_t person;
	char person_type;
}combine_type;	

/*Function prototypes*/
int read_person_info(char *file_name, combine_type *combine, int max_size);
combine_type salary_rise(combine_type person_info);

int
main(void)
{

	combine_type combine[MAX_SIZE]; /*Array of person information*/
	int i; /*For loop*/
	FILE *fp; /*File pointer*/
	int number_of_person; /*Number of person*/

	/*Reads person information from text file*/	
	number_of_person=read_person_info("person.txt", combine, MAX_SIZE);

	/*Calculates salary rise for each person*/
	for(i=0;i<number_of_person;i++)
		combine[i]=salary_rise(combine[i]);
	
	/*Open binary file*/
	fp=fopen("person.bin", "wb");
	
	/*Writes updated person information to binary file*/
	fwrite(combine, sizeof(combine), 1, fp);
	
	/*Close binary file*/
	fclose(fp);	
		
	return 0;
}

/*Reads person information from text file*/
int read_person_info(char *file_name, combine_type *combine, int max_size)
{

	FILE *fp; /*File pointer*/
	int i=0; /*For loop*/
	char type[10]; /*Person type string*/
	char ch; /*Read for ',' character after department*/
	int status=0; /*Control value*/
	char buffer[20]; /*For buffer problem*/
	int number_of_person=0; /*Number of person*/
	
	/*Open text file*/
	fp=fopen(file_name, "r");
	
	/*Reads person information*/
	while(fscanf(fp, "%s", type)!=EOF&&i<max_size){
	
		if(type[strlen(type)-1]==',')
			type[strlen(type)-1]='\0';
		/*If person is instructor*/
		if(strcmp(type, "Instructor")==0){
			combine[i].person_type='I';
			fscanf(fp, "%s", combine[i].person.I.name);
			fscanf(fp, "%s", combine[i].person.I.surname);
			if(combine[i].person.I.surname[strlen(combine[i].person.I.surname)-1]==',')
				combine[i].person.I.surname[strlen(combine[i].person.I.surname)-1]='\0';
			fscanf(fp, "%[^',']s", &combine[i].person.I.department[-1]); /*Read for department*/
			fscanf(fp, "%c", &ch); /*Read for ',' character after department*/
			fscanf(fp, "%s", combine[i].person.I.class_one);
			if(combine[i].person.I.class_one[strlen(combine[i].person.I.class_one)-1]==',')
				combine[i].person.I.class_one[strlen(combine[i].person.I.class_one)-1]='\0';
			fscanf(fp, "%s", combine[i].person.I.class_two);	
			if(combine[i].person.I.class_two[strlen(combine[i].person.I.class_two)-1]==',')
				combine[i].person.I.class_two[strlen(combine[i].person.I.class_two)-1]='\0';
			fscanf(fp, "%lf", &combine[i].person.I.salary);
			
			i++;
			number_of_person++;			
		}
		/*If person is employee*/
		else if(strcmp(type, "Employee")==0){
			combine[i].person_type='E';
			fscanf(fp, "%s", combine[i].person.E.name);
			fscanf(fp, "%s", combine[i].person.E.surname);
			if(combine[i].person.E.surname[strlen(combine[i].person.E.surname)-1]==',')
				combine[i].person.E.surname[strlen(combine[i].person.E.surname)-1]='\0';
			fscanf(fp, "%lf", &combine[i].person.E.salary);	
			do{
				fscanf(fp, "%c", &combine[i].person.E.degree);
				if(combine[i].person.E.degree=='\n'||combine[i].person.E.degree==' '||combine[i].person.E.degree==',')
					status=-1;
				else
					status=0;	
			}			
			while(status==-1);
		
			i++;
			number_of_person++;
		}
	}				
	
	buffer[0]='B'; /*For buffer problem*/
	
	fclose(fp);
	
	return number_of_person;	
}					

/*Takes array of person imformation, calculates salary rise*/ 
/*Updates array of person imformation and returns it*/		
combine_type salary_rise(combine_type person_info)
{
	/*If person is instructor*/
	if(person_info.person_type=='I'){
		person_info.person.I.salary+=(person_info.person.I.salary/100.0)*5.0;
		person_info.person.I.salary+=(person_info.person.I.salary/100.0)*5.3;
	}
	/*If person is employee*/
	else if(person_info.person_type=='E'){
		
		if(person_info.person.E.degree=='a')
			person_info.person.E.salary+=(person_info.person.E.salary/100)*17.5;
		else if(person_info.person.E.degree=='b')
			person_info.person.E.salary+=(person_info.person.E.salary/100)*12.0;
		else if(person_info.person.E.degree=='c')
			person_info.person.E.salary+=(person_info.person.E.salary/100)*9.0;
	
	}
	
	return person_info;
}			

/*############################################################################*/
/*               End of HW09_Furkan_Erdol_131044065_part1.c                   */
/*############################################################################*/
