class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid.size();
        int m = grid[0].size();

        auto possible = [&](int prev , int cur){
            for(int i=0;i<n;i++){
                if(abs(grid[i][prev] - grid[i][cur]) > limit)
                    return false;
            }
            return true;
        };
        vector<int>dp(m,1);
        for(int i=0; i<m;i++){
            int maxi = INT_MIN;
            for(int prev = 0; prev < i ; prev++){
                if(possible(prev,i))
                    dp[i] = max(1+dp[prev] , dp[i]);
                maxi = max(maxi,dp[i]);
            }
        }

        int ans = 0;
        for(auto i : dp){
            ans = max(ans,i);
        }
        return ans;
    }
};