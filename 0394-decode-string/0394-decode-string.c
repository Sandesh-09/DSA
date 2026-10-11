#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* decodeString(char* s)
{
    int st[1000];
    char* str[1000];
    int top = -1;
    int n = 0;

    char* curr = (char*)malloc(100001);
    int l = 0;
    curr[0] = '\0';

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]))
        {
            n = n * 10 + (s[i] - '0');
        }
        else if (s[i] == '[')
        {
            st[++top] = n;
            str[top] = curr;
            curr = (char*)malloc(100001);
            l = 0;
            curr[0] = '\0';
            n = 0;
        }
        else if (s[i] == ']')
        {
            int r= st[top];
            char* prev = str[top--];

            int prevLen = strlen(prev);
            int currLen = strlen(curr);

            for (int j = 0; j < r; j++)
            {
                memcpy(prev + prevLen, curr, currLen);
                prevLen += currLen;
            }

            prev[prevLen] = '\0';
            free(curr);
            curr = prev;
            l = prevLen;
        }
        else
        {
            curr[l++] = s[i];
            curr[l] = '\0';
        }
    }

    return curr;
}