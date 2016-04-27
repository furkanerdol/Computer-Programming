/*############################################################################*/
/*HW09_Furkan_Erdol_131044065_part3.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on April 27, 2015                                   */
/*Description                                                                 */
/*____________                                                                */
/********************This program for microbiologists**************************/
/*Takes a table including experiments and results                             */
/*Writes them into to binary file                                             */
/*Takes from users combination of positives numbers and search them in table  */
/*Prints the screen serch result                                              */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Experiments and results table(as a text file)                            */
/*  -Experiments and results table(as a binary file)                          */
/*  -Combination of positives numbers for searching                           */
/*Outputs:                                                                    */
/*  -Experiments and results table(as a binary file)                          */
/*  -Search result                                                            */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 30

typedef struct{
	int one;
	int two;
	int three;
}triplet_t;	

typedef struct{
	triplet_t triplet;
	int mpn;
	int co_limit_lower;
	int co_limit_upper;
}Row;	

/*Function prototypes*/
int read_text(FILE *text_input, Row table[]);
void Into_Binary(FILE *text_input, FILE *binary_output);
int read_binary(FILE *binary_input_file, Row mpn_table[]);
int Load_Mpn_table(FILE *binary_input_file, Row mpn_table[], int maxsize);
Row search(Row mpn_table[], int actual_size, const triplet_t triplet_to_search);

int
main(void)
{

	FILE *fp, *fp2; /*File pointers*/
	triplet_t triplet_to_search; /*For search*/
	Row mpn_table[TABLE_SIZE]; /*Table array*/
	int actual_size; /*Actual size or number of row in table*/
	
	/*Open table.txt if file couldn't open prints the screen warning message*/
	fp=fopen("table.txt", "r");
	if(fp==NULL)
        printf("table.txt couldn't open");
	/*Open converted.bin if file couldn't open prints the screen warning message*/        
	fp2=fopen("converted.bin", "wb");
	if(fp==NULL)
        printf("converted.bin couldn't open");

	/*Reads informations from text file and writes them to binary file*/
	Into_Binary(fp,fp2);
	
	fclose(fp);
	fclose(fp2);
	
	/*Open converted.bin if file couldn't open prints the screen warning message*/        
	fp2=fopen("converted.bin", "rb");
	if(fp==NULL)
        printf("converted.bin couldn't open");
	
	/*Reads informations from binary file and records in table array returns number of row*/
	actual_size=Load_Mpn_table(fp2, mpn_table, 10);
	
	/*Takes from the user a combination-of-positives triplet*/
	printf("\nEnter combination-of-positives triplet:");
	scanf("%d%d%d", &triplet_to_search.one, &triplet_to_search.two, &triplet_to_search.three);  
	/*Search for it in the table*/
	search(mpn_table, actual_size, triplet_to_search);
	
	fclose(fp2);

	return 0;
}

/*Reads 10 row from text file*/
int read_text(FILE *text_input, Row table[])
{
	int i=0;
	
	while(i<10&&fscanf(text_input, "%d", &table[i].triplet.one)!=EOF){
		fscanf(text_input, "%d", &table[i].triplet.two);
		fscanf(text_input, "%d", &table[i].triplet.three);
		fscanf(text_input, "%d", &table[i].mpn);
		fscanf(text_input, "%d", &table[i].co_limit_lower);
		fscanf(text_input, "%d", &table[i].co_limit_upper);
		i++;
	}
	
	return i;	
}

/*Reads informations from txt file and writes them to binary file*/
void Into_Binary(FILE *text_input, FILE *binary_output)
{
	Row table[TABLE_SIZE]; /*Table array*/
	int location=0; /*Location information in the array*/
	int read=10; /*For row control*/
	
	while(read==10){
		/*Reads maximum 10 row from text file*/
		read=read_text(text_input,&table[location]);
		/*Writes table to binary file*/
		fwrite(&table[location], sizeof(table[0]), read, binary_output);
		location+=read;
	}	
}

/*Reads 10 Row from binary file*/
int read_binary(FILE *binary_input_file, Row mpn_table[])
{
	int i=0;
	
	i=fread(mpn_table, sizeof(mpn_table[0]), 10, binary_input_file);
	
	return i;
}

/*Reads informations from binary file and records in table array returns number of row*/
int Load_Mpn_table(FILE *binary_input_file, Row mpn_table[], int maxsize)
{
	int location=0; /*Location information in the array*/
	int actual_size=0; /*Actual size or number of row in table*/
	
	while(maxsize==10){
		maxsize=read_binary(binary_input_file, &mpn_table[location]);
		actual_size+=maxsize;
		location+=maxsize;
	}	
	
	return actual_size;
}

/*Search for combination_of_positives components in the table after generate a message*/
Row search(Row mpn_table[], int actual_size, const triplet_t triplet_to_search)
{
	int i; /*For loop*/
	Row target; /*Target row*/
	int found=-1; /*Control value*/
	
	target.mpn=-1;
	target.co_limit_lower=-1;
	target.co_limit_upper=-1;
	
	for(i=0;i<actual_size;i++){
		if(triplet_to_search.one==mpn_table[i].triplet.one &&
		   triplet_to_search.two==mpn_table[i].triplet.two &&
		   triplet_to_search.three==mpn_table[i].triplet.three){
			printf("\nMPN = %d -> 95%% of samples contain between %d and %d bacteria/ml\n\n",
			mpn_table[i].mpn, mpn_table[i].co_limit_lower, mpn_table[i].co_limit_upper);
			target=mpn_table[i];
			found=0;
		}				   
	}
	
		if(found==-1)
			printf("\nNot found!\n\n");
	
	return target;	   
}	

/*############################################################################*/
/*               End of HW09_Furkan_Erdol_131044065_part3.c                   */
/*############################################################################*/				
