class Solution {
public:
    bool isAnagram(string s, string t) {
        int size1 = s.length();
        int size2 = t.length();
        sort(s.begin() , s.end());
        sort(t.begin() , t.end());
        for(int i =0 ; i<size1 ; i++){
            if(s == t && size1 == size2){
                return true;
            }
            
        }
    return false;
    }
};