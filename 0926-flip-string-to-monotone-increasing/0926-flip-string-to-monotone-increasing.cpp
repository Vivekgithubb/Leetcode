class Solution {
public:
    int LR(const string & s , int ind , int prev, vector<vector<int>>& dp){
        int n = s.size();
        if( ind == n) 
            return 0;
        
        if(dp[ind][prev] != -1 ) return dp[ind][prev];
        int ans1 = INT_MAX;
        int ans2 = INT_MAX;      
        if(prev == 0){
            //no flip or flip
            if(s[ind] == '0'){
                ans1 = LR(s,ind+1,0,dp); 
                ans2 = 1 + LR(s,ind+1,1,dp); 
            }
            if( s[ind] == '1'){
                ans1 = LR(s,ind+1,1,dp);
                ans2 = 1 + LR(s,ind+1,0,dp);
            }
        }else{
            //no flip or flip
            if(s[ind] == '0'){
                ans1 = 1 + LR(s,ind+1,1,dp); 
            }
            if( s[ind] == '1'){
                ans1 = LR(s,ind+1,1,dp);
            }
        }
        return dp[ind][prev] = min(ans1,ans2);
    }
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int ans1 = LR(s,0,0,dp);
        return ans1;
    }
};