class Solution {
public:
    int split(int k , vector<int>& nums){
        int num = 1;
        int sum = 0;
        for(int i=0 ;i<nums.size();i++){
            if(sum+nums[i] <= k){
                sum += nums[i];
            }else{
                num += 1;
                sum = nums[i];
            }
        } 
        return num;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = 0;
        for(auto i  : nums){
            high += i;
        }

        while( low <= high){
            int mid = low + (high - low)/2;

            if(split(mid,nums) > k){
                low = mid+1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};