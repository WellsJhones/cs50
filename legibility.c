#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1000

int main(void)
{
    int words = 1;
    int letters = 0;
    int sentences = 0;

    printf("Text: ");
    char c[MAX_LENGTH];
    fgets(c, MAX_LENGTH, stdin);

    int n = 0;
    while (c[n] != '\0')
    {.
        int ascii = tolower(c[n]);
        if (ascii == 32)
        {
            words++;
        }
        else if (ascii >= 97 && ascii <= 122)
        {
            letters++;
        }
        else if (ascii == 33 || ascii == 46 || ascii == 63)
        {
            sentences++;
        }

        n++;
    }
    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)index);
    }
    return 0;
}

// gcc -o legibility legibility.c -lm
// if make returns an error using round, use the command above to compile the program