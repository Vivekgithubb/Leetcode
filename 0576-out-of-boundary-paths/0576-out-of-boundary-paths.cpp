class Solution {
public:
    int mod = 1e9+7;
    int r[4] = {-1,0,1,0};
    int c[4] = {0,-1,0,1};
    int dfs(int moves, int i, int j, int n , int m, int maxMove,vector<vector<vector<int>>>& dp){
        if((i == n || j == m) || ( i < 0 || j < 0)){
            return moves <= maxMove;
        }
        if(moves > maxMove) return 0;

        if(dp[i][j][moves] != -1) return dp[i][j][moves];

        int curCount = 0;
        for(int k=0;k<4;k++){
            int nr = r[k] + i;
            int nc = c[k] + j;
            curCount = (curCount + dfs(moves+1,nr,nc,n,m,maxMove,dp)%mod)%mod ;
        }
        return dp[i][j][moves] = curCount%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1 , -1)));
        return dfs(0,startRow , startColumn, m, n, maxMove,dp)%mod;
    }
};