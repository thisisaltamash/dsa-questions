class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> freq;

        for(char ch : s)
            freq[ch]++;

        vector<pair<char,int>> arr;

        for(auto x : freq)
            arr.push_back(x);

        sort(arr.begin(), arr.end(),
            [](auto &a, auto &b){
                return a.second > b.second;
            });

        string ans = "";

        for(auto x : arr)
        {
            ans.append(x.second, x.first);
        }

        return ans;
    }
};