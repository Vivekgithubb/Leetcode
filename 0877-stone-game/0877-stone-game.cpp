class Solution {
public:
    int maxAns(vector<int>& piles , int total , int i , int j , vector<vector<int>>& dp){
        if(i > j ) return 0;
        if(i == j) return piles[i];
        if(dp[i][j] != -1) return dp[i][j];

        int leftMax = total - maxAns(piles , total-piles[i] , i+1,j,dp);
        int rightMax = total - maxAns(piles , total-piles[j] , i,j-1,dp);

        return dp[i][j]=max(leftMax,rightMax);

    }
    bool stoneGame(vector<int>& piles) {
        int total = 0;
        int n = piles.size();
        for(auto i : piles) total += i;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        int ans = maxAns(piles,total,0,n-1,dp);
        return ans > total - ans;

        // for(int i=n-1; i>=0 ; i--){
        //     for(int j=0;j<n;j++){
        //         if(i==j){
        //             dp[i][j] = piles[i];
        //             continue;
        //         }
        //         if(i>j) continue;
        //         int leftMax = piles[i] - dp[i+1][j];
        //         int rightMax = piles[j] - dp[i][j-1]; 

        //         dp[i][j] = max(leftMax,rightMax);
        //     }
        // }

        // return dp[1][n-1] >= 0;
        // return true;
    }
};