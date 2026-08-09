class Solution {
public:
    bool solve( int n, vector<int>&dp){
        if( n == 1) return 1;
        if( n <= 0 ) return 0;

        if(dp[n] != -1 ) return dp[n];

        for(int j=1; j*j<= n ; j++){
            bool rem = solve(n - (j*j) , dp);
            if( rem == false) 
                return dp[n] = 1;
        }
        return dp[n] = 0;

    }
    bool winnerSquareGame(int n) { 
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};