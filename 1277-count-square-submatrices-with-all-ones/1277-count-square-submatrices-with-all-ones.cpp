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
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if( matrix[i][j] == 0 ) 
                    continue ;

                int l = dp[i][j+1];
                int d = dp[i+1][j+1];
                int r = dp[i+1][j];
                dp[i][j] = 1 + min({l,r,d});

                if(dp[i][j] >= 1 )
                    ans += dp[i][j];
            }
        }
        return ans;
    }
};