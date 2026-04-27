class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        int i =0;
        if(n==0) return "";
        while(true){
            if(i>= strs[0].size())return ans;
            char c = strs[0][i];

            for(int j =1;j<n;j++){
                if(i>=strs[j].size() || strs[j][i] != c){
                    return ans;
                }
            }
            ans += c;
            i++;
            

        }
        return ans;


        
    }
};