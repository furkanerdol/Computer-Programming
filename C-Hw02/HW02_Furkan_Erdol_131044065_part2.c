/*############################################################################*/
/*HW02_Furkan_Erdol_131044065_part2.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on February 28, 2015                                */
/*Description                                                                 */
/*____________                                                                */
/*Calculated according to the midterm1 midterm2, final;                       */
/*  -Average grades                                                           */
/*  -Letter grades                                                            */
/*  -Contribution of GPA                                                      */
/*Input values ​​read from Students.txt                                         */
/*Output values ​​are written to Grades.txt                                     */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Student name and surname,                                                */
/*  -Midterm1, midterm2 and final points                                      */
/*Outputs:                                                                    */
/*  -Average grades and contributions of GPA                                  */
/*                                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>

int calculate_grade(int mid1, int mid2, int final);
char grade_to_latter_grade(int x);
double contribution_GPA(char lgrade);

int
main(void){

    int mid1, mid2, final,grade; /*Midterm1, midterm2, final and average grade*/
    double contribution; /*Contribution of GPA*/
    char name, surname, lgrade; /*Name, surname and latter grade*/
    FILE *fp1, *fp2;
    
    fp1 = fopen("Students.txt", "r");
    fp2 = fopen("Grades.txt", "w");

/********************************STUDENT 1*************************************/    
    
    /*Read input values from Stındents.txt*/
    fscanf(fp1, "%c%c%d%d%d\n", &name, &surname, &mid1, &mid2, &final);
    
    /*Print the screen contributions of GPA*/ 
    printf("The notes of %c%c to GPA contribution: ", name, surname); 
    
    grade = calculate_grade(mid1, mid2, final); /*Calculate grade*/
    lgrade = grade_to_latter_grade(grade); /*Calculate latter grade*/
    contribution = contribution_GPA(lgrade); /*Calculate conribution of GPA*/
    
    /*Write results to Grades.txt*/
    fprintf(fp2, "%c%c %d %.2f\n", name, surname, grade, contribution );
    
/*******************************STUDENT 2**************************************/
    /*Read input values from Stındents.txt*/
    fscanf(fp1, "%c%c%d%d%d\n", &name, &surname, &mid1, &mid2, &final);
    
    /*Print the screen contributions of GPA*/ 
    printf("The notes of %c%c to GPA contribution: ", name, surname); 
    
    grade = calculate_grade(mid1, mid2, final); /*Calculate grade*/
    lgrade = grade_to_latter_grade(grade); /*Calculate latter grade*/
    contribution = contribution_GPA(lgrade); /*Calculate conribution of GPA*/
    
    /*Write results to Grades.txt*/
    fprintf(fp2, "%c%c %d %.2f\n", name, surname, grade, contribution );
    
/********************************STUDENT 3*************************************/
    /*Read input values from Stındents.txt*/
    fscanf(fp1, "%c%c%d%d%d\n", &name, &surname, &mid1, &mid2, &final);
    
    /*Print the screen contributions of GPA*/ 
    printf("The notes of %c%c to GPA contribution: ", name, surname); 
    
    grade = calculate_grade(mid1, mid2, final); /*Calculate grade*/
    lgrade = grade_to_latter_grade(grade); /*Calculate latter grade*/
    contribution = contribution_GPA(lgrade); /*Calculate conribution of GPA*/
    
    /*Write results to Grades.txt*/
    fprintf(fp2, "%c%c %d %.2f\n", name, surname, grade, contribution );
    
/********************************STUDENT 4*************************************/
    /*Read input values from Stındents.txt*/
    fscanf(fp1, "%c%c%d%d%d\n", &name, &surname, &mid1, &mid2, &final);
    
    /*Print the screen contributions of GPA*/ 
    printf("The notes of %c%c to GPA contribution: ", name, surname); 
    
    grade = calculate_grade(mid1, mid2, final); /*Calculate grade*/
    lgrade = grade_to_latter_grade(grade); /*Calculate latter grade*/
    contribution = contribution_GPA(lgrade); /*Calculate conribution of GPA*/
    
    /*Write results to Grades.txt*/
    fprintf(fp2, "%c%c %d %.2f\n", name, surname, grade, contribution );
    
/********************************STUDENT 5*************************************/
    /*Read input values from Stındents.txt*/
    fscanf(fp1, "%c%c%d%d%d\n", &name, &surname, &mid1, &mid2, &final);
    
    /*Print the screen contributions of GPA*/ 
    printf("The notes of %c%c to GPA contribution: ", name, surname); 
    
    grade = calculate_grade(mid1, mid2, final); /*Calculate grade*/
    lgrade = grade_to_latter_grade(grade); /*Calculate latter grade*/
    contribution = contribution_GPA(lgrade); /*Calculate conribution of GPA*/
    
    /*Write results to Grades.txt*/
    fprintf(fp2, "%c%c %d %.2f\n", name, surname, grade, contribution );
    
    
    
    fclose(fp2);
    fclose(fp1);
    
    return 0;
}
    
/*This function calculate average grade*/    
int calculate_grade(int mid1, int mid2, int final){
    int grade;
    grade = mid1*0.3+mid2*0.3+final*0.4;
    return(grade);
}
    
/*This function calculate latter grade*/ 
char grade_to_latter_grade(int grade){

    char A, B, C, D, F;
    char lgrade;
    
    if(grade>=85)
    lgrade = 'A';
    else if(grade>=70)
    lgrade = 'B';
    else if(grade>=65)
    lgrade = 'C';
    else if(grade>=40)
    lgrade = 'D';
    else
    lgrade = 'F';
    
    return(lgrade);
}
    
/*This function calculate contribution of GPA and print the screen*/    
double contribution_GPA(char lgrade){

    double A, B, C, D, F; /*The contributions of A, B, C, D, F*/ 
    
    A = 4.0*3.0/20.0;
    B = 3.0*3.0/20.0;
    C = 2.0*3.0/20.0;
    D = 1.0*3.0/20.0;
    F = 0;
    
    switch(lgrade){
    
    case 'A' : printf("%.2f\n", A);
               return(A);
    case 'B' : printf("%.2f\n", B);
               return(B);
    case 'C' : printf("%.2f\n", C);
               return(C);
    case 'D' : printf("%.2f\n", D);
               return(D);
    case 'F' : printf("%.2f\n", F);
               return(F);
    }
    
}

/*############################################################################*/
/*               End of HW02_Furkan_Erdol_131044065_part2.c                   */
/*############################################################################*/
               
    
    
    
    
    
    
