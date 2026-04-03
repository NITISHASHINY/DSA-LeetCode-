class Solution {
public:
    unordered_set<string> dict;  // store words for O(1) lookup
    unordered_map<int, vector<string>> memo; // memo[start] → all sentences from index 'start'

    vector<string> dfs(string &s, int start) {

        // 🔹 If already computed, return stored result
        if (memo.count(start)) return memo[start];

        vector<string> res;  // store all valid sentences from this index

        // 🔹 Base case: reached end of string
        if (start == s.size()) {
            res.push_back("");  // return empty string to help in concatenation
            return res;
        }

        string word = ""; // current substring

        // 🔹 Try all possible substrings starting from 'start'
        for (int end = start; end < s.size(); end++) {
            word += s[end];  // build substring step by step

            // 🔹 If substring is in dictionary
            if (dict.count(word)) {

                // 🔹 Recurse for remaining string
                vector<string> temp = dfs(s, end + 1);

                // 🔹 Combine current word with results of recursion
                for (string &t : temp) {

                    // If t is empty → last word, no space needed
                    // else → add space between words
                    res.push_back(word + (t.empty() ? "" : " " + t));
                }
            }
        }

        // 🔹 Store result in memo and return
        return memo[start] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        // 🔹 Convert dictionary to set for fast lookup
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());

        // 🔹 Start recursion from index 0
        return dfs(s, 0);
    }
};