class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int n = s.length();
        int ans = INT_MIN;
        int i=0;
        int j=0;
        while( j < n){
            char c = s[j];
            mp[c]++;
            while(i <= j && mp[c] > 2){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};