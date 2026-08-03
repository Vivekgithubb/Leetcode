class Solution {
public:
    int solve(int i ,vector<int>& stoneValue,vector<int>& dp){
        int n = stoneValue.size();
        if( i == n) return 0;
        if(dp[i] != -1) return dp[i];
        
        int cur = 0;
        cur = stoneValue[i] - solve(i+1,stoneValue,dp);
        if(i+1 < n )
            cur = max(cur , stoneValue[i]+stoneValue[i+1] - solve( i+2 , stoneValue,dp));
        if( i + 2 < n)
            cur = max(cur , stoneValue[i]+stoneValue[i+1]+ stoneValue[i+2] - solve( i+3 , stoneValue,dp));
        
        return dp[i] = cur;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int diff = 0;
        int n = stoneValue.size();
        vector<int>dp(n,-1);
        diff = solve(0,stoneValue,dp);
        if(diff > 0) return "Alice";
        if(diff < 0) return "Bob";
        return "Tie"; 
    }
};