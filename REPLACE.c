#include <stdio.h>
#include <string.h>
FILE *f;
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




int replace(char *to_be_replaced, char *replacement)
{

    FILE *Input;
    FILE *Output;
    char *TemporaryFileName = "tmp.txt";/**< temporary file(output file, where the result will be printed) */
    char *Buffer[2000];/**< stores the string */
    Input = fopen("in.txt", "rt");
    Output = fopen("tmp.txt", "wt");

    if(Input==NULL)
    {
        printf("Empty or missing file!");
        return 1;
    }

    // For each line...
    while(fgets(Buffer, 2000, Input)!= NULL)
    {
        char *Stop = NULL;/**< pointer that marks what it's found before the given word */
        char *Start = Buffer;/**< pointer that helps to read until EOF */

        while(1)
        {


            Stop = strstr(Start, to_be_replaced);/**< reading the first location of the input string */
            if(Stop==NULL)
            {
                fwrite(Start, 1, strlen(Start), Output);/**< if we don't find the given word, the current word will be rewritten in the file */
                break;
            }


            fwrite(Start, 1, Stop - Start, Output);/**< writing data until the source string location */
            fwrite(replacement, 1, strlen(replacement), Output);/**< replacement is written to the output file */

            Start = Stop + strlen(to_be_replaced);/**< the pointer moves to the next character of the input string */
        }

    }

    fclose(Input);
    fclose(Output);

    remove("in.txt");/**< remove the initial file */
    rename(TemporaryFileName, "in.txt");/**< rename the temporary file */

}


int main()
{
    char to_be_replaced[50], replacement[50], s[256];
    printf("Enter the word that you want to replace as it is in the text:");
    scanf("%s", &to_be_replaced);
    if(find(s,to_be_replaced)==1)
    {
        printf("Enter the substitute:");
        scanf("%s", &replacement);

        replace(to_be_replaced, replacement);
        printf("The word has been replaced!");
    }
    else
    {
        printf("This word doesn't exist in the file!");
        exit(0);
    }


    return 0;
}
