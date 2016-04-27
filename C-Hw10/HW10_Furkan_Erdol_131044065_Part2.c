/*
 * HW10_Furkan_Erdol_131044065_Part2.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HW10_Furkan_Erdol_131044065_Part1.h"
#include "HW10_Furkan_Erdol_131044065_Part2.h"

/*Takes an integer array and hour searches whether hour*/
int check_time(int time[], int size, int hour)
{
	int i;
	int status=0; /*Finding status*/
	
	for(i=0;i<size;i++)
		if(time[i]==hour)
			status=-1;
	
	return status;
}			
			
/*Takes array of appointments and creates linked list of appointments*/
node_t* build_ll(Appointment_t appointments[], int size, const Working_hours_t* hours)
{
	node_t *head=NULL, *curr;
	int i, counter=0;
	int time[24]={0};

	
	for(i=0; i<size; i++){
		if(appointments[i].hour>=hours->start&&
		appointments[i].hour<=hours->end&&
		check_time(time, 24, appointments[i].hour)==0){
			counter++;
			/*First node of the linked list*/
			if(counter==1){
				head=(node_t*)malloc(sizeof(node_t));
				head->app_id=appointments[i].app_id;
    			head->patient_id=appointments[i].patient_id;
				head->name[0]='\0';
				head->history=NULL;
				head->hour=appointments[i].hour;
				curr=head;
			}
			/*Other nodes of the linked list*/
			else{
				curr->next=(node_t*)malloc(sizeof(node_t));
				curr=curr->next;	
				curr->app_id=appointments[i].app_id;
    			curr->patient_id=appointments[i].patient_id;
				curr->name[0]='\0';
				curr->history=NULL;
				curr->hour=appointments[i].hour;
			}
			
			time[i]=appointments[i].hour;
		}	
	}
	
	/*Last node*/
	curr->next=NULL;
	
	return head;
}	

/*Takes linked list of appointments and writes them into the file as cvs file*/
void write_accepted_app(node_t* head, const Files_t* files)
{
	FILE* fptr;
	int number=1; /*Appointment number*/
	
	fptr=fopen(files->accepted_appo_file_n, "w");
	
	while(head!=NULL){
		fprintf(fptr, "%d;", number++);
		fprintf(fptr, "%d;", head->app_id);
		fprintf(fptr, "%d;", head->patient_id);
		fprintf(fptr, "%s;", head->name);
		
		if(head->history==NULL)
			fprintf(fptr, ";");
		else	
			fprintf(fptr, "%s;", head->history);
		
		fprintf(fptr, "%d\n\n", head->hour);
		head=head->next;		
	}
	
	fclose(fptr);
}

/*Takes linked list and integer id searches id into the linled list*/
int search_in_ll(node_t* head, int id)
{
	int found=0;
	
	if(head!=NULL){
		if(head->patient_id==id)
			found=1;
		else
			found=search_in_ll(head->next, id);
	}
	
	return found;			
}

/*Takes linked list of appointments and patient informations*/
/*Reads personal data and records them into the linked list*/
void add_personal_data(node_t* head, const Files_t* files)
{
	FILE* fptr;
	char ch;
	int i;
	int counter=0;
	char first_line[20]; /*For first line*/
	int control;

	fptr=fopen(files->patients_file_n, "r");
	
	fgets(first_line, 10, fptr);

	while(control!=EOF&&head!=NULL){
		
		counter=0;
		do{
			control=fscanf(fptr, "%c", &ch);
			if(ch=='>')
				counter++;
		}while(counter!=2&&control!=EOF);
		
		if(control!=EOF){
			
			head->history=(char*)malloc(300*sizeof(char));
			
			fscanf(fptr, "%d", &head->patient_id);
			
			
			counter=0;
			do{
				fscanf(fptr, "%c", &ch);
				if(ch=='>')
					counter++;
			}while(counter!=2);	
		
			
			fscanf(fptr, "%c", &ch);
			i=0;
			while(ch!='<'){
				head->name[i++]=ch;
				fscanf(fptr, "%c", &ch);
			}
			head->name[i]='\0';		
		
			
			counter=0;
			do{
				fscanf(fptr, "%c", &ch);
				if(ch=='>')
					counter++;
			}while(counter!=2);	
	
	
			fscanf(fptr, "%c", &ch);
			i=0;
			while(ch!='<'){
				head->history[i++]=ch;
				fscanf(fptr, "%c", &ch);
			}
			head->history[i]='\0';

			
			counter=0;
			do{
				fscanf(fptr, "%c", &ch);
				if(ch=='>')
					counter++;
			}while(counter!=2);
			
			head=head->next;
			
		}
	}

	fclose(fptr);	
}

/*Deletes all records in the delete file from the linked list*/
/*Returns the number of appointments deleted*/
int delete_appointments(node_t** head, const Files_t* files)
{
	FILE* fptr;
	int delete;
	node_t *currP, *prevP;
	int counter=0;
	
	fptr=fopen(files->delete_file_n, "r");
	
	while(fscanf(fptr, "%d", &delete)!=EOF){
	
		prevP=NULL;
		currP=*head;
	
		while(currP!=NULL){
			
			if(currP->app_id==delete){
				
				if(prevP==NULL)
					*head=currP->next;
				else
					prevP->next=currP->next;
					
				free(currP);
				counter++;
			}
			
			prevP=currP;		
			currP=currP->next;
						
		}
	}			

	fclose(fptr);
	
	return counter;
}

/*Frees reserved place in memory for linked list of appointments*/
void free_list(node_t* head)
{
	node_t* temp;
	
	while(head!=NULL){
		temp=head;
		head=head->next;
		free(temp->history);
		free(temp);
	}	
}

/*Takes linked list and prints the screen first node*/
void write_appo_node(node_t* head)
{
	printf("\n<<<<<<<<<<<<<<PATIENT>>>>>>>>>>>>>>\n");
	printf(">>>App id: %d\n", head->app_id);
	printf(">>>Patien_id: %d\n", head->patient_id);
	printf(">>>Name: %s\n", head->name);
	printf(">>>History: %s\n", head->history);
	printf(">>>Hour: %d\n\n", head->hour);
}

/*############################################################################*/
/*                HW10_Furkan_Erdol_131044065_Part2.c                         */
/*############################################################################*/	
