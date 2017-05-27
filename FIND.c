#include <stdio.h>
#include <string.h>
FILE *f;
int main()
{
    char s[256];/**< the input string */
    char word[50];/**< the given word */
    f=fopen("in.txt","rt");
    printf("Enter the word without any spaces between the letters:");
    scanf("%s",word);
    if(find(s, word)==1)
    {
        printf("Yes, the word exists in this document!");
    }
    else
    {
        printf("No, the word doesn't exist in this document!");
    }
    return 0;
}

int find (char *s, char *word)
{
    f=fopen("in.txt","rt");/**< opening the input file */
    if (f ==NULL)
    {
        printf("Empty or missing file!");
        getch();
    }
    else
    {
        while(fscanf(f,"%s",s)>=0)/**< reading until EOF */
        {
            if (stricmp(word,s)==NULL)/**< verifies the existence of the given word */
            {
                return 1;
            }

        }

    }
    return 0;
    fclose(f);
    getch();

}


