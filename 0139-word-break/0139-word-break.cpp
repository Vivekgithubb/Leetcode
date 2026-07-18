class Solution {
public:
    bool solve(int i, string s , unordered_set<string>& v, vector<bool>& dp){
        
        if(!dp[i]) return false;
        
        int m = s.size();
        string word = "";
        
        for(int k = i ; k < m ; k++){
            word += s[k];
            if( v.find(word) != v.end()){
                if ( k == m-1) return true;

                if( k < m-1 && solve(k+1,s,v,dp))
                    return true; 
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        int m = s.size();
        unordered_set<string>v(wordDict.begin(),wordDict.end());
        vector<bool>dp(m+1, 1);
        return solve(0,s,v,dp);
    }
};