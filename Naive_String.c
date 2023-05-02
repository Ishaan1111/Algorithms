#include <stdio.h>
#include <string.h>

void naive_string_match(char *text, char *pattern)
{
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);
    for (int i = 0; i <= text_length - pattern_length; i++)
    {
        int j;
        for (j = 0; j < pattern_length; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == pattern_length)
        {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main()
{
    char text[] = "The quick brown fox jumps over the lazy dog.";
    char pattern[] = "fox";
    naive_string_match(text, pattern);
    return 0;
}