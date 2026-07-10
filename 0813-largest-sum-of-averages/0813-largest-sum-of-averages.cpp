class Solution {
public:
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
    }
};