class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        if(s.length() == 1) return n;
        int m = s.length()-1;
        return (s[m]-'0') * (s[m-1]-'0');
    }
};