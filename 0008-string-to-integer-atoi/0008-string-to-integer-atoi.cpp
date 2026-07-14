class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.size();

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Step 2: Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long long num = 0;

        // Step 3: Read digits
        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Step 4: Overflow check
            if (num > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};