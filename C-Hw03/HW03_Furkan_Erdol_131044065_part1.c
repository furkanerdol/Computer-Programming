/*############################################################################*/
/*HW03_Furkan_Erdol_131044065_part1.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on March 7, 2015                                    */
/*Description                                                                 */
/*____________                                                                */
/*This program is guessing an integer number game                             */
/*Firstly asks if you want to play                                            */
/*Computer determines an integer number between 1 to 10                       */
/*Player tries to guessing that value                                         */
/*Players can guess as much as players want                                   */
/*Program will continue until guess be correct                                */
/*                                                                            */
/*Inputs:                                                                     */
/*  -An integer number between 1 to 10                                        */
/*  -Character 'P','p' or 'E','e'                                             */
/*Outputs:                                                                    */
/*  -Prints the screen instructions and comments                              */
/*  -Asks if you want to play                                                 */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#include <stdlib.h>

/*Function prototypes*/
int RNG();
int CalculateTheDifference(int x, int y);
void WarnThePlayer(int x);


int
main(void)
{

    char choose; /*Player's choice to play the game*/ 
    int number; /*The correct number of 1 to 10*/
    int guess; /*Player's guess*/
    int result; /*Difference between guess and number*/
    int number_of_guessesA; /*Count number of guesses*/
    int number_of_guessesB; /*Count number of guesses*/
    
    printf("\nWELCOME");
    printf("\nI've got a number for you");
    printf("\nIs a number between 1 to 10");
    printf("\nCan you guess this number?");
    printf("\nIf you know it, you can continue for new one");
    
    /*Input character, player's choice*/
    printf("\n\nIf you want to play game enter 'P', don't want play enter 'E'");
    scanf("%c", &choose);
    
    /*If input character is 'E' or 'e', the program ends*/ 
    if(choose=='E'||choose=='e')
    return 0;
    
    /*If input character is 'P' or 'p', the program continues as follows*/ 
    number_of_guessesA = 1;   
    while(choose=='p'||choose=='P')
    {
    
        printf("\n\nEnter your guess: ");
        scanf("%d", &guess);
        
        number = RNG();
        result = CalculateTheDifference(number, guess);
        WarnThePlayer(result);
        
        if(result==0)
        {
        printf("\n*****Number of guesses: %d*****", number_of_guessesA);
        printf("\n\nIf you want to play game enter 'P', don't want play enter 'E'");
        scanf(" %c", &choose);
        }
        
        /*If first guess isn't correct the program continues as follows*/ 
        number_of_guessesB = 1;
        while (result!=0)
        {
            
            printf("\n\nEnter your guess: ");
            scanf("%d", &guess);
            
            number = number;
            result = CalculateTheDifference(number, guess);
            WarnThePlayer(result);
            
            ++ number_of_guessesB;
            
            if(result==0)
            {
            printf("\n*****Number of guesses: %d*****", number_of_guessesB);
            printf("\n\nIf you want to play game enter 'P', don't want play enter 'E'");
            scanf(" %c", &choose);
            }
        }
        
    }
    
    
    return 0;
}


/*This function determine an integer number between 1 to 10*/
int RNG()
{
    int x;
    srand(time(NULL));
    x = rand()%10+1;
    return(x);
}

/*This function calculates the difference between guess and correct number*/
int CalculateTheDifference(int x, int y)
{
    int result;
    if(x>=y)
    result=x-y;
    else
    result=y-x;
    
    return(result);
}


/*This function prints the screen comments according to result*/   
void WarnThePlayer(int x)
{
    
    if(x>=5)
    printf("You are too far from the number");
    else if(x>=3)
    printf("You are far from the number");
    else if(x>=1)
    printf("You are close to the number");
    else
    printf("#######################CONGRATULATIONS!!!#######################");
}

/*############################################################################*/
/*               End of HW03_Furkan_Erdol_131044065_part1.c                   */
/*############################################################################*/

