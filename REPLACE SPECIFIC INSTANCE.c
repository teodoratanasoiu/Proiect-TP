#include <stdio.h>
#include <string.h>

FILE *f1;
FILE *f2;
int find (char *s, char *word)
{
    f1=fopen("in.txt","rt");/**< opening the input file */
    if (f1==NULL)
    {
        printf("Empty or missing file!");
        getch();
    }
    else
    {
        while(fscanf(f1,"%s",s)>=0)/**< reading until EOF */
        {
            if (stricmp(word,s)==NULL)/**< verifies the existence of the given word */
            {
                return 1;
            }

        }

    }
    return 0;
    fclose(f1);
    getch();

}



int occurrence(char *s, char *word)
{
    int counter=0;/**< counts the number of occurrences */
    f2=fopen("in.txt","rt");/**< opening the input file */
    while(fscanf(f2,"%s",s)>=0)/**< reading until EOF */
    {
        if(stricmp(s,word)==NULL)/**< if the word exists in the file, it will be counted */
        {
            counter++;

        }
    }
    return counter;
    fclose(f2);
    getch();
}





int specific_replacement(char *to_be_replaced, char *replacement, int position)
{


    FILE *Input,*Output;
    char Buffer[2000];
    char *TemporaryFileName = "tmp.txt";
    int count_to_position=0;
    Input = fopen("in.txt", "rt");
    Output = fopen(TemporaryFileName, "wt");

    if(Input==NULL)
    {
        printf("Empty or missing file!");
        exit(1);
    }


    while(fgets(Buffer, 2000, Input) != NULL)
    {
        char *Stop = NULL;
        char *Start = Buffer;


        while(1)
        {
            Stop = strstr(Start, to_be_replaced);
            if(Stop == NULL)
            {

                fwrite(Start, 1, strlen(Start), Output);
                break;
            }


            fwrite(Start, 1, Stop - Start, Output);
            count_to_position++; /**< it counts until it reaches the wanted position */
            if(count_to_position==position)/**< if it reaches the wanted position, it will make the replacement */
            {

                fwrite(replacement, 1, strlen(replacement), Output);
            }
            else
            {

                fwrite(to_be_replaced, 1, strlen(to_be_replaced), Output);
            }

            Start = Stop + strlen(to_be_replaced);

        }

    }

    fclose(Input);
    fclose(Output);
    remove("in.txt");
    rename(TemporaryFileName, "in.txt");
    printf("The word has been replaced!");
}

int main()
{

    FILE *Input;
    char to_be_replaced[50], replacement[50], s[256];
    int position=100,counter=0;
    printf("Enter the word that you want to replace:");
    scanf("%s",&to_be_replaced);
    if(find(s,to_be_replaced)==1)
    {
        printf("Enter the substitute:",to_be_replaced);
        scanf("%s",&replacement);
    }

    counter=occurrence(s,to_be_replaced);/**< stores the number of occurrences */
    if(position >= counter)
    {
        printf("Insert the position: ");
        scanf("%d",&position);
    }

    specific_replacement(to_be_replaced, replacement, position);
    return 0;
}

