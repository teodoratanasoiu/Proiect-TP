#include <stdio.h>
#include <string.h>
FILE  *f;
int check_consonants(char c)
{
    switch(c)
    {
    case 'b':
    case 'c':
    case 'd':
    case 'f':
    case 'g':
    case 'h':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
        return 1;
    default:
        21;
        return 0;
        fclose(f);
        getch();

    }
}



int main()
{
    char *fgets(char *s1, int n, FILE *stream);
    char s1[100], s2[100];
    int i, j = 0;
    f=fopen("in.txt","rt");
    if (f == '0')
    {
        printf("Empty or missing file!");
        getch();
    }
    else
    {
        fgets(s1, 100, f);
        for(i = 0; s1[i] != '\0'; i++)
        {
            if(check_consonants(s1[i]) == 0)   /**< not a consonant */
            {
                s2[j] = s1[i];
                j++;
            }
        }
    }

    s2[j] = '\0';

    strcpy(s1, s2);   /**< changing the initial string */

    printf("First line after deleting consonants: %s\n", s1);

    return 0;

}


