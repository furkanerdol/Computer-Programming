/*############################################################################*/
/*HW03_Furkan_Erdol_131044065_part3.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on March 7, 2015                                    */
/*Description                                                                 */
/*____________                                                                */
/*This program:                                                               */
/*  -Print the screen vertical diagram of a bouncing ball                     */
/*  -Calculate length of the diagram axis                                     */
/*  -Calculate total number of character                                      */
/*                                                                            */
/*Inputs:                                                                     */
/*  -First height                                                             */
/*  -Feet height                                                              */
/*  -Peak point                                                               */
/*  -Road point                                                               */
/*Outputs:                                                                    */
/*  -Print the screen steps of bouncing ball                                  */
/*  -Total number of character                                                */
/*                                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>

/*Function prototypes*/
int draw_ver_diag_of_bb(int first_height, int feet_height, char the_peak_point, char the_road_point);
int draw_diag_step( int height, int feet_height, char the_peak_point, char the_road_point);
int lenght_function(int first_height, int feet_height);
int finish_diag(int length);

int
main(void)
{

    int first_height; /*Length of first hight*/
    int feet_height; /*Length of feet hight*/
    int length; /*The length of the diagram axis*/
    int total_ch; /*Total number of characters*/
    char the_peak_point; /*Peak point*/
    char the_road_point; /*Road point*/
    
/*############################FIRST TIME CALLING##############################*/    
    /*Input values*/ 
    printf("\n<<<<<<<<<For first ball>>>>>>>>>");
    printf("\nPlease enter the first_height of the ball: ");
    scanf("%d", &first_height);
    printf("Please enter the feet_height of the ball: ");
    scanf("%d", &feet_height);
    printf("Please enter the the_peak_point of the ball: ");
    scanf(" %c", &the_peak_point);
    printf("Please enter the the_road_point of the ball: "); 
    scanf(" %c", &the_road_point);
    
    /*Print the screen steps of bouncing ball and return total number of characters*/
    total_ch = draw_ver_diag_of_bb(first_height, feet_height, the_peak_point, the_road_point);
    
    /*The length of the diagram axis*/
    length = lenght_function(first_height, feet_height);
    
    /*Print the screen diagram axis*/
    finish_diag(length);
    
    printf("\n\nTotal number of characters: %d\n\n", total_ch);

/*############################SECOND TIME CALLING#############################*/    
    /*Input values*/ 
    printf("<<<<<<<<<For second ball>>>>>>>>>");
    printf("\nPlease enter the first_height of the ball: ");
    scanf("%d", &first_height);
    printf("Please enter the feet_height of the ball: ");
    scanf("%d", &feet_height);
    printf("Please enter the the_peak_point of the ball: ");
    scanf(" %c", &the_peak_point);
    printf("Please enter the the_road_point of the ball: "); 
    scanf(" %c", &the_road_point);
    
    /*Print the screen steps of bouncing ball and return total number of characters*/
    total_ch = draw_ver_diag_of_bb(first_height, feet_height, the_peak_point, the_road_point);
    
    /*The length of the diagram axis*/
    length = lenght_function(first_height, feet_height);
    
    /*Print the screen diagram axis*/
    finish_diag(length);
    
    printf("\n\nTotal number of characters: %d\n\n", total_ch);

/*############################THIRD TIME CALLING##############################*/    
    /*Input values*/ 
    printf("<<<<<<<<<For third ball>>>>>>>>>");
    printf("\nPlease enter the first_height of the ball: ");
    scanf("%d", &first_height);
    printf("Please enter the feet_height of the ball: ");
    scanf("%d", &feet_height);
    printf("Please enter the the_peak_point of the ball: ");
    scanf(" %c", &the_peak_point);
    printf("Please enter the the_road_point of the ball: "); 
    scanf(" %c", &the_road_point);
    
    /*Print the screen steps of bouncing ball and return total number of characters*/
    total_ch = draw_ver_diag_of_bb(first_height, feet_height, the_peak_point, the_road_point);
    
    /*The length of the diagram axis*/
    length = lenght_function(first_height, feet_height);
    
    /*Print the screen diagram axis*/
    finish_diag(length);
    
    printf("\n\nTotal number of characters: %d\n\n", total_ch);
     
   
    
    return 0;
    
}


/*Print the screen vertical steps bouncing ball*/
/*Return total number of characters*/
int draw_ver_diag_of_bb(int first_height, int feet_height, char the_peak_point, char the_road_point)
{

    int count=1; /*Count number*/
    int total_ch=0; /*Total number of characters*/
    
    printf("\n^\n");
    
    for(count=1; count<=first_height; first_height--)
    {
    
        total_ch=total_ch+draw_diag_step(first_height, feet_height, the_peak_point, the_road_point);
        
    }

    return total_ch;

}

/*Print the screen one step of bouncing ball*/
int draw_diag_step( int height, int feet_height, char the_peak_point, char the_road_point)
{

    int count_h=1; /*Count number*/
    int count_f=1; /*Count number*/
    int total_ch=0; /*Total number of characters*/
    int count_s=1; /*Count of space character*/
    
    printf("|");
    
    for(count_h=1; count_h<=height; count_h++)
    {
        
        for(count_f=1; count_f<=feet_height; count_f++)
        {
           
            printf("%c", the_road_point);
            total_ch++;
        }
    
    printf("\n|");
    
        for(count_f=1; count_f<=feet_height*count_s; count_f++)
        {
            printf(" ");
        }
    
    count_s++;
    
    }
    
    printf("%c", the_peak_point);
    total_ch++;
    
    for(count_h=1; count_h<=height; count_h++)
    {
    
        printf("\n|");
    
        for(count_f=1; count_f<=(count_s-2)*feet_height; count_f++)
        {
            printf(" ");
        
        }
    
        for(count_f=1; count_f<=feet_height; count_f++)
        {
            printf("%c", the_road_point);
            total_ch++;
        }
    
    count_s--;

    }
    
    printf("\n");
    
    return total_ch++;
   
}
     

/*Calculate the length of the diagram axis*/
/*Use first height and and feet height*/
int lenght_function(int first_height, int feet_height)
{

    int length; /*The length of the diagram axis*/
    
    length = first_height*feet_height+1;
    
    return length;

}


/*Print the screen diagram axis*/
/*Print "-" length up diagram axis*/
int finish_diag(int length)
{

    int count; /*Count number*/

    printf("L");
    
    for(count=0; count<length; count++)
    {
        printf("-");
    }
    
    printf(">");
    
    if(count==length)
    return 1;
    else
    return 0;
    
}

/*############################################################################*/
/*               End of HW03_Furkan_Erdol_131044065_part3.c                   */
/*############################################################################*/
