class Solution {
public:
    int solve(vector<int>&arr,int k , int i,vector<int>& dp){
        int n = arr.size();
        if( i == n) return 0;
        if(dp[i] != -1 ) return dp[i];
        int maxCost = 1;
        int maxE = arr[i];
        for(int j=i;j<n;j++){
            if(j-i+1 > k)   break;
            maxE = max(maxE , arr[j]);
            int cost = maxE*(j-i+1) + solve(arr,k,j+1,dp);
            maxCost = max(cost , maxCost);
        }

        return dp[i]= maxCost;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return solve(arr,k,0,dp);
    }
};