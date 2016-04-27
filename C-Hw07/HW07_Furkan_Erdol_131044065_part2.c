/*############################################################################*/
/*HW07_Furkan_Erdol_131044065_part2.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on April 9, 2015                                    */
/*Description                                                                 */
/*____________                                                                */
/*                                                                            */
/*  This program calculate in how many distinct ways you can climb to the top */
/*and to print it on the screen                                               */
/*Steps as follow: One stair at a time or two stairs at a time                */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Number of stairs                                                         */
/*Outputs:                                                                    */
/*  -Number of distinct ways                                                  */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>

/*Function prototypes*/
int combination(int n , int k);
int ways(int n);
int ways_rec(int x, int y);

int
main(void)
{
    int total_ways; /*Total number of ways*/
    int number_of_stairs; /*Number of stairs*/
    
    /*Takes number of stairs from console*/
    printf("\nEnter number of stairs:");
    scanf("%d", &number_of_stairs);
    
    /*Calculate total number of distinct ways*/ 
    total_ways=ways(number_of_stairs);
    
    /*Prints result on the screen*/
    printf("\nYou can climb in %d different ways\n\n", total_ways);

    return 0;
}

/*This recursive function to calculate combination “n choose k” and returns the result*/
int combination(int n , int k)
{
    int result; /*Combination result*/
   
    if(k<0||k>n)
        result=0;
    else if(k<1)
        result=1; 
    else if(n==k)
        result=1;
    else
        result=combination(n-1,k)+combination(n-1,k-1);        
    
    return result;
}

/*This funtion calls ways_rec function and returns it*/
int ways(int n)
{
    return  ways_rec(n, n-n);        
}

/*This recursive function to calculate and return total number of ways*/
int ways_rec(int x, int y)
{
    int result; /*Total number of ways*/
    
    if(x<y)
        result=0;
    else
        result=combination(x,y)+ways_rec(x-1, y+1);
        
    return result;         
}    

/*############################################################################*/
/*                End of HW07_Furkan_Erdol_131044065_part2.c                  */
/*############################################################################*/
