class Solution {
public:
    int myAtoi(string s) {
        int c = 0;
        int n = s.size();
        long ans = 0;
        int sign = 1;

        // skip spaces
        while (c < n && s[c] == ' ') {
            c++;
        }

        // sign
        if (c < n && (s[c] == '+' || s[c] == '-')) {
            if (s[c] == '-') sign = -1;
            c++;
        }

        // digits
        while (c < n && isdigit(s[c])) {
            ans = ans * 10 + (s[c] - '0');

            if (sign * ans > INT_MAX) return INT_MAX;
            if (sign * ans < INT_MIN) return INT_MIN;

            c++;
        }

        return sign * ans;
    }
};