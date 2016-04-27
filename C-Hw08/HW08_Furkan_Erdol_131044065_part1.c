/*############################################################################*/
/*HW08_Furkan_Erdol_131044065_part1.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on April 18, 2015                                   */
/*Description                                                                 */
/*____________                                                                */
/*                                                                            */
/*Takes double array from file                                                */  
/*Finds maximum sum Rectangular starting from origin                          */
/*Finds maximum sum Rectangular in all array                                  */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Double array                                                             */
/*Outputs:                                                                    */
/*  -Maximum sum Rectangular starting from origin                             */
/*  -Maximum sum Rectangular                                                  */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>

#define COL_COUNT 8
#define ROW_CAP 10

typedef struct{
	int x;
	int y;
}Point_t;

typedef struct{
	Point_t left_up;
	Point_t right_down;
	double sum;
}Rectangle_t;		

/*Function prototypes*/
void getArray(FILE* inFile, double table[][COL_COUNT], int* nRow);
Point_t construct_point(int x, int y);
Rectangle_t construct_rectangle(Point_t left_up, Point_t right_down);
void print_rectangle(const Rectangle_t *rectangle);
void getSum(double table[][COL_COUNT], Rectangle_t *rectangle);
Rectangle_t maxSumConstPoint(double table[][COL_COUNT], int nRow, Point_t left_up);
Rectangle_t maxSumRec(double table[][COL_COUNT], int nRow);


int
main(void)
{
	double table[ROW_CAP][COL_COUNT]; /*Table array*/
	FILE* inFile; /*File pointer*/
	int nRow; /*Row size table*/
	Rectangle_t rectangle; /*Rectangle*/
	
	/*Assing rectangle letf corner and right corner (origin)*/
	rectangle=construct_rectangle(construct_point(0, 0), construct_point(0, 0));
	
	/*Open Table1.txt*/
	inFile=fopen("Table1.txt", "r");
	
	/*Calls getArray function for reads the table*/ 
	getArray(inFile, table, &nRow);
	
	/*Finds maximum sum rectangle left corner is 0,0 and prints it*/ 
	rectangle=maxSumConstPoint(table, nRow, rectangle.left_up);
	printf("\nMaximum sum Rectangular starting from origin");
	print_rectangle(&rectangle);
	
	/*Finds maximum sum rectangle ind all table and prints it*/ 
	rectangle=maxSumRec(table, nRow);
	printf("Maximum sum Rectangular");
	print_rectangle(&rectangle);
	
	/*Close Table1.txt*/
	fclose(inFile);
	
    return 0;
}

/*Reads the table from a file into a 2D array*/
void getArray(FILE* inFile, double table[][COL_COUNT], int* nRow)
{
	int row=0;
	int col;
	int status=EOF+1;/*Different from EOF*/

	/*One more row will be read but the values will not be recorded into the table
	therefore, it is safe to use a table having just enough capasity to hold the data*/
	while(status!=EOF){
		for(col=0; col<COL_COUNT; col++)
			status=fscanf(inFile, "%lf", &table[row][col]);
		++row;
	}

	*nRow=row-1; /*One more row read*/
}

/*Takes two integer and construct point*/
Point_t construct_point(int x, int y)
{
	Point_t point;
	
	point.x=x;
	point.y=y;

	return point;	
}

/*Takes two point and construct rectangle*/
Rectangle_t construct_rectangle(Point_t left_up, Point_t right_down)
{
	Rectangle_t rectangle;
	
	rectangle.left_up=left_up;
	rectangle.right_down=right_down;
	
	return rectangle;
}

/*Takes rectangle as an input parameter and prints it*/
void print_rectangle(const Rectangle_t *rectangle)
{
	printf("\nLeft up-------(%d)(%d)",rectangle->left_up.y,rectangle->left_up.x);
	printf("\nRight down----(%d)(%d)",rectangle->right_down.y,rectangle->right_down.x);
	printf("\nSum-----------%.2f\n\n",rectangle->sum);
}

/*Takes double array and rectangle as an output parameter*/
/*Returns the sum inside a given rectangular*/
void getSum(double table[][COL_COUNT], Rectangle_t *rectangle)
{
	int row, col;
	rectangle->sum=0;
	
	for(row=rectangle->left_up.y; row<=rectangle->right_down.y; ++row)
		for(col=rectangle->left_up.x; col<=rectangle->right_down.x; ++col)
			rectangle->sum+=table[row][col];
}

/*Finds the rectangular left upper point of which is specified having the max sum inside*/
Rectangle_t maxSumConstPoint(double table[][COL_COUNT], int nRow, Point_t left_up)
{
	Rectangle_t rectangle; /*Wanted rectangle*/
	Rectangle_t rectangle_temp; /*Temporary rectangle*/
	
	/*Assign wanted rectangle*/
	rectangle.sum=table[left_up.x][left_up.y];
	rectangle=construct_rectangle(left_up, left_up);
	
	/*Assign temporary rectangle*/
	rectangle_temp.left_up.x=left_up.x;
	rectangle_temp.left_up.y=left_up.y;

	/*Try all feasible rectangulars by changing the right down corner*/
	for(rectangle_temp.right_down.y=left_up.y; rectangle_temp.right_down.y<nRow; ++rectangle_temp.right_down.y){
		for(rectangle_temp.right_down.x=left_up.x; rectangle_temp.right_down.x<COL_COUNT; ++rectangle_temp.right_down.x){
			/*Calls getSum funtion for sum value*/
			getSum(table, &rectangle_temp);
			if(rectangle_temp.sum>rectangle.sum){
				/*A better rectangular is found, perform an update*/
				rectangle=rectangle_temp;				
			}
		}
	}
	
	return rectangle;
}	

/*Finds the largest sum of rectangle*/
Rectangle_t maxSumRec(double table[][COL_COUNT], int nRow)
{
	Rectangle_t rectangle; /*Wanted rectangle*/
	Rectangle_t rectangle_temp; /*Temporary rectangle*/
	
	/*Assign first value on array for sum*/
	rectangle.sum=table[0][0];
	
	/*For all feasible starting points call maxSumConstPoint*/
	for(rectangle_temp.left_up.y=0; rectangle_temp.left_up.y<nRow; ++rectangle_temp.left_up.y){
		for(rectangle_temp.left_up.x=0; rectangle_temp.left_up.x<COL_COUNT; ++rectangle_temp.left_up.x){
			/*Calls maxSumConstPoint function for maximum sum value*/
			rectangle_temp=maxSumConstPoint(table, nRow, rectangle_temp.left_up);
			if(rectangle_temp.sum>rectangle.sum){
				/*A better rectangular found, perform an update*/
				rectangle=rectangle_temp;
			}
		}
	}

	return rectangle;
}

/*############################################################################*/
/*                End of HW08_Furkan_Erdol_131044065_part1.c                  */
/*############################################################################*/
