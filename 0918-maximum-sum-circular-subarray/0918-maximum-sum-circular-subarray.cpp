class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int minSum = INT_MAX;
        int cur = 0;
        int total = 0;
        for(auto i : nums)
            total += i;
        //finding min subarray sum
        for(int i=0;i<n;i++){
            if(cur > 0)
                cur = nums[i];
            else 
                cur += nums[i];
            minSum = min( cur , minSum);
        }

        int maxSum = INT_MIN;
        cur = 0;
        //finding normal Max subbarray
        for(int i=0;i<n;i++){
            if(cur < 0)
                cur = nums[i];
            else 
                cur += nums[i];
            maxSum = max( cur , maxSum);
        }
        if( total == minSum)
            return max(maxSum , minSum);
        return max(maxSum , total - minSum) ;
    }   
};