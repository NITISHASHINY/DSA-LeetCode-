class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0 ; i<haystack.length();i++){
            int ans = haystack.find(needle);
            return ans;
        }
        
        

    return -1;   
    }

    
};