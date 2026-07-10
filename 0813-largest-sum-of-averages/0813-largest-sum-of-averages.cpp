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
    double largestSumOfAverages(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<double>>dp(n+1,vector<double>(k+1,-1e9));
        for(int i=0;i<n;i++){
            double curAvg = arr[i];
            for(int j=i+1; j<n ;j++){
                curAvg += (double)arr[j];
            }
            curAvg = curAvg/(n-i);
            dp[i][1] = curAvg;
        }
        for(int c = 2 ; c <=k  ; c++){
            for(int i=n-1; i>=0 ; i--){
                double curAvg = arr[i];
                double sum = 0;
                double maxSum = -1e9;
                for(int j=i;j<n;j++){
                    sum += arr[j];
                    curAvg = sum/(j-i+1);
                    double cost = curAvg + dp[j+1][c-1];
                    maxSum = max(cost , maxSum);
                }
                dp[i][c] = maxSum;
            }
        }
        return dp[0][k];            
        // return solve(arr,k,0,dp);
    }
};