#include <stdio.h>
#include<string.h>
FILE *f;

int occurrence(char *s, char *word)
{

    int counter=0;/**< counts the number of occurrences */
    f=fopen("in.txt","rt");/**< opening the input file */
    while(fscanf(f,"%s",s)>=0)/**< reading until EOF */
    {
        if(stricmp(s,word)==NULL)/**< if the word exists in the file, it will be counted */
        {
            counter++;

        }
    }
    return counter;
    fclose(f);
    getch();
}





struct word_occurrence/**< stores each word and the number of its occurrences */
{
    int occurrence;/**< int for the number of occurrences */
    char each_word[50];/**< char for the words */

};



int sorted_list()
{
    struct word_occurrence o[1000];
    int n,i=0,j=0; /**< n=number of words */
    int aux;/**< helping variable */
    char auxword[50];
    char word[20]; /**< helping string for making the change */
    FILE *Input;
    char s[256];
    Input = fopen("in.txt", "rt");
    if(Input == NULL)
    {
        printf("Missing or empty file!");
        exit(0);
    }

    while(fscanf(Input,"%s ", word)>=0) /**< reading data until EOF */
    {


        strcpy(o[i].each_word, word);/**< stores each word and the number of its occurrences */
        o[i].occurrence=occurrence(s,word);/**< stores the number of occurrences */
        i++;
    }

    n=i-1;/**< in order to print all the words starting with 1 time occurrence */

    for(i=0; i<n; i++)
    {
        for(j=i; j<=n; j++)
        {
            if( o[i].occurrence > o[j].occurrence )   /**< sorting in ascending order */
            {
                aux=o[i].occurrence;
                strcpy(auxword, o[i].each_word);
                o[i].occurrence=o[j].occurrence;
                strcpy(o[i].each_word, o[j].each_word);
                o[j].occurrence=aux;
                strcpy(o[j].each_word, auxword);


            }
        }
    }

    for(i=0; i<=n; i++)
    {
        if(o[i].occurrence==1)
        {
            printf("\n%s -> %d occurrence", o[i].each_word, o[i].occurrence);
        }
        else
        {
            printf("\n%s -> %d occurrences",o[i].each_word, o[i].occurrence);
        }
    }

    fclose(Input);
}


int main()
{

    sorted_list();
    return 0;
}
