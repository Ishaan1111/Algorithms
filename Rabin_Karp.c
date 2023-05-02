#include<stdio.h>
#include<string.h>
#include<math.h>

#define d 256
#define q 101 

void rabin_karp_string_match(char *text, char *pattern)
{
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);
    int i, j;
    int pattern_hash = 0; // hash value for pattern
    int text_hash = 0; // hash value for current substring of text
    int h = 1;  
    // calculate h value: d^(m-1) % q
    for (i = 0; i < pattern_length - 1; i++)
    {
        h = (h * d) % q;
    }
    
    // calculate hash value for pattern and first substring of text
    for (i = 0; i < pattern_length; i++)
    {
        pattern_hash = (d * pattern_hash + pattern[i]) % q;
        text_hash = (d * text_hash + text[i]) % q;
    }
    // slide the pattern over the text and compare hash values
    for (i = 0; i <= text_length - pattern_length; i++)
    {
        // if hash values match, check for exact match 
        if (pattern_hash == text_hash)
        {
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
         // calculate hash value for next substring of text 
         if (i < text_length - pattern_length)
        {
            text_hash = (d * (text_hash - text[i] * h) + text[i + pattern_length]) % q;
            if (text_hash < 0)
            {
                text_hash = (text_hash + q);
            }
        }
    }
}
int main()
{
    char text[] = "The quick brown fox jumps over the lazy dog.";
    char pattern[] = "fox";
    rabin_karp_string_match(text, pattern);
    return 0;
}