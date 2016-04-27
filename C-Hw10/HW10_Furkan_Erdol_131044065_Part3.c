/*
 * HW10_Furkan_Erdol_131044065_Part3.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HW10_Furkan_Erdol_131044065_Part1.h"
#include "HW10_Furkan_Erdol_131044065_Part2.h"
#include "HW10_Furkan_Erdol_131044065_Part3.h"

/*Takes linked list of appointments and creates creates its copy*/
node_t* make_independent_copy_ll(node_t* head)
{
	node_t *curr, *copy_head=NULL;
	int counter=0;
	
	
	while(head!=NULL){
		counter++;
		/*First node of the linked list*/
		if(counter==1){
			copy_head=(node_t*)malloc(sizeof(node_t));
			copy_head->history=(char*)malloc(300*sizeof(char));
			copy_head->app_id=head->app_id;
			copy_head->patient_id=head->patient_id;
			strcpy(copy_head->name, head->name);
			strcpy(copy_head->history, head->history);
			copy_head->hour=head->hour;
			curr=copy_head;
		}
		/*Other nodes of the linked list*/
		else{
			curr->next=(node_t*)malloc(sizeof(node_t));
			curr=curr->next;
			curr->history=(char*)malloc(300*sizeof(char));
			curr->app_id=head->app_id;
			curr->patient_id=head->patient_id;
			strcpy(curr->name, head->name);
			strcpy(curr->history, head->history);
			curr->hour=head->hour;
		}
		
		head=head->next;
	
	}	
	
	curr->next=NULL;
	
	return copy_head;
}

/*Change the history information*/
void change_history(node_t* node, char* new_history)
{
	strcpy(node->history, new_history);
}	 		

/*############################################################################*/
/*                HW10_Furkan_Erdol_131044065_Part3.c                         */
/*############################################################################*/	
