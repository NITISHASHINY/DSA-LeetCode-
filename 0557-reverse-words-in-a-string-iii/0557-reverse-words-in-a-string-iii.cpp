class Solution {
public:
    string reverseWords(string s) {

        stack<char> st;
        string ans = "";

        for(char c : s) {

            if(c != ' ') {
                st.push(c);
            }
            else {

                while(!st.empty()) {
                    ans += st.top();
                    st.pop();
                }

                ans += ' ';
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};