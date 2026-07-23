class Solution {
public:
    int solve(int i,int j , int n , int m,int count,vector<vector<int>>&dp){
        if( i==n-1 && j == m-1) return count+1;
        if( i >= n || j>= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int c1 = solve(i+1,j,n,m,count,dp);
        int c2 = solve(i,j+1,n,m,count,dp);
        count += c1+c2;

        return dp[i][j] = count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,0,dp);
    }
};