/*############################################################################*/
/*HW06_Furkan_Erdol_131044065_part2.c                                         */
/*______________________________                                              */
/*Written by Furkan Erdol on April 5, 2015                                    */
/*Description                                                                 */
/*____________                                                                */
/*                                                                            */
/*                                                                            */
/*<<<<This program checking the Major and Minor Vowel Harmony according to    */
/*rules of the vowel harmony and making a noun Plural>>>>                     */
/*                                                                            */                                              
/*                                                                            */
/*Inputs:                                                                     */
/*  -Vowels                                                                   */
/*  -Nouns                                                                    */
/*Outputs:                                                                    */
/*  -Plural nouns                                                             */
/*  -Vowel harmony results                                                    */
/*............................................................................*/
/*                               Includes                                     */
/*............................................................................*/
#include <stdio.h>
#include <string.h>
#define VOWELS "Vowels.txt"
#define NOUNS "Nouns.txt"
#define PLURAL "Plural.txt"

typedef enum
 {HARD, SOFT, CONSONANT1}
 major_type;

typedef enum
 {FLAT, ROUND, CONSONANT2}
 minor_type;

typedef enum
 {FALSE, TRUE}
 bool;  

/*Function prototypes*/
bool is_major_vh_word(const char* word, const char* v_hard, const char* v_soft);
major_type major(const char ch1, const char* v_hard, const char* v_soft);
bool is_minor_vh_word( const char* word, const char* v_flat, const char* v_round);
minor_type minor(const char ch1, const char* v_flat, const char* v_round);
major_type find_last_type(const char* word, const char* v_hard, const char* v_soft);
char* make_plural(const char* noun , char* plural_noun, const char* v_hard, const char* v_soft);


int
main(void)
{

    FILE *fp, *fp2, *fp3; /*File pointers*/
    char hard[7], soft[7], flat[7], round[7]; /*Input vowels*/ 
    char plural[15][20]; /*Output plural nouns*/
    char word[15][20]; /*Input nouns*/
    bool control; /*Whether it is harmonies*/
    int i; /*For loops*/
    int size=0; /*Number of nouns*/
    
    /*Open Vowels.txt if couldn't open print the screen warning message*/
    fp=fopen(VOWELS, "r");
    if(fp==NULL)
        printf("Vowels.txt counldn't open...");
    
    /*Reads vowels from file*/
    fgets(hard,7,fp);
    fgets(soft,7,fp);
    fgets(flat,7,fp);
    fgets(round,7,fp);
    
    fclose(fp);
    
    /*Open Nouns.txt if couldn't open print the screen warning message*/
    fp2=fopen(NOUNS, "r");
    if(fp2==NULL)
        printf("Nouns.txt counldn't open...");
    
    /*Reads nouns from file*/
    i=0;
    while(fscanf(fp, " %s", word[i])!=EOF)
    {
        size++;
        i++;   
    }
    
    fclose(fp2);
    
/*##########################Print the screen results##########################*/
    printf("\n%10cMajor%4cMinor", ' ', ' ');
    
    for(i=0;i<size;i++)
    {
        printf("\n%-12s", word[i]);
                       
        
        control=is_major_vh_word(word[i], hard, soft);
        if(control==1)
            printf("T%8c", ' ');
        else
            printf("F%8c", ' ');
        
        control=is_minor_vh_word(word[i], flat, round);
        if(control==1)
            printf("T");
        else
            printf("F");        
      
    }
    
    printf("\n\n<<<<Plural of the nouns>>>>");
    for(i=0;i<size;i++)
    {
        make_plural(word[i] , plural[i], hard, soft);
        printf("\n%s---%s", word[i],plural[i]);
    }
         
    printf("\n\n");
    
    /*Open Plural.txt if couldn't open print the screen warning message*/
    fp3=fopen(PLURAL, "w");
    if(fp3==NULL)
        printf("Plural.txt counldn't open...");
    
    /*Writes to file plural nouns*/
    for(i=0;i<size;i++)
    {
        make_plural(word[i] , plural[i], hard, soft);
        fprintf(fp3,"%s\n",plural[i]);
    }    
        
    
    
    return 0;
}

/*Checks whether the word satisfies the major vowel harmony or not and returns* 
 *TRUE or FALSE                                                               */
bool is_major_vh_word(const char* word, const char* v_hard, const char* v_soft)
{
    int hard=0, soft=0; /*Checks whether*/
    int i, j; /*For loops*/
    bool major=FALSE;
    
        for(i=0;i<strlen(word);i++)
            for(j=0;j<strlen(v_hard);j++)
                if(word[i]==v_hard[j])
                    hard=1;    
                else if(word[i]==v_soft[j])
                    soft=1;
        
        if((hard==1&&soft==0)||(hard==0&&soft==1))
            major=TRUE;
            
            
    return major;
}                

/*Takes one character and two lists of hard and soft vowels and checks whether* 
 *the character is a soft vowel or a hard vowel, returns HARD, SOFT           *
 *or CONSONANT                                                                */
major_type major(const char ch1, const char* v_hard, const char* v_soft)
{
    int i; /*For loops*/
    major_type type=CONSONANT1;
    
    for(i=0;i<strlen(v_hard);i++)
        if(ch1==v_hard[i])
            type=HARD;
        else if(ch1==v_soft[i])
            type=SOFT;       
    
    return type;        
}            

/*Checks whether the word satisfies the minor vowel harmony or not and returns* 
 *TRUE or FALSE                                                               */
bool is_minor_vh_word( const char* word, const char* v_flat, const char* v_round)
{
    int flat=0, round=0, testing=0; /*Checks whether*/
    int i, j; /*For loops*/
    int control1=0, control2=0, control3=0; /*Finds index of vowels*/
    bool minor=TRUE;
    char test[3]="oi", test2[3]="o"; /*Test strings*/
    
    for(i=0;i<strlen(word);i++)
    {
        for(j=0;j<strlen(v_flat);j++)
        {
            if(word[i]==v_flat[j])
            {
                flat=1;
                control1=i;
            }
            else if(word[i]==v_round[j])
            {
                round=1;
                control2=i;
            }
            else if(word[i]==test[j])
            {
                testing=1;
                control3=i;
            }
           
            if(word[i]==test2[j]&&i>1)
                minor=FALSE;
         }                               
    
    if(flat==1&&control2>control1||round==1&&control3>control2)
        minor=FALSE;
   
    }
    
    return minor;
}

/*Takes one character and two lists of flat and round vowels and checks       *
 *whether the character is a soft vowel or a hard vowel, returns FLAT, ROUND  *
 *or CONSONANT                                                                */
minor_type minor(const char ch1, const char* v_flat, const char* v_round)
{
    int i; /*For loops*/
    major_type type=CONSONANT2;
    
    for(i=0;i<strlen(v_flat);i++)
        if(ch1==v_flat[i])
            type=FLAT;
        else if(ch1==v_round[i])
            type=ROUND;       
    
    return type;      
}

/*Returns the major type (HARD or SOFT) of the last vowel                     */
major_type find_last_type(const char* word, const char* v_hard, const char* v_soft)
{
    int i; /*For loops*/
    major_type last_type, type;
   
    for(i=0;i<strlen(word);i++)
    {
        type=major(word[i], v_hard, v_soft);
        if(type==HARD||type==SOFT)
            last_type=type;
    }        
    
    return last_type;
}            

/*Takes a string “noun” and returns itsplural form in “plural_noun”           *
 *(an output argument)                                                        */     
char* make_plural(const char* noun , char* plural_noun, const char* v_hard, const char* v_soft)
{
    char hard_plural[5]="lar", soft_plural[5]="ler"; /*For making plural*/
    major_type type;
    
    /*Copies to noun*/
    strcpy(plural_noun, noun);
    
    /*Calls find last type function*/
    type=find_last_type(plural_noun, v_hard, v_soft);
    
    if(type==HARD)
        strcat(plural_noun, hard_plural);
    else if(type==SOFT)
        strcat(plural_noun, soft_plural);
    
    return plural_noun;
}             

/*############################################################################*/
/*                End of HW06_Furkan_Erdol_131044065_part2.c                  */
/*############################################################################*/ 
