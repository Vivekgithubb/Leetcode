class Solution {
public:
    string smallestPalindrome(string s) {
        string str1="";
        string str2="";
        string str3="";
        int n = s.length();
        vector<int>mp(26,0);
        for(auto c : s){
            mp[c-'a']++;
        }
        for(int i=0;i<26;i++){
            int freq = mp[i];
            if(freq >= 2){
                str1.append(freq/2, i + 'a');
                str2.append(freq/2, i + 'a');
                mp[i] = mp[i] % 2 == 0 ? 0 : 1;
            }
        }
        if( n%2 != 0){
            for(int i=0;i<26;i++){
                int freq = mp[i];
                str3.append(freq, i + 'a');
            }
        }
        reverse(str2.begin(),str2.end());
        string ans = str1 + str3 + str2;
        return ans;
    }
};