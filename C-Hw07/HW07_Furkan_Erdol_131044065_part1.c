/*############################################################################*/
/*HW07_Furkan_Erdol_131044065_part1.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on April 8, 2015                                    */
/*Description                                                                 */
/*____________                                                                */
/*                                                                            */
/*Finds and returns size of a string                                          */  
/*Finds how many times a given string is used in a given string               */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Strings                                                                  */
/*Outputs:                                                                    */
/*  -Size of a string                                                         */
/*  -Number of occurrence                                                     */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>

/*Function prototypes*/
int find_size(const char *string);
int char_number(const char *string, const char *wish_to_find);

int
main(void)
{
    char string[10]="Furkan";
    char big_string[50]="GTU is good, GTU is hard, GTU is big";
    char small_string[10]="GTU";
    int size; /*Size of a string*/
    int occ; /*Number of occurrence*/
    
    /*Calls find_size function and finds size of string*/ 
    size=find_size(string);
    printf("\n%s\nSize of string=%d",string, size);
    
    /*Calls char_number function and finds number of occurrence*/ 
    occ=char_number(big_string, small_string);
    printf("\n\n%s\nNumber of occurrence %s=%d\n\n",big_string,small_string, occ);
    
    return 0;
}

/*This recursive function that finds and returns size of a string*/
int find_size(const char *string){
    int size; /*Size of a string*/
    
    if(string[0]=='\0')
        size=0;
    else
        size=1+find_size(&string[1]);
        
    return size;
}        

/*This recursive function finds how many times a given string is used in a given string*/
int char_number(const char *string, const char *wish_to_find){
    int occ; /*Number of occurrence*/

    if(string[0]=='\0')
        occ=0;
    else if(strncmp(&string[0], wish_to_find, find_size(wish_to_find))==0)
        occ=1+char_number(&string[1], wish_to_find);
    else
        occ=0+char_number(&string[1], wish_to_find);
                
    return occ;
}        
/*############################################################################*/
/*                End of HW07_Furkan_Erdol_131044065_part1.c                  */
/*############################################################################*/
