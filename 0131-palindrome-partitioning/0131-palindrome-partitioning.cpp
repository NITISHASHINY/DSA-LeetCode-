class Solution {
public:
    vector<vector<string>> ans; 
    vector<vector<string>> partition(string s) {
        vector<string> substring;
        solve(0, s, substring);
        return ans;
    }
    //recursion
    void solve(int index, string &s, vector<string> &substring){
        if(index == s.length()){
            ans.push_back(substring);
            return;
        }
        for(int i = index; i<s.length(); i++){
            if(palindrome(s, index, i)){
                substring.push_back(s.substr(index, i-index + 1));
                solve(i + 1, s, substring);
                substring.pop_back();
            }
        }
    }   
    
    bool palindrome(string &s, int left, int right){
        while(left <= right){
            if(s[left] != s[right])return false;
            left++;
            right--;
        }
        return true;
    }

};