class Solution {
public:
    int solve(int i, int total, int m , vector<int>&piles, vector<vector<int>>& dp){
        if( i >= piles.size()) return 0;
        if(dp[i][m] != -1) return dp[i][m];
        
        int t = INT_MIN;
        int curTotal = total - piles[i];
        
        for(int j=1; j <= 2*m; j++){
            if((i + j - 1 ) >= piles.size()) break;

            int rem = total - solve(i+j, curTotal ,max(j,m), piles,dp );
            if(i+j < piles.size())
                curTotal -= piles[i+j];

            t = max(rem,t);
        }

        return dp[i][m] = t;
    }
    int stoneGameII(vector<int>& piles) {
        int total = 0;
        for(auto p : piles) total += p;
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,total,1,piles,dp);
    }
};