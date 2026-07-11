class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for (char ch : s) {

            // Opening bracket
            if (ch == '(') {

                // If depth > 0, it is not the outermost '('
                if (depth > 0)
                    ans += ch;

                depth++;
            }

            // Closing bracket
            else {

                depth--;

                // If depth > 0 after decreasing,
                // it is not the outermost ')'
                if (depth > 0)
                    ans += ch;
            }
        }

        return ans;
    }
};