/*############################################################################*/
/*HW03_Furkan_Erdol_131044065_part2.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on March 7, 2015                                    */
/*Description                                                                 */
/*____________                                                                */
/*This program evaluates the vertical distance of the bouncing ball           */
/*Program stops that when height is smaller than 1                            */
/*Prints the screen and writes result table to file                           */
/*Generates a random number between 10 to 40 for first height                 */
/*Generates a random number between 0.4 to 0.8 for ratio                      */
/*                                                                            */
/*Inputs:                                                                     */
/*  -No input value, the program generates first height and ratio             */
/*Outputs:                                                                    */
/*  -Rebouncing heights                                                       */
/*  -Total vertical distances                                                 */
/*  -How many times calculation                                               */
/*                                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#define limit_of_rebouncing_height 1 /*Limit of rebouncing height*/

/*Function prototypes*/
double calculate_the_new_height(double height, double ratio);
double calculate_the_vertical_distance(double height);
int count_the_number(int count);
double RNG1();
double RNG2();

int
main(void){

    double first_height, distance, ratio, height;
    int count=1;
    
    FILE *fp1;
    
    fp1 = fopen("Result_Table.txt", "w");
    
    /*Generates first_height and ratio, assigns first height to distance*/
    ratio = RNG2();
    first_height = RNG1();
    distance = first_height;
    
    /*Table headings*/
    printf("\nNo – The Rebounching Height -- The Total vertical Distance");
    printf("\n%d%6c%6.3f%23c%6.3f\n", count, ' ', first_height, ' ', distance);
    fprintf(fp1, "No – The Rebounching Height -- The Total vertical Distance");
    fprintf(fp1, "\n%d%6c%.3f%23c%.3f\n", count, ' ', first_height, ' ', distance);
    
    /*Assigns first height to distance*/
    height = first_height;
    
    /*If rebouncing height is higher than 1 the program continues as follows*/
    while (height*ratio>limit_of_rebouncing_height)
    {
    
    height = calculate_the_new_height(height, ratio);
    distance = distance+calculate_the_vertical_distance(height);
    count = count_the_number(count);
   
    printf("%d%5c%7.3f%23c%.3f\n", count, ' ', height, ' ', distance);
    fprintf(fp1, "%d%5c%7.3f%23c%.3f\n", count, ' ', height, ' ', distance);
    
    }
    
    printf("\nThe bouncing is stopped and the task completed...\n\n");
    printf("First height=%.2f\nRatio=%.2f\n\n", first_height, ratio);
        
    
    fclose(fp1);

    return 0;
}


/*Calculate rebouncing height*/
double calculate_the_new_height(double height, double ratio){
    
    double rebouncing_height;
    rebouncing_height =  height*ratio;
    
    return rebouncing_height;

}

/*Calculate the vertical distance*/
double calculate_the_vertical_distance(double height){
    
    double distance;
    
    distance = height*2;
    
    return distance;
}

/*Calculate loop counts*/
int count_the_number(int count){

    count ++;
    
    return count;
}

/*Generates double number between 10 to 40*/
double RNG1(){
    
    double x;
    srand(time(NULL));
    x = rand()%40+1;
    return(x);
}

/*Generates double number between 0.4 to 0.8*/
double RNG2(){

    double x;
    srand(time(NULL));
    x = (rand()%40+40)/100.0;
    return(x); 
}

/*############################################################################*/
/*               End of HW03_Furkan_Erdol_131044065_part2.c                   */
/*############################################################################*/
