class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int left = 0;
        vector<int> freq(3, 0); // to count 'a', 'b', 'c'

        for (int right = 0; right < s.size(); ++right) {
            if (s[right] == 'a') freq[0]++;
            else if (s[right] == 'b') freq[1]++;
            else if (s[right] == 'c') freq[2]++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count += s.size() - right;
                if (s[left] == 'a') freq[0]--;
                else if (s[left] == 'b') freq[1]--;
                else if (s[left] == 'c') freq[2]--;
                left++;
            }
        }
        return count;
    }
};