class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>visited;
        int left,maxlen=0;
        for(int right=0;right<s.size();right++){
            while(visited.count(s[right])){
                visited.erase(s[left]);
                left++;
            }
            visited.insert(s[right]);
            maxlen=max(maxlen,right-left+1);

        }
        return maxlen;

        
    }
    
};