class Solution {
public:
    int solve(int i, int k , vector<vector<int>>&piles, vector<vector<int>>& dp ){
        if( k == 0 ||  i >= piles.size() )  return 0;
        if(dp[i][k] != -1) return dp[i][k];

        int take = 0;
        int notTake = solve( i+1, k , piles,dp);

        int n = piles[i].size();
        int sum = 0;
        for(int j=1 ; j <= min (n,k); j++){
            sum += piles[i][j-1];
            int ans = solve( i+1 , k-j , piles,dp) + sum;
            take = max(take,ans);
        }

        return dp[i][k] = max(take,notTake);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>>dp(piles.size()+1,vector<int>(k+1,-1));
        return solve(0,k,piles,dp);
    }
};