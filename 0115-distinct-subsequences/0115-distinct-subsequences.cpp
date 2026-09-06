class Solution {
public:
    // int solve(string s , string t , int i, int j,vector<vector<int>>&dp){
    //     if(j < 0 ) return 1;
    //     if(i < 0 ) return j < 0;

    //     if(dp[i][j] != 0 && j < 0) return dp[i][j];

    //     int take = 0;
    //     int ntake = 0;
    //     ntake +=  solve(s,t,i-1,j, dp);
    //     if( s[i] == t[j])
    //         take  +=  solve(s,t,i-1,j-1, dp);

    //     return dp[i][j] = ntake+take;
    // }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long int>>dp(n+1,vector<unsigned long int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = dp[i-1][j];
                if(s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1];        
            }
        }
        return dp[n][m];
    }
};