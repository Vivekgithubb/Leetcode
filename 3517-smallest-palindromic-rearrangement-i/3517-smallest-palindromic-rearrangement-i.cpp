class Solution {
public:
    string smallestPalindrome(string s) {
        string str1="";
        string str2="";
        string str3="";
        int n = s.length();
        map<char,int>mp;
        for(auto c : s){
            mp[c]++;
        }
        for(auto &[c,freq] : mp){
            if(freq >= 2){
                str1.append(freq/2, c);
                str2.append(freq/2, c);
                freq = freq % 2 == 0 ? 0 : 1;
            }
        }
        if( n%2 != 0){
            for(auto &[c,freq] : mp){
                str3.append(freq,c);
            }
        }
        reverse(str2.begin(),str2.end());
        string ans = str1 + str3 + str2;
        return ans;
    }
};