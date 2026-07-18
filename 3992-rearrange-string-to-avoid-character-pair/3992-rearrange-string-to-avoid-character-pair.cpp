class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ys, xs, other;

        for (char c : s) {
            if (c == y)
                ys += c;
            else if (c == x)
                xs += c;
            else
                other += c;
        }

        return ys + xs + other;
    }
};