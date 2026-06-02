class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int k =1;k<n;k++){
            string temp = "";
            int i =0;

            while(i<s.length()){
                int j = i;
                while(j<s.length() && s[j] == s[i]){
                    j++;
                }
                int count = j-i;
                temp += to_string(count);
                temp += s[i];
                i=j;
            }
            s = temp;
        }
        return s;
    }

        
};