class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int j=0;
        int sum = 0;
        for(int i=0;i<n;i++){
            while(j < n){
                sum += nums[j];
                ans = max({sum , ans , nums[j]});
                j++;
                if( sum  < 0){
                    sum = 0;
                }
            }
            i = j;
        }
        return ans;
    }
};