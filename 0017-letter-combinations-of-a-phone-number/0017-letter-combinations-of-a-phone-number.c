char *map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void solve(char *digits, int idx, char *cur,
           char **ans, int *cnt)
{
    if (digits[idx] == '\0')
    {
        cur[idx] = '\0';

        ans[*cnt] = malloc((idx + 1) * sizeof(char));
        strcpy(ans[*cnt], cur);
        (*cnt)++;

        return;
    }

    char *letters = map[digits[idx] - '0'];

    for (int i = 0; letters[i] != '\0'; i++)
    {
        cur[idx] = letters[i];
        solve(digits, idx + 1, cur, ans, cnt);
    }
}

char **letterCombinations(char *digits, int *returnSize)
{
    *returnSize = 0;

    if (digits == NULL || digits[0] == '\0'){
        return NULL;
    }

    int total = 1;

    for (int i = 0; digits[i] != '\0'; i++)
    {
        total *= strlen(map[digits[i] - '0']);
    }

    char **ans = malloc(total * sizeof(char *));
    char *cur = malloc((strlen(digits) + 1) * sizeof(char));

    int cnt = 0;

    solve(digits, 0, cur, ans, &cnt);
    free(cur);
    *returnSize = cnt;
    return ans;
}
