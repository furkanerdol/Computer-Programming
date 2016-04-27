/*############################################################################*/
/*HW05_Furkan_Erdol_131044065_part1.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on March 22, 2015                                   */
/*Description                                                                 */
/*____________                                                                */
/*                                                                            */
/*<<<This is a car crash simulation program, for two cars                     */  
/*<<<Gives inputs from console and prints the screen car crash simulation     */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Car names                                                                */
/*  -Car speeds                                                               */
/*  -Car weights                                                              */
/*Outputs:                                                                    */
/*  -Prints the screen car crash simulation                                   */
/*                                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#define ROAD_LENGTH 50 /*Define road legnth*/

/*Define enumarated type*/
typedef enum
 {PLAY, CRASH, END}
object_state;

/*Function prototypes*/

/*Calculates crash time. Gives positions and speeds returns crash time*/
double car_crash_time(double position1, double position2, double speed1, double speed2);
/*Two cars collides and move according to inealistic collision. This function *
 *calculate car positions and after collision speed and prints the screen     *
 *simulation.                                                                 *
 *Car names, speeds, positions and game state are input-output parameter      */
void make_move(char *object1, double *position1, double *speed1, int weight1, 
               char *object2, double *position2, double *speed2, int weight2, object_state *game_state);
/*Gives car names, positions and game state, prints the screen car crash simulation*/
void print_game_state(char object1, double position1, char object2, double position2, object_state game_state);


int
main(void)
{

    char object1, object2; /*Car names*/
    double position1=0, position2=ROAD_LENGTH; /*Car positions*/
    double speed1, speed2; /*Car speeds*/ 
    int weight1, weight2; /*Car weights*/
    int i;
    object_state game_state; /*Game state*/
    
    /*Input values for car 1*/
    printf("\nEnter name of car 1:");
    scanf(" %c", &object1);
    printf("\nEnter speed of car 1:");
    scanf("%lf", &speed1);
    printf("\nEnter weight of car 1:");
    scanf("%d", &weight1);
    
    /*Input values for car 2*/
    printf("\nEnter name of car 2:");
    scanf(" %c", &object2);
    printf("\nEnter speed of car 2:");
    scanf("%lf", &speed2);
    printf("\nEnter weight of car 2:");
    scanf("%d", &weight2);
    
    game_state=PLAY;
    
    /*Call make move function*/
    make_move(&object1,  &position1, &speed1,  weight1, &object2,  &position2, &speed2,  weight2, &game_state);
    
    
    
    return 0;
}


/*Calculates crash time. Gives positions and speeds returns crash time*/
double car_crash_time(double position1, double position2, double speed1, double speed2)
{

    double crash_time; /*Crash time*/
    
    if(speed1>0&&speed2<0)
        crash_time=(position2-position1)/(speed1-speed2);
    else if(speed1>0&&speed2>0)
        crash_time=(position2-position1)/(speed1);
    else if(speed1<0&&speed2>0)
        crash_time=(position2-position1)/(ROAD_LENGTH);
    else if(speed1<0&&speed2<0)
        crash_time=(position2-position1)/(-speed2);
        
    return crash_time;
}

/*Two cars collides and move according to inealistic collision. This function *
 *calculate car positions and after collision speed and prints the screen     *
 *simulation.                                                                 *
 *Car names, speeds, positions and game state are input-output parameter      */
void make_move(char *object1, double *position1, double *speed1, int weight1, 
               char *object2, double *position2, double *speed2, int weight2, object_state *game_state)
               
{
    int i;
    int count=0; /*Counts for crash time*/
    double crash_time; /*Crash time*/
    double speed; /*Inelastic collision result, speed*/
    
    /*Call crash time function and assign it*/
    crash_time=car_crash_time(*position1, *position2, *speed1, *speed2);
    
    while(*game_state==PLAY)
    {
        /*Call print game state function for prints the screen*/
        print_game_state(*object1,  *position1,  *object2,  *position2, *game_state);
        
        /*Change the car positions according to speeds*/
        *position1+=*speed1;
        *position2+=*speed2;
        
        count++;
        
        /*Change game state when cars collide*/
        if(count>=crash_time)
        {
            *position1-=*speed1;
            *position2-=*speed2;
            *game_state=CRASH; /*Update game state*/
        }    
    }
    
    /*Calculate new speed after crash according to inealistic collision*/
    speed=((*speed1*weight1)+(*speed2*weight2))/(weight1+weight2);
    
    *speed1=speed;/*New speed assign to car 1 speed*/ 
    *speed2=speed;/*New speed assign to car 2 speed*/
    
    /*Assign character 'X' to car names*/
    *object1='X';
    *object2='X';
    
    while(*game_state==CRASH)
    {
        /*Call print game state function for prints the screen*/
        print_game_state(*object1,  *position1,  *object2,  *position2, *game_state);
        
        /*Change game state when cars finish their routes*/
        if(*position1<=0||*position1>=ROAD_LENGTH-1||*position2>ROAD_LENGTH||speed==0)
            *game_state=END; /*Update game state*/
        
        *position1+=speed;
    }        
    
}

/*Gives car names, positions and game state, prints the screen car crash simulation*/
void print_game_state(char object1, double position1, char object2, double position2, object_state game_state)
{
    int i;
    
    /*Prints the screen before collision*/
    if(game_state==PLAY)
    {
        printf("\n");
       
        for(i=0;i<position1;i++)
            printf("_");
       
        printf("%c", object1);
       
        if(position1>=0&&position2<=ROAD_LENGTH)
        {
            for(i=0;i<(position2-position1)-2; i++)
                printf("_");
        }
        
        else if(position1<0&&position2<ROAD_LENGTH)
        {
            for(i=0;i<position2-2; i++)
                printf("_");
        }
        
        else if(position1>0&&position2>ROAD_LENGTH)
        {
            for(i=0;i<(ROAD_LENGTH-position1)-2; i++)
                printf("_");          
        }
        
        else if(position1<0&&position2>ROAD_LENGTH)
        {
            for(i=0;i<ROAD_LENGTH-2; i++)
                printf("_");     
        }
       
        if(position1<ROAD_LENGTH-1)
        printf("%c", object2);
        
        for(i=0;i<ROAD_LENGTH-position2;i++)
            printf("_");
    }
    
    /*Prints the screen after collision*/
    if(game_state==CRASH)
    {
        printf("\n");
        
        for(i=0;i<position1;i++)
            printf("_");
        
        printf("%c", object1);
        
        for(i=0;i<ROAD_LENGTH-position1-1;i++)
            printf("_");
    }           
    
    printf("\n12345678901234567890123456789012345678901234567890");
    printf("\n");
}      

/*############################################################################*/
/*                End of HW05_Furkan_Erdol_131044065_part1.c                  */
/*############################################################################*/             
