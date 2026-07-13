class Solution {
public:
    int find(int i , int j , vector<vector<int>>& m, vector<vector<int>>& dp){
        if( i <0 || j<0) return 0;
        if( m[i][j] == 0 ) return 0;
        if(dp[i][j] != -1) return dp[i][j]; 

        int l = find(i,j-1,m,dp);
        int d = find(i-1,j-1,m,dp);
        int r = find(i-1,j,m,dp);

        return dp[i][j] = 1 + min({l,r,d});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans += find(i,j,matrix,dp);
            }
        }
        return ans;
    }
};