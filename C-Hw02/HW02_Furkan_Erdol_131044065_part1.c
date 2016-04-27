/*############################################################################*/
/*HW02_Furkan_Erdol_131044065_part1.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on February 28, 2015                                */
/*Description                                                                 */
/*____________                                                                */
/*This program is guessing an integer number game                             */
/*Computer determines an integer number between 1 to 10                       */
/*Player tries to guessing that value                                         */
/*                                                                            */
/*Inputs:                                                                     */
/*  -An integer number between 1 to 10                                        */
/*Outputs:                                                                    */
/*  -Prints the screen instructions and comments                              */
/*  -If player doesn't guessing the number, number prints the screen          */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#include <stdlib.h>

int RNG();
int CalculateTheDifference(int x, int y);
void WarnThePlayer(int x);

int 
main(void){

    int number; 
    int guess;
    int result;
    
    /*Prints the screen instructions and comments*/
    printf("\nWELCOME");
    printf("\nI've got a number for you");
    printf("\nIs a number between 1 and 10");
    printf("\nCan you guess this number?");
    printf("\nI'm giving you two chances, good luck!");
    printf("\n\nEnter your guess:");
    
    /*Player's guess*/
    scanf("%d",&guess);
    
    /*The correct answer assign to number*/
    number = RNG();
    
    /*Calculates the difference between guess and correct number*/
    result = CalculateTheDifference(number, guess);
    
    /*Print screen the comment according to the result*/
    WarnThePlayer(result);
    
    /*If the guess is correct the program ends*/
    /*If the guess isn't correct player enter the second time guess*/
    if(result==0)
    return 0;
    else{
    printf("\n\nThis is your last chance:");
    scanf("%d",&guess);
    
    number = number;
    result = CalculateTheDifference(number, guess);
    
    if(guess==number)
    printf("---------------------CONGRATULATIONS!!!---------------------\n\n");
    else
    printf("\nI'm sorry, the correct number is:%d\n\n", number);
    }
    
    return 0;
}

/*This function determine an integer number between 1 to 10*/
int RNG(){
    
    int x;
    srand(time(NULL));
    x = rand()%10+1;
    return(x);
}

/*This function calculates the difference between guess and correct number*/
int CalculateTheDifference(int x, int y){
    
    int result;
    if(x>=y)
    result=x-y;
    else
    result=y-x;
    
    return(result);
}

/*This function prints the screen comments according to result*/    
void WarnThePlayer(int x){
    
    if(x>=5)
    printf("You are too far from the number");
    else if(x>=3)
    printf("You are far from the number");
    else if(x>=1)
    printf("You are close to the number");
    else
    printf("----------CONGRATULATIONS!!!----------\n\n");
}

/*############################################################################*/
/*               End of HW02_Furkan_Erdol_131044065_part1.c                   */
/*############################################################################*/

