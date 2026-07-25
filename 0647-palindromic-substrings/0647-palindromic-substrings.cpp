class Solution {
public:
    int count = 0;
    void check(int l , int r , string s ){
        while( l >=0 && r < s.length() && s[l] == s[r]){
            l--;
            r++;
            count++;
        }
    }
    int countSubstrings(string s) {
        int n = s.length();
        for(int i=0;i<n;i++){
            check(i,i,s);
            check(i,i+1,s);
        }
        return count;
    }
};