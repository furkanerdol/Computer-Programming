/*############################################################################*/
/*HW03_Furkan_Erdol_131044065_bonusPart.c                                     */
/*______________________________                                              */
/*Written by Furkan Erdol on March 8, 2015                                    */
/*Description                                                                 */
/*____________                                                                */
/*This program:                                                               */
/*  -Print the screen horizontal diagram of a bouncing ball                   */
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
int draw_hor_diag_of_bb(int first_height, int feet_height, char the_peak_point, char the_road_point);
int lenght_function(int first_height);
int finish_diag(int length);


int
main (void)
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
    total_ch = draw_hor_diag_of_bb(first_height, feet_height, the_peak_point, the_road_point);
    
    /*The length of the diagram axis*/
    length = lenght_function(first_height);
    
    /*Print the screen diagram axis*/
    finish_diag(length);
    
    printf("\n\nTotal number of characters: %d\n\n", total_ch);
    
/*############################SECOND TIME CALLING#############################*/    
    /*Input values*/ 
    printf("\n<<<<<<<<<For second ball>>>>>>>>>");
    printf("\nPlease enter the first_height of the ball: ");
    scanf("%d", &first_height);
    printf("Please enter the feet_height of the ball: ");
    scanf("%d", &feet_height);
    printf("Please enter the the_peak_point of the ball: ");
    scanf(" %c", &the_peak_point);
    printf("Please enter the the_road_point of the ball: "); 
    scanf(" %c", &the_road_point);
    
    /*Print the screen steps of bouncing ball and return total number of characters*/
    total_ch = draw_hor_diag_of_bb(first_height, feet_height, the_peak_point, the_road_point);
    
    /*The length of the diagram axis*/
    length = lenght_function(first_height);
    
    /*Print the screen diagram axis*/
    finish_diag(length);
    
    printf("\n\nTotal number of characters: %d\n\n", total_ch);    
    
/*############################THIRD TIME CALLING##############################*/    
    /*Input values*/ 
    printf("\n<<<<<<<<<For third ball>>>>>>>>>");
    printf("\nPlease enter the first_height of the ball: ");
    scanf("%d", &first_height);
    printf("Please enter the feet_height of the ball: ");
    scanf("%d", &feet_height);
    printf("Please enter the the_peak_point of the ball: ");
    scanf(" %c", &the_peak_point);
    printf("Please enter the the_road_point of the ball: "); 
    scanf(" %c", &the_road_point);
    
    /*Print the screen steps of bouncing ball and return total number of characters*/
    total_ch = draw_hor_diag_of_bb(first_height, feet_height, the_peak_point, the_road_point);
    
    /*The length of the diagram axis*/
    length = lenght_function(first_height);
    
    /*Print the screen diagram axis*/
    finish_diag(length);
    
    printf("\n\nTotal number of characters: %d\n\n", total_ch);                    
    

    return 0;
    
} 
    
/*Print the screen horizontal steps bouncing ball*/
/*Return total number of characters*/    
int draw_hor_diag_of_bb(int first_height, int feet_height, char the_peak_point, char the_road_point)
{
    
    int length;
    int total_ch;
    int middle_space;
    int before_peak_point;
    int number_intermediate_lines;
    int between_columns;
    int for_repetition;
    int count1, count2, count3, count4, count5, count6, count7, count8, count9;
    int count_peak_point, count_intermediate_lines, count_first_height, count_middle_space;
    
    
    before_peak_point=(first_height-1)*2;
    number_intermediate_lines=first_height-2;
    between_columns=number_intermediate_lines*2+2;
    count_intermediate_lines=0;
    count_first_height=first_height;
    middle_space=1;
    total_ch=0;
    for_repetition=0;
    count_peak_point=1;
    
    
    printf("^\n|");
    for(count1=1;count1<=first_height;count1++)
    {
        printf(" ");
        
    }
        
    printf("%c\n",the_peak_point);
    total_ch++;
    
    for(count2=1;count2<=first_height;count2++)
    {
    
    
        for(count3=1;count3<=feet_height;count3++)
        {
            printf("|");
            
            for(count4=1;count4<=count_first_height-1;count4++)
            {
                printf(" ");
            }
        
            printf("%c",the_road_point);
            total_ch++;
            
            for(count5=1;count5<=middle_space;count5++)
            {
                printf(" ");
            }
            
            printf("%c",the_road_point);
            total_ch++;
            
            count_middle_space=middle_space-2;
            for(count6=1;count6<=for_repetition;count6++)
            {
                if(count_intermediate_lines>0&count_intermediate_lines<=number_intermediate_lines+1)
                {    
                    for(count7=1;count7<=between_columns;count7++)
                    {
                        printf(" ");
                    }
                
                    printf("%c",the_road_point);
                    total_ch++;
                
                    for(count8=1;count8<=count_middle_space;count8++)
                    {
                        printf(" ");
                    }
                    
                    count_middle_space-=2;
                    printf("%c",the_road_point);
                    total_ch++;
                }
            }
            
            while(count_peak_point==feet_height)
            {
                for(count9=1;count9<=before_peak_point;count9++)
                {
                    printf(" ");
                }
           
                if(before_peak_point!=0)
                { 
                printf("%c",the_peak_point);
                total_ch++;
                before_peak_point-=2;
                }
        
                count_peak_point++;
            
            }
            
            printf("\n");
            count_peak_point++;    
        }
        
        count_intermediate_lines++;
        middle_space+=2;
        count_first_height--;
        
        between_columns-=2;
        for_repetition++;
        count_peak_point=1;
        
    }
        
        
    return total_ch;

}
        
/*Calculate the length of the diagram axis*/
int lenght_function(int first_height)
{

    int length;
    int first_height_A=first_height;
    
    length=0;
    
    while(first_height!=0)
    {
        length+=first_height;
        first_height--;
    }
    
    length=length*2+first_height_A;
    
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
/*               End of HW03_Furkan_Erdol_131044065_bonusPart.c               */
/*############################################################################*/
