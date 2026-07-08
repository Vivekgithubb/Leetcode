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
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // int ans1 = LR(s,0,0,dp);
        dp[n][1] = 0;
        dp[n][0] = 0;
        for(int ind=n-1 ; ind>=0; ind-- ){
            for(int prev = 0; prev <=1 ;prev++){
                int ans1 = INT_MAX;
                int ans2 = INT_MAX;      
                if(prev == 0){
                    //no flip or flip
                    if(s[ind] == '0'){
                        ans1 = dp[ind+1][0]; 
                        ans2 = 1 + dp[ind+1][1]; 
                    }
                    if( s[ind] == '1'){
                        ans1 = dp[ind+1][1];
                        ans2 = 1 + dp[ind+1][0];
                    }
                }else{
                    //no flip or flip
                    if(s[ind] == '0'){
                        ans1 = 1 + dp[ind+1][1];
                    }
                    if( s[ind] == '1'){
                        ans1 = dp[ind+1][1];
                    }
                }
                dp[ind][prev] = min(ans1,ans2);
            }
        }
        return dp[0][0];
    }
};