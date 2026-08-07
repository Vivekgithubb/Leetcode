class Solution {
public:
    int solve(int i, int j, int k , vector<vector<int>>&piles ,  vector<vector<vector<int>>>& dp ){
        if( k == 0 ||  i >= piles.size() )  return 0;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];

        long long take = 0;
        long long notTake = solve( i+1, 0 , k , piles , dp);

        if( j < piles[i].size()){
            take = solve(i, j+1, k-1 , piles, dp ) + piles[i][j]; 
        }

        return dp[i][j][k] = max(take,notTake);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int maxJ = 0;
        for(auto i : piles){
            int s = i.size();
            maxJ = max(maxJ,s);
        }
        vector<vector<vector<int>>>dp(piles.size(),vector<vector<int>>(maxJ+1,vector<int>(k+1,-1)));
        return solve(0,0,k,piles,dp);
    }
};