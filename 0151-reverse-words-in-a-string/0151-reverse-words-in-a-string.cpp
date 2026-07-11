class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;
        string word = "";

        // Traverse the string
        for (int i = 0; i < s.size(); i++) {

            // Build the current word
            if (s[i] != ' ') {
                word += s[i];
            }

            // Space encountered
            else {

                // Store the completed word
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            }
        }

        // Push the last word (if any)
        if (!word.empty()) {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        // Build the final answer
        string ans = "";

        for (int i = 0; i < words.size(); i++) {

            ans += words[i];

            // Don't add space after the last word
            if (i != words.size() - 1) {
                ans += " ";
            }
        }

        return ans;
    }
};