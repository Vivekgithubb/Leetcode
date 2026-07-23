class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int n = og.size();
        int m = og[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,1));
        if(og[0][0] == 1) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                if(og[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                int c1=0,c2=0;
                if(i>0){
                    c1 = dp[i-1][j];
                }
                if(j>0){
                    c2 = dp[i][j-1];
                }
                dp[i][j] = c1 + c2;
            }
        }
        return dp[n-1][m-1];
    }
};