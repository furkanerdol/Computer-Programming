/*############################################################################*/
/*HW07_Furkan_Erdol_131044065_part3.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on April 9, 2015                                    */
/*Description                                                                 */
/*____________                                                                */
/*                                                                            */
/*************This program tries to find a way out of the maze*****************/  
/*                                                                            */
/*Entry position position: (0,0)                                              */
/*Output position position: (ROW_SIZE-1, COL_SIZE-1)                          */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Grid table                                                               */
/*Outputs:                                                                    */
/*  -Path table                                                               */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#define ROW_SIZE 5
#define COL_SIZE 5

typedef enum
 {notavailable, available, right_down}
 Grid_t;

typedef enum
 {FALSE, TRUE}
 Bool; 

/*Function prototypes*/ 
void read_table(FILE *input_file, Grid_t table[][COL_SIZE]);
void print_path(char path[][COL_SIZE], int n);
void print_table(Grid_t table[][COL_SIZE], int n); 
Bool find_path(Grid_t table[][COL_SIZE], char path[][COL_SIZE], int size, int location_x, int location_y);


int
main(void)
{
    int i,j; /*For loops*/
    FILE *fp; /*File pointer*/
    Grid_t table[ROW_SIZE][COL_SIZE]; /*Grid table*/
    char path[ROW_SIZE][COL_SIZE]; /*Path table*/
    Bool found;

    /*Assign '|' character to all path string array*/
    for(i=0;i<ROW_SIZE;i++)
        for(j=0;j<COL_SIZE;j++)
            path[i][j]='|';
    
    /*Open table.txt if couldn't open prints the screen warning message*/
    fp=fopen("table.txt", "r");
    if(fp==NULL){
        ("File couldn't open...");
        return 0;
    }
    
    /*Calls read_table function and reads grid table from file*/
    read_table(fp, table);
    
    fclose(fp);
    
    /*Calls print_table function and prints to screen grid table*/
    print_table(table, ROW_SIZE);
    
    printf("\n######################################");
    printf("\nSearching for a way out of the maze...");
    printf("\n######################################");
    
    /*Calls find_path function and function tries to find a way out of the maze*/ 
    found=find_path(table, path, ROW_SIZE, 0,  0);
    if(found==TRUE)
        printf("\nOutput path found!\n");
    else
        printf("\nOutput path not found!\n");    
    
    printf("######################################");
    
    /*Calls print_path function and prints to screen path table*/
    print_path(path, ROW_SIZE);
    
    return 0;
}

void read_table(FILE *input_file, Grid_t table[][COL_SIZE])
{
    int i,j;
    int x;
    
    for(i=0;i<ROW_SIZE;i++)
        for(j=0;j<COL_SIZE;j++){
            fscanf(input_file, "%d", &x);
            table[i][j]=x;
        }
}

/*Take a grid table and reads it*/
void print_table(Grid_t table[][COL_SIZE], int n)
{
    int i,j; /*For loops*/
    
    printf("\n<<<<<<<<<<<<<<<GRID MAZE>>>>>>>>>>>>>>>\n");
    
    for(i=0;i<n;i++){
    printf("\n");
        for(j=0;j<COL_SIZE;j++)
            printf("%d ",table[i][j]);
    }
}

/*Take a path table and prints it*/
void print_path(char path[][COL_SIZE], int n)
{
    int i,j; /*For loops*/
    
    for(i=0;i<n;i++){
    printf("\n");
        for(j=0;j<COL_SIZE;j++)
            printf("%c ",path[i][j]);
    }
    
    printf("\n\n* (Output path)\n| (dead-end)\n\n");
}

/*This function tries to find a way out of the maze if it finds, return TRUE otherwise return FALSE*/
Bool find_path(Grid_t table[][COL_SIZE], char path[][COL_SIZE], int size, int location_x, int location_y)
{
    /*For stay in the grid*/
    if(location_x>size||location_y>COL_SIZE)
        return FALSE;
    /*Exit if there is*/ 
    else if(location_x==size&&location_y==COL_SIZE)
        return TRUE;
    /*For dead-end*/
    else if(table[location_x][location_y]==notavailable)
        return FALSE;   
    
    /*For available points*/
    else if(table[location_x][location_y]==available){
        path[location_x][location_y]='*';
        find_path(table, path, size, location_x, location_y+1);
        find_path(table, path, size, location_x+1, location_y);
        
        if(find_path(table, path, size, location_x, location_y+1)==TRUE)
            return TRUE;
        if(find_path(table, path, size, location_x+1, location_y)==TRUE)
            return TRUE;
        
        /*Deletes the dead-end*/
        if(table[location_x][location_y]==available)
            path[location_x][location_y]='|';  
    }
    
    /*For right-down points*/
    else if(table[location_x][location_y]==right_down&&table[location_x-1][location_y-1]!=right_down){
        path[location_x][location_y]='*';
        find_path(table, path, size, location_x+1, location_y+1);
        
        if(find_path(table, path, size, location_x+1, location_y+1)==TRUE)
            return TRUE;
        
        /*Deletes the dead-end*/
        if(table[location_x][location_y]==right_down)
            path[location_x][location_y]='|';
    }   
    
    return FALSE;
}

/*############################################################################*/
/*                End of HW07_Furkan_Erdol_131044065_part3.c                  */
/*############################################################################*/
