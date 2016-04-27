/*############################################################################*/
/*HW05_Furkan_Erdol_131044065_part2.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on March 22, 2015                                   */
/*Description                                                                 */
/*____________                                                                */
/*                                                                            */
/*<<<Gives one array and finds and prints the screen:                         */  
/*  -Maximum value                                                            */
/*  -Maximum second value                                                     */
/*  -Sum of all array                                                         */
/*  -How many times the value entered is repeated                             */
/*  -The location of the valeu entered                                        */
/*                                                                            */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Input array                                                              */
/*  -Value for counting                                                       */
/*  -Valeue for searching                                                     */
/*Outputs:                                                                    */
/*  -Maxiumum number in array                                                 */
/*  -Maxiumum second number in array                                          */
/*  -Sum of all array                                                         */
/*  -How many times the number entered is repeated                            */
/*  -The location of the number entered                                       */
/*                                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#define SIZE 9 /*Size of input array*/

/*Define enumarated type*/
typedef enum
 {FALSE=0, TRUE=1}
bool; 

/*Function prototypes*/ 

/*Finds max number in array*/
int max_array(const int array[], int n);
/*Finds second max number in array*/
int second_max_array(const int array[], int n);
/*Finds sum of all array*/
int sum_all_array (const int array[], int n);
/*Finds how many times the number entered is repeated*/
int count_array(const int array[], int n, int value);
/*Finds the location of the number entered and prints the screen*/
bool search_array(const int array[], int n, int value);


int
main(void)
{
    /*Inputs*/
    int count_of_value1=6, /*Input for counting*/
        count_of_value2=8, /*Input for counting*/
        count_of_value3=3, /*Input for counting*/
        search_value1=2, /*Input for searching*/
        search_value2=8, /*Input for searching*/
        search_value3=12; /*Input for searching*/
    int myarray[SIZE]={6,8,3,3,12,8,3,8,2}; /*Input array*/
    /*Outputs*/
    int max, /*Maximum number in array*/
        second_max, /*Maximum second number in array*/
        sum, /*Sum of all array*/
        count, /*How many times the number entered is repeated*/
        search; /*the location of the number entered*/
    
    
    /*Finds max number in array and prints the screen*/
    printf("\n++++++++++++++++++++++++++++++");
    max=max_array(myarray, SIZE);
    printf("\nMaximum array is: %d",max);
    
    /*Finds second max number in array and prints the screen*/
    printf("\n++++++++++++++++++++++++++++++");
    second_max=second_max_array(myarray, SIZE);
    printf("\nMaximum second array is: %d",second_max);
    
    /*Finds sum of all array and prints the screen*/
    printf("\n++++++++++++++++++++++++++++++");
    sum= sum_all_array (myarray, SIZE);
    printf("\nSum of all array is: %d",sum);    

    /*Finds how many times the number entered is repeated and prints the screen*/
    /*This procedure is done three times*/
    printf("\n++++++++++++++++++++++++++++++");
    count=count_array(myarray, SIZE, count_of_value1);
    printf("\nCount of value %d is: %d",count_of_value1, count);
    count=count_array(myarray, SIZE, count_of_value2);
    printf("\nCount of value %d is: %d",count_of_value2, count);
    count=count_array(myarray, SIZE, count_of_value3);
    printf("\nCount of value %d is: %d",count_of_value3, count);

    /*Finds the location of the number entered and prints the screen*/
    /*Gives an error message if the number entered does not exist*/
    /*This procedure is done three times*/
    printf("\n++++++++++++++++++++++++++++++");
    search=search_array(myarray, SIZE, search_value1);
    if(search==FALSE)
        printf("\nNumber couldn't foun!");
    search=search_array(myarray, SIZE, search_value2);
    if(search==FALSE)
        printf("\nNumber couldn't foun!");
    search=search_array(myarray, SIZE, search_value3);
    if(search==FALSE)
        printf("\nNumber couldn't foun!");
    printf("\n++++++++++++++++++++++++++++++\n");    
        

    return 0;

}

/*Finds max number in array*/
int max_array(const int array[], int n)
{

    int i,
        max=0; /*Maximum number in array*/
    
    for(i=0;i<n;i++)
    {
        if(array[i]>max)
            max=array[i];
    }    
        
    return max;
}

/*Finds second max number in array*/
int second_max_array(const int array[], int n)
{

    int i,
        max, /*Maximum number in array*/
        second_max=0; /*Maximum second number in array*/
    
    max=max_array(array, n); /*Calls max array function for give maximum number*/
    
    for(i=0;i<n;i++)
    {
        if(array[i]>second_max&&array[i]<max)
            second_max=array[i];
    }    
            
        
    return second_max;
    
}        

/*Finds sum of all array*/
int sum_all_array (const int array[], int n)
{

    int i,
        sum=0; /*Sum of all array*/
    
        for(i=0;i<n;i++)
            sum+=array[i];
            
    return sum;        
            
            
}

/*Finds how many times the number entered is repeated*/
int count_array(const int array[], int n, int value)

{

    int i,
        count=0; /*Counts how many times the number entered is repeated*/
    
    for(i=0;i<n;i++)
    {
        if(array[i]==value)
            count++;
    }       
            
    return count;

}

/*Finds the location of the number entered and prints the screen*/
/*If have more than one of the same number, prints the screen first place*/
bool search_array(const int array[], int n, int value)
{

    int i,
        count=0; /*Counts whether number is or not*/ 
        
    for(i=0;i<n;i++)
    {
        if(array[i]==value&&count==0)
        {
            printf("\n%d is at [%d]",value, i);
            count++;
        }       
    }
    
    /*If there are number entered return TRUE otherwise return FALSE*/
    if(count==1)
        return TRUE;
    else
        return FALSE;           
    
}

/*############################################################################*/
/*                End of HW05_Furkan_Erdol_131044065_part2.c                  */
/*############################################################################*/    
