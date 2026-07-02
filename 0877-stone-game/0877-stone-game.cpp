class Solution {
public:
    int maxAns(vector<int>& piles , int total , int i , int j , vector<vector<int>>& dp){
        if(i > j ) return 0;
        if(i == j) return piles[i];
        if(dp[i][j] != -1) return dp[i][j];

        int leftMax = total - maxAns(piles , total-piles[i] , i+1,j,dp);
        int rightMax = total - maxAns(piles , total-piles[j] , i,j-1,dp);

        return max(leftMax,rightMax);

    }
    bool stoneGame(vector<int>& piles) {
        int total = 0;
        int n = piles.size();
        for(auto i : piles) total += 1;
        vector<vector<int>>dp(n,vector<int>(n,-1));

        // int ans = maxAns(piles,total,0,n-1,dp);
        // return ans > total - ans;
        return true;
    }
};