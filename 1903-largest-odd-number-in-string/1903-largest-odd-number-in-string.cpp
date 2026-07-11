class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();

        // Traverse from the last digit to the first
        for (int i = n - 1; i >= 0; i--) {

            // Check if the current digit is odd
            if ((num[i] - '0') % 2 == 1) {

                // Return the substring from index 0 to i
                return num.substr(0, i + 1);
            }
        }

        // No odd digit found
        return "";
    }
};