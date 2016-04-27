/*############################################################################*/
/*HW06_Furkan_Erdol_131044065_part1.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on April 5, 2015                                    */
/*Description                                                                 */
/*____________                                                                */
/*                                                                            */
/***************This program for job assignment problem************************/
/*<<<The aim of this program is to assign jobs to the employees as fair as    */
/*possible and show the most hardworking employee of the day and the week>>>> */  
/*                                                                            */
/*-Gives inputs from enegergies file                                          */
/*-Creats schedule work schedule for employees                                */
/*-Finds the day's employee and week's employee                               */
/*-Writes report to report file                                               */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Energies                                                                 */
/*Outputs:                                                                    */
/*  -Work schedule                                                            */
/*  -Day's employee                                                           */
/*  -Week's employee                                                          */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#define NUM_EMPLOYEES 4
#define NUM_DAYS 7

typedef enum
 {Ali, Ayse, Fatma, Mehmet}
 employee;
 
typedef enum
 {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday}
 day;
 

/*Function protoytpes*/
void read_matrix(const char* file_name, int m[NUM_EMPLOYEES][NUM_DAYS]);
void create_work_plan(int job_schedule[NUM_EMPLOYEES][NUM_DAYS], int m[NUM_EMPLOYEES][NUM_DAYS]);
employee find_the_employer_of_the_day(int work_schedule[NUM_EMPLOYEES][NUM_DAYS], day day_name);
employee find_the_employer_of_the_week(int work_schedule[NUM_EMPLOYEES][NUM_DAYS]);
void report(const char* file_name, int job_scheduling[NUM_EMPLOYEES][NUM_DAYS]);
void sort_array(int array[], int size);
int max_array(const int array[], int n);
int second_max_array(const int array[], int n);
int second_min_array(const int array[], int n);
int min_array(const int array[], int n);
int index_of_max(const int array[], int n);
int index_of_second_max(const int array[], int n);
int index_of_second_min(const int array[], int n);
int index_of_min(const int array[], int n);


int
main(void)
{
    int i,j; /*For loops*/
    int job_energies[NUM_EMPLOYEES][NUM_DAYS]; /*Required energy for jobs*/
    int schedule[NUM_EMPLOYEES][NUM_DAYS]; /*Work schedule*/
    char file_energies[20]="Energies.txt"; 
    char file_report[20]="Report.txt";
    employee employee; /*Employee*/
    day day_name; /*Day name*/
    
    /*Reads job energies from file and writes it to job_energies array*/
    read_matrix(file_energies, job_energies);
    
    /*Reads job energies from job_energies array and creates schedule array*/
    create_work_plan(schedule, job_energies);
    
    /*Assign jobs to the employees as fair as possible*/
    find_the_employer_of_the_day(schedule, day_name);
    
    /*Make the necessary calculations*/
    /*Finds day's and week's employee*/
    /*Finally writes report to file*/ 
    report(file_report, schedule);
    
    return 0;
}

/*Reads job energies from file and writes it to job_energies array*/
void read_matrix(const char* file_name, int m[NUM_EMPLOYEES][NUM_DAYS])
{

    FILE *fp; /*File pointer*/
    int i,j; /*For loops*/
    
    /*Open energies.txt if file couldn't open prints the screen warning message*/
    fp=fopen(file_name, "r");
    if(fp==NULL)
        printf("energies.txt couldn't open");
    
    /*Reads energi values and creates matrix*/
    for(i=0;i<NUM_DAYS;i++)
        for(j=0;j<NUM_EMPLOYEES;j++)
            fscanf(fp, "%d", &m[j][i]);
    
    fclose(fp);
            
}

/*Fills schedule matrix according to m array*/
void create_work_plan(int job_schedule[NUM_EMPLOYEES][NUM_DAYS], int m[NUM_EMPLOYEES][NUM_DAYS])
{
    int i, j; /*For loops*/
    
        for(i=0;i<NUM_EMPLOYEES;i++)
            for(j=0;j<NUM_DAYS;j++)
                job_schedule[i][j]=m[i][j];
}

/*Make the necessary calculations*
 *Finds day's employee and return*
 *Finally writes report to file  */ 
employee find_the_employer_of_the_day(int work_schedule[NUM_EMPLOYEES][NUM_DAYS], day day_name)
{
    int i,n,j=0; /*For loops*/
    int sum_array[NUM_EMPLOYEES]={0}; /*Sum array for calculation*/
    int transporter[NUM_EMPLOYEES]; /*For copying to energies*/
    int control[NUM_EMPLOYEES]; /*To compare the arrays*/
    employee employee; /*Employee*/
    
    /*Fills work schedule*/
    for(n=0;n<NUM_DAYS;n++)
    {
    
        for(i=0;i<NUM_EMPLOYEES;i++)
           control[i]=work_schedule[i][n];
        
        transporter[index_of_max(sum_array, NUM_EMPLOYEES)]=min_array(control, NUM_EMPLOYEES);
        transporter[index_of_min(sum_array, NUM_EMPLOYEES)]=max_array(control, NUM_EMPLOYEES);   
        transporter[index_of_second_min(sum_array, NUM_EMPLOYEES)]=second_max_array(control, NUM_EMPLOYEES);
        transporter[index_of_second_max(sum_array, NUM_EMPLOYEES)]=second_min_array(control, NUM_EMPLOYEES);
        
        for(i=0;i<NUM_EMPLOYEES;i++)
            sum_array[i]+=transporter[i];    
              
        for(i=0;i<NUM_EMPLOYEES;i++)
            work_schedule[i][j]=transporter[i];
    
        if(day_name==n)
            employee=index_of_max(control, NUM_EMPLOYEES);      
            
    j++;    
    
    }    
    
    return employee;
    
}

/*Finds employer of the week according to wor schedule*/
employee find_the_employer_of_the_week(int work_schedule[NUM_EMPLOYEES][NUM_DAYS])
{

    int i,j; /*For loops*/
    int sum_array[NUM_EMPLOYEES]={0}; /*Sum array*/
    employee employee; /*Employee*/
    
    
    for(i=0;i<NUM_EMPLOYEES;i++)
        for(j=0;j<NUM_DAYS;j++)
        sum_array[i]+=work_schedule[i][j];
            
    employee=index_of_max(sum_array, NUM_EMPLOYEES);
    
    return employee;
}    

/*Prints to file work schedule report*/
void report(const char* file_name, int job_scheduling[NUM_EMPLOYEES][NUM_DAYS])
{
    FILE *fp;
    int i,j;
    char days[NUM_DAYS][13]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    char employees[NUM_EMPLOYEES][13]={"Ali", "Ayse", "Fatma", "Mehmet"};
    employee employee;
    
    fp=fopen(file_name, "w");
    
    fprintf(fp, "Report:\n\n%7c", ' ');
    for(i=0;i<NUM_DAYS;i++)
        fprintf(fp, "%-10s",  days[i]);
    
    for(i=0;i<NUM_EMPLOYEES;i++)
    {
        fprintf(fp, "\n\n%-9s",employees[i]);
        for(j=0;j<NUM_DAYS;j++)
            fprintf(fp, "%-10d",job_scheduling[i][j]);    
    }

    
    employee=find_the_employer_of_the_day(job_scheduling, Monday);
    fprintf(fp, "\n\nThe best employer of Monday : ");
    switch(employee)
    {
      
    case 0 : fprintf(fp, "Ali");
             break; 
    case 1 : fprintf(fp, "Ayse");
             break; 
    case 2 : fprintf(fp, "Fatma");
             break;           
    case 3 : fprintf(fp, "Mehmet");
             break;   

    }
    
    employee=find_the_employer_of_the_day(job_scheduling, Tuesday);
    fprintf(fp, "\n\nThe best employer of Tuesday : ");
    switch(employee)
    {
      
    case 0 : fprintf(fp, "Ali");
             break; 
    case 1 : fprintf(fp, "Ayse");
             break; 
    case 2 : fprintf(fp, "Fatma");
             break;           
    case 3 : fprintf(fp, "Mehmet");
             break;   

    }
    
    employee=find_the_employer_of_the_day(job_scheduling, Wednesday);
    fprintf(fp, "\n\nThe best employer of Wednesday : ");
    switch(employee)
    {
      
    case 0 : fprintf(fp, "Ali");
             break; 
    case 1 : fprintf(fp, "Ayse");
             break; 
    case 2 : fprintf(fp, "Fatma");
             break;           
    case 3 : fprintf(fp, "Mehmet");
             break;   

    }
    
    employee=find_the_employer_of_the_day(job_scheduling, Thursday);
    fprintf(fp, "\n\nThe best employer of Thursday : ");
    switch(employee)
    {
      
    case 0 : fprintf(fp, "Ali");
             break; 
    case 1 : fprintf(fp, "Ayse");
             break; 
    case 2 : fprintf(fp, "Fatma");
             break;           
    case 3 : fprintf(fp, "Mehmet");
             break;   

    }
    
    employee=find_the_employer_of_the_day(job_scheduling, Friday);
    fprintf(fp, "\n\nThe best employer of Friday : ");
    switch(employee)
    {
      
    case 0 : fprintf(fp, "Ali");
             break; 
    case 1 : fprintf(fp, "Ayse");
             break; 
    case 2 : fprintf(fp, "Fatma");
             break;           
    case 3 : fprintf(fp, "Mehmet");
             break;   

    }
    
    employee=find_the_employer_of_the_day(job_scheduling, Saturday);
    fprintf(fp, "\n\nThe best employer of Saturday : ");
    switch(employee)
    {
      
    case 0 : fprintf(fp, "Ali");
             break; 
    case 1 : fprintf(fp, "Ayse");
             break; 
    case 2 : fprintf(fp, "Fatma");
             break;           
    case 3 : fprintf(fp, "Mehmet");
             break;   

    }
    
    employee=find_the_employer_of_the_day(job_scheduling, Sunday);
    fprintf(fp, "\n\nThe best employer of Sunday : ");
    switch(employee)
    {
      
    case 0 : fprintf(fp, "Ali");
             break; 
    case 1 : fprintf(fp, "Ayse");
             break; 
    case 2 : fprintf(fp, "Fatma");
             break;           
    case 3 : fprintf(fp, "Mehmet");
             break;   

    }
    
    employee=find_the_employer_of_the_week(job_scheduling);
    fprintf(fp, "\n\nThe best employer of the week is ");
    switch(employee)
    {
      
    case 0 : fprintf(fp, "Ali ... Congratulations Ali !!");
             break; 
    case 1 : fprintf(fp, "Ayse ... Congratulations Ayse !!");
             break; 
    case 2 : fprintf(fp, "Fatma ... Congratulations Fatma !!");
             break;           
    case 3 : fprintf(fp, "Mehmet ... Congratulations Mehmet !!");
             break;   

    }    

}

/*Gives an array and sort it*/            
void sort_array(int array[], int size){

    int i, k; /*For loops*/
    int temp; /*Temporary variable*/
    
    for(i=0;i<size;i++)
    {
        for(k=i+1;k<size;k++)
        {
            if(array[i]<array[k])
            {
                temp=array[i];
                array[i]=array[k];
                array[k]=temp;
            }    
        }
     }        
}

/*Finds maximum number in array and return it*/
int max_array(const int array[], int n)
{

    int i,
        max=array[0];/*Maximum number in array*/
    
    for(i=0;i<n;i++)
        if(array[i]>max)
            max=array[i];
            
    return max;
}

/*Finds second maximum number in arrayand return it*/
int second_max_array(const int array[], int n)
{

    int i,
        max, /*Maximum number in array*/
        second_max=0; /*Maximum second number in array*/
    int counter=0;    
    
    max=max_array(array, n); /*Calls max array function for give maximum number*/
    
    for(i=0;i<n;i++)
    {
        if(array[i]>second_max&&array[i]<max)
            second_max=array[i];
        else if(array[i]==max)
            counter++;   
        }    
            
    if(counter>1)
        second_max=max;
        
    return second_max;
    
}

/*Finds second minimum number in array and return it*/
int second_min_array(const int array[], int n)
{

    int i,
        min, /*Minimum number in array*/
        second_min=max_array(array, n); /*Minimun second number in array*/
    int counter=0;
    
    min=min_array(array, n); /*Calls min array function for give minimum number*/   
    
    for(i=0;i<n;i++)
    {
       
        if(array[i]<second_min&&array[i]>min)
            second_min=array[i];
        else if(array[i]==min)
            counter++;       
                
    }    
            
    if(counter>1)
        second_min=min;        
        
    return second_min;
    
}  

/*Finds minimum number in array and return it*/
int min_array(const int array[], int n)
{

    int i,
        min=array[0]; /*Minimum number in array*/
    
    
    for(i=0;i<n;i++)
        if(array[i]<=min)
            min=array[i];
            
    return min;
}

/*Finds maximum number's index in array and return it*/
int index_of_max(const int array[], int n)
{

    int i,
        max=array[0], /*Maximum number in array*/
        index=0; /*Maximum number's index*/
    
    for(i=0;i<n;i++)
        if(array[i]>=max)
        {
            max=array[i];
            index=i;
        }    
        
    return index;
}

/*Finds second maximum number's index in array and return it*/
int index_of_second_max(const int array[], int n)
{

    int i,
        max, /*Maximum number in array*/ 
        second_max=0, /*Second maximum number in array*/
        index=0, /*Second maximum number's index*/
        control_position=0; 
    int counter=0;    
    
    max=max_array(array, n); /*Calls max array function for give maximum number*/
    
    for(i=0;i<n;i++)
    {
        if(array[i]>=second_max&&array[i]<max)
        {
            second_max=array[i];
            index=i;
        }
        else if(array[i]==max)
        {
            counter++;
            if(counter==2||counter==3||counter==4)
            {
                second_max=max;
                index=control_position;       
            }
            control_position=i;
        }      
    }    
            
    return index;
    
}        

/*Finds second minimum number's index in array and return it*/
int index_of_second_min(const int array[], int n)
{

    int i,
        min, /*Minimum number in array*/ 
        second_min=max_array(array, n), /*Second minimum number in array*/ 
        index=0; /*Second minimum number's index*/
    int counter=0;
    
    min=min_array(array, n); /*Calls min array function for give minimum number*/    
    
    for(i=0;i<n;i++)
    {
    
        if(array[i]<second_min&&array[i]>min)
        {
            second_min=array[i];
            index=i;
        }
        else if(array[i]==min)
        {
            counter++;
            if(counter==2)
            {   
                second_min=min;
                index=i;   
            }
        }
    }    
            
    return index;
}

/*Finds minimum number's index in array and return it*/
int index_of_min(const int array[], int n)
{

    int i,
        min=array[0]; /*Minimum number in array*/
    int index=0; /*Minimum number's index*/
    
    for(i=0;i<n;i++)
        if(array[i]<min)
        {
            min=array[i];
            index=i;
        }    
       
    return index;
}

/*############################################################################*/
/*                End of HW06_Furkan_Erdol_131044065_part1.c                  */
/*############################################################################*/
