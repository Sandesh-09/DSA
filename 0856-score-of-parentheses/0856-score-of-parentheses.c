int scoreOfParentheses(char* s) {
    int ans = 0;
    int balance = 0;

    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] == '(') {
            balance++;
        }
        else {
            balance--;

            if (s[i - 1] == '(') {
                ans += 1 << balance;
            }
        }
    }

    return ans;
}
