/*############################################################################*/
/*HW04_Furkan_Erdol_131044065_part1.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on March 12, 2015                                   */
/*Description                                                                 */
/*____________                                                                */
/*                                                                            */
/*>>>>Reads the plain text messages from file and encrypts them, uses GTU     */
/*Encoding Table<<<<                                                          */   
/*                                                                            */
/*Inputs:                                                                     */
/*  -Plain messages to sent                                                   */
/*  -Encoded messages                                                         */
/*Outputs:                                                                    */
/*  -Crypted messages                                                         */
/*  -Encoded messages                                                         */
/*                                                                            */
/*Points: 30                                                                  */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>

#define PLAINTEXTFILE "Files/Q1/PlainMessagesToSent.txt"
#define ENCODEDFILE "Files/Q1/EncodedMessages.txt"
#define CRYPTEDFILE "Files/Q1/CryptedMessages.txt"

/******************************************************************************
 * Gets FILE* to write file and character to encode uses encoding table to    *
 * convert plain text to encoded message                                      *
 ******************************************************************************/
void encode_and_write_to_file(FILE *f_out_ptr, char character);

/******************************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and FILE* f_out_ptr to    *
 * write message to encoded file return number of characters read from plain  *
 * text                                                                       * 
 ******************************************************************************/
int encode_message(FILE *f_in_ptr, FILE *f_out_ptr);

/******************************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and FILE* f_out_ptr to  * 
 * write message to encrypted file return number of characters read from      *
 * encoded text file                                                          *
 ******************************************************************************/
int crypt_message(FILE *f_in_ptr, FILE *f_out_ptr);


int
main(void)
{

    FILE *f_plane_ptr, /* PlainMessagesToSent.txt */
         *f_encoded_ptr, /* EncodedMessages.txt */
         *f_crypted_ptr; /* CryptedMessages.txt */
    
    /* Open plain messages file and encoded messages file */
    f_plane_ptr=fopen(PLAINTEXTFILE, "r");
    f_encoded_ptr=fopen(ENCODEDFILE, "w");
    
    
    /*Exit program and print error if plan messages file could not be opened to read */
    if(f_plane_ptr==NULL)
    {
        printf("PlainMessagesToSent.txt couldn't open...\n");
        return 0;
    }
    
    /*Exit program and print error if encoded file could not be opened to write */
    if(f_encoded_ptr==NULL)
    {
        printf("EncodedMessages.txt couldn't open...\n");
        return 0;
    }
    
    /* Gets message and encode it, return number of characters read from file */
    encode_message(&*f_plane_ptr, &*f_encoded_ptr);
    
    /*Close plain messages file and encoded messages file */
    fclose(f_plane_ptr);
    fclose(f_encoded_ptr);
    
    /* Open crypted messages file and encoded messages file */
    f_crypted_ptr=fopen(CRYPTEDFILE, "w");
    f_encoded_ptr=fopen(ENCODEDFILE, "r");
    
    
    /*Exit program and print error if crypted file could not be opened to write */
    if(f_crypted_ptr==NULL)
    {
        printf("CryptedMessages.txt couldn't open...\n");
        return 0;
    }
    
    /*Exit program and print error if encoded file could not be opened to read */
    if(f_encoded_ptr==NULL)
    {
        printf("EncodedMessages.txt couldn't open...\n");
        return 0;
    }
    
    /* Gets encoded message and encrypt it, return number of characters read from file */
    crypt_message(&*f_encoded_ptr, &*f_crypted_ptr);
    
    /* Close crypted messages file and encoded messages file */
    fclose(f_crypted_ptr);
    fclose(f_encoded_ptr);
    
    
    return 0;
}


/******************************************************************************
 * Gets FILE* to write file and character to encode uses encoding table to    *
 * convert plain text to encoded message                                      *
 ******************************************************************************/
void encode_and_write_to_file(FILE *f_out_ptr, char character)
{
    int count=0, /* Counts according to encoding table */
        count1=1; /* Count value for loop */
    
    /* Encodes the letters according to encoding table and prints the file */
    switch(character)
    {
    
    case 'E' : count=0; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case 'I' : count=1; 
              for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case ' ' : count=2; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;               
    case 'T' : count=3; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;               
    case 'C' : count=4; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case 'N' : count=5; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case 'A' : count=6; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case 'G' : count=7; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case 'B' : count=8; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case 'Z' : count=9; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case 'H' : count=10; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case 'L' : count=11; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case 'U' : count=12; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case 'V' : count=13; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case 'R' : count=14; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case 'S' : count=15; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    case 'Y' : count=16; 
               for(count1=1;count1<=count;count1++){
                   fprintf(f_out_ptr, "%d", 1);
                   }
                   fprintf(f_out_ptr, "%d", 0);
                   break;
    }
}

/******************************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and FILE* f_out_ptr to    *
 * write message to encoded file return number of characters read from plain  *
 * text                                                                       * 
 ******************************************************************************/
int encode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	
	int counter = 0; /* Counts number of characters */
	char character; /* Read character variable */
	

	while(fscanf(f_in_ptr, "%c", &character)!=EOF) /* Reads the file until the end */
	{
	    encode_and_write_to_file(f_out_ptr, character); /* Call encode and write to file function */
	    
	    counter++;
	}
	
	return counter;
}


/******************************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and FILE* f_out_ptr to  * 
 * write message to encrypted file return number of characters read from      *
 * encoded text file                                                          *
 ******************************************************************************/
int crypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	
	int counter = 0, /* Counts number of characters */
	    N=5, M; /* Values for encoding */
        char number; /* Read character variable (1 or 0) */
	
	M=N;
	

	while(fscanf(f_in_ptr, " %c", &number)!=EOF) /* Reads the file until the end */
	{
	   
        if(number=='1')
	        fprintf(f_out_ptr, "%c", '*');
	    else if(number=='0')
	        fprintf(f_out_ptr, "%c", '_');
	       
	    M--;
	       
	    
	    if(M==0)
	    {
	        fprintf(f_out_ptr, "%c", '-');
	        N--;
	        M=N;
	    }
	    
	    if(N==0)
	    {
	        N=5;
	        M=N;
	    }
	       
	counter++;
	
	
	}
	
	
	return counter;
}

/*############################################################################*/
/*                End of HW04_Furkan_Erdol_131044065_part1.c                  */
/*############################################################################*/
