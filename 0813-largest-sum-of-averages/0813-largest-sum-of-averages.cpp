class Solution {
public:
    double solve(vector<int>&arr,int k , int i,vector<vector<double>>& dp){
        int n = arr.size();
        if( i == n) return -1e9;
        if( k == 1 && i < n){
            double curAvg = arr[i];
            for(int j=i+1; j<n ;j++){
                curAvg += (double)arr[j];
            }
            curAvg = curAvg/(n-i);
            return curAvg;
        }

        k--;
        if(dp[i][k] != -1) return dp[i][k];
        
        double curAvg = arr[i];
        double sum = 0;
        double maxSum = -1e9;

        for(int j=i;j<n-k;j++){
            sum += arr[j];
            curAvg = sum/(j-i+1);
            double cost = curAvg + solve(arr,k,j+1,dp);
            maxSum = max(cost , maxSum);
        }

        return dp[i][k] = maxSum;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>>dp(n+1,vector<double>(k,-1));
        return solve(nums,k,0,dp);
    }
};