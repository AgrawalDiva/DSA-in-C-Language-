#include <stdio.h>

int main()
{
    char ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    printf("Enter the text (press Ctrl+D or Ctrl+Z to end input):\n");

    while ((ch = getchar()) != EOF)
    {
        characters++;

        if (ch == '\n')
        {
            lines++;
        }

        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            inWord = 1;
            words++;
        }
    }

    printf("\nTotal characters: %d\n", characters);
    printf("Total words: %d\n", words);
    printf("Total lines: %d\n", lines);

    return 0;
}
