class Solution {
public:
    bool check(string s1, string s2, string s3, int i, int j , vector<vector<int>>&dp){
        int n = s1.size();
        int m = s2.size();
        int size = s3.size();
        int k = i+j;
        if(dp[i][j] != -1) return dp[i][j];
        if( j == m && i==n )  return true;
        bool t=false,nt=false;
        if(i < n && s1[i] == s3[k])
            t = check(s1,s2,s3,i+1,j,dp);
        
        if(j < m && s2[j] == s3[k])
           nt = check(s1,s2,s3,i,j+1,dp);

        return dp[i][j] = (t || nt);
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int size = s3.size();

        if(n+m != size) return false;
        if(n == 0)
            return s2 == s3;
        else if( m == 0)
            return s1 == s3;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return check(s1,s2,s3,0,0,dp);
    }
};