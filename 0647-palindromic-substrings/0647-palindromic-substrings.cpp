class Solution {
public:
    bool check(int l , int r , string& s , vector<vector<int>>& dp){
        if( l >= r ) return 1;
        if(dp[l][r] != -1) return dp[l][r];

        if( s[l] == s[r])
            return dp[l][r] = check(l+1, r-1 , s , dp);
        return dp[l][r] = 0;
    }
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s,dp))
                    count++;
            }
        }
        return count;
    }
};