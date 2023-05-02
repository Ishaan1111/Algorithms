#include <stdio.h>
#include <string.h>
void compute_lps(char *pattern, int *lps)
{
    int pattern_length = strlen(pattern);
    int i = 1, j = 0;

    lps[0] = 0;

    while (i < pattern_length)
    {
        if (pattern[i] == pattern[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void kmp_string_match(char *text, char *pattern)
{
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);
    int lps[pattern_length];
    compute_lps(pattern, lps);
    int i = 0, j = 0;
    while (i < text_length)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == pattern_length)
        {
            printf("Pattern found at index %d\n ", i- j);
            j = lps[j - 1];
        }
        else if (i < text_length && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}
int main()
{
    char text[] = "The quick brown fox jumps over the lazy dog.";
    char pattern[] = "fox";
    kmp_string_match(text, pattern);
    return 0;
}
