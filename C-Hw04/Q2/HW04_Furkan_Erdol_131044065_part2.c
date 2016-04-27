/*############################################################################*/
/*HW04_Furkan_Erdol_131044065_part2.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on March 12, 2015                                   */
/*Description                                                                 */
/*____________                                                                */
/*                                                                            */
/*<Reads encrypted text and creates encoded, writes received message to file> */
/*                                                                            */
/*Inputs:                                                                     */
/*  -Crypted message                                                          */
/*  -Encoded message                                                          */
/*Outputs:                                                                    */
/*  -Encoded message                                                          */
/*  -Received message                                                         */
/*                                                                            */
/*Points: 20                                                                  */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>

#define PLAINTEXTFILE "Files/Q2/ReceivedMessage.txt"
#define ENCODEDFILE "Files/Q2/EncodedInput.txt"
#define CRYPTEDINPUT "Files/Q2/CryptedInput.txt"

/******************************************************************************
 * Gets FILE* to write file and character to decode uses encoding table to    *
 * convert encoded message to plain text message                              *
 ******************************************************************************/
void decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones);

/******************************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and FILE* f_out_ptr to  * 
 * write message to plain text file return number of characters read from     *
 * encoded text                                                               *
 ******************************************************************************/
int decode_message(FILE *f_in_ptr, FILE *f_out_ptr);

/******************************************************************************
 * Gets FILE* f_in_ptr to read from encrypted text file and FILE* f_out_ptr to* 
 * write message to encoded file return encrypted character number            *
 ******************************************************************************/
int decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr);



int
main(void)
{

    int y;
    
    FILE *f_plane_ptr, /* ReceivedMessage.txt */
         *f_encoded_ptr, /* EncodedInput.txt */
         *f_crypted_ptr; /* CryptedInput.txt */
    
    /* Open cyrpted input and encoded input file */ 
    f_crypted_ptr=fopen(CRYPTEDINPUT, "r");
    f_encoded_ptr=fopen(ENCODEDFILE, "w");
    
    /*Exit program and print error if crypted input file could not be opened to read */
    if(f_crypted_ptr==NULL)
    {
        printf("CryptedInput.txt couldn't open...\n");
        return 0;
    }
    
    /*Exit program and print error if encoded input file could not be opened to write */
    if(f_encoded_ptr==NULL)
    {
        printf("EncodedInput.txt couldn't open...\n");
        return 0;
    }
    
    /* Gets cyrpted input file and encrypted it, write to encoded input file */
    decrypt_message(&*f_crypted_ptr, &*f_encoded_ptr);
    
    /* Close cyrpted input and encoded input file */
    fclose(f_crypted_ptr);
    fclose(f_encoded_ptr);
    
    /* Open received message and encoded input file */
    f_plane_ptr=fopen(PLAINTEXTFILE, "w");
    f_encoded_ptr=fopen(ENCODEDFILE, "r");
    
    /*Exit program and print error if received message file could not be opened to write */
    if(f_plane_ptr==NULL)
    {
        printf("ReceivedMessage.txt couldn't open...\n");
        return 0;
    }
    /*Exit program and print error if encoded input file could not be opened to read */
    if(f_encoded_ptr==NULL)
    {
        printf("EncodedInput.txt couldn't open...\n");
        return 0;
    }
    
   /* Gets encoded input file and decode it, write to received message file */
    decode_message(&*f_encoded_ptr, &*f_plane_ptr);
    
    /* Close received message and encoded input file */
    fclose(f_plane_ptr);
    fclose(f_encoded_ptr);
    
    
    return 0;
}


/******************************************************************************
 * Gets FILE* to write file and character to decode uses encoding table to    *
 * convert encoded message to plain text message                              *
 ******************************************************************************/
void decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones)
{
    /* Decodes the code according to encoding table and prints the file */
    switch(number_of_ones)
    
    {
    
    case 0 : fprintf(f_out_ptr, "%c", 'E');
             break;     
    case 1 : fprintf(f_out_ptr, "%c", 'I');
             break;
    case 2 : fprintf(f_out_ptr, "%c", ' ');
             break;               
    case 3 : fprintf(f_out_ptr, "%c", 'T');
             break;               
    case 4 : fprintf(f_out_ptr, "%c", 'C');
             break;
    case 5 : fprintf(f_out_ptr, "%c", 'N');
             break;
    case 6 : fprintf(f_out_ptr, "%c", 'A');
             break;
    case 7 : fprintf(f_out_ptr, "%c", 'G');
             break;
    case 8 : fprintf(f_out_ptr, "%c", 'B');
             break;
    case 9 : fprintf(f_out_ptr, "%c", 'Z');
             break;
    case 10 : fprintf(f_out_ptr, "%c", 'H');
              break;
    case 11 : fprintf(f_out_ptr, "%c", 'L');
              break;
    case 12 : fprintf(f_out_ptr, "%c", 'U');
              break;
    case 13 : fprintf(f_out_ptr, "%c", 'V');
              break;
    case 14 : fprintf(f_out_ptr, "%c", 'R');
              break;
    case 15 : fprintf(f_out_ptr, "%c", 'S');
              break;
    case 16 : fprintf(f_out_ptr, "%c", 'Y');
                 
    }

}

/******************************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and FILE* f_out_ptr to  * 
 * write message to plain text file return number of characters read from     *
 * encoded text                                                               *
 ******************************************************************************/
int decode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	
	int counter = 0, /* Counts number of 1 and 0 */ 
	    count_number_of_1=0; /* Counts number of 1 */
	char character; /* Reads 1 and 0 */
	
	while(fscanf(f_in_ptr, "%c", &character)!=EOF) /* Reads the file until the end */
	{
	    if(character=='1')
	        count_number_of_1++;
	    else if(character=='0')
	    {
	        /* Call decode and write to file function */
	        decode_and_write_to_file(&*f_out_ptr, count_number_of_1); 
	        count_number_of_1=0;
	    }
	
	counter++;
	}
	
    return counter;
}

/******************************************************************************
 * Gets FILE* f_in_ptr to read from encrypted text file and FILE* f_out_ptr to* 
 * write message to encoded file return encrypted character number            *
 ******************************************************************************/
int decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	
    int counter=0; /* Counts number of "*", "_", "-" */
	char character; /* Reads "*" and "_"*/
	
	
	while(fscanf(f_in_ptr, " %c", &character)!=EOF) /* Reads the file until the end */
	{
	    if(character=='*')
	        fprintf(f_out_ptr, "%d", 1);
	    else if(character=='_')
	        fprintf(f_out_ptr, "%d", 0);
	       
	counter++;
	}
	
	return counter;
}

/*############################################################################*/
/*                End of HW04_Furkan_Erdol_131044065_part2.c                  */
/*############################################################################*/
