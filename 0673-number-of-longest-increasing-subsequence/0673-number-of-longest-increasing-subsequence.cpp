class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>dp(n,{1,1});
        for(int i=1;i<n;i++){
            int val = dp[i].first;
            int count = dp[i].second;
            for(int j = 0 ; j < i; j++){
                if(nums[j] < nums[i]){
                    if(1+dp[j].first > val){
                        val = 1 + dp[j].first;
                        count = dp[j].second;
                    }else if( (1+dp[j].first) == val){
                        count += (dp[j].second);
                    }
                }
            }
            dp[i] ={val,count};
        }
        int count = 0;
        int maxL = INT_MIN;
        for(auto i : dp){
            int val = i.first;
            if(maxL < val){
                count = i.second;
                maxL = val;
            }
            else if(maxL == val)
                count+=i.second;
        }
        return count;
    }
};