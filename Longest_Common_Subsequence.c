#include <stdio.h>
#include <string.h>
int lcs(char X[], char Y[])
{
    int c = strlen(X);
    int d = strlen(Y);
    int L[c + 1][d + 1];
    int i, j;
    for (i = 0; i <= c; i++)
    {
        for (j = 0; j <= d; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                L[i][j] = L[i - 1][j-1] + 1;
            }
            else
            {
                L[i][j] = (L[i-1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }
    return L[c][d];
}
int main()
{
    char X[] = "AGGTABFJJIEOKDCJNRFKMWLKMWIGKREMDLWEJKMNFDWJKENKJFWKHKJDE ";
    char Y[] = "GXTXAYBERFWQRTGFWRTYUHGFSERTGWWRTGSFWEFRGWREEDFTWERFTFWEF ";
    printf("Length of LCS is %d",lcs(X, Y));
    return 0;
}