#include <stdio.h>
#include <string.h>
FILE *f;
int main()
{
    char s[256];/**< the input string */
    char word[50];/**< the given word */
    int counter=0;/**< counts the number of occurrences */
    f=fopen("in.txt","rt");
    printf("Enter the word without any spaces between the letters:");
    scanf("%s",word);
    counter=occurrence(s, word);
    if(occurrence(s, word) > 0)
    {
        printf("This word appears in the document for %d time[s]!", counter);
    }
    else
    {
        printf("This word doesn't exist in the document!");

    }
    return 0;
}

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
