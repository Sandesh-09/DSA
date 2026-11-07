int calculate(char* s) {
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] == '*' || s[i] == '/') {

            int l = i - 1;
            while (l >= 0 && s[l] == ' ')
                l--;

            int r = i + 1;
            while (s[r] == ' ') r++;

            int start = l;
            while (start >= 0 && isdigit(s[start])) start--;

            int end = r;
            while (isdigit(s[end])) end++;

            int a = atoi(s + start + 1);
            int b = atoi(s + r);

            int ans;

            if (s[i] == '*')
                ans = a * b;
            else
                ans = a / b;

            char temp[32];
            sprintf(temp, "%d", ans);

            int prefix = start + 1;
            int suffix = end;

            memmove(s + prefix + strlen(temp), s + suffix, strlen(s + suffix) + 1);
            memcpy(s + prefix, temp, strlen(temp));

            n = strlen(s);
            i = -1;
        }
    }

    int ans = 0;
    int sign = 1;
    int num = 0;

    for (int i = 0; i <= n; i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
            ans += sign * num;
            num = 0;

            if (s[i] == '-')
                sign = -1;
            else
                sign = 1;
        }
    }

    return ans;
}