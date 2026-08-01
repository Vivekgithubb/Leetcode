class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        if(nums.size() <= 1) return nums[0] == target;

        while(low <= high){
            int mid = low + (high - low)/2;
            int val = nums[mid];

            if(val == target){
                return true;
            }
            if(nums[low] == val && nums[high] == val){
                low++;
                high--;
            }
            else if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target < val)
                    high = mid-1;
                else
                    low = mid+1;
            }else{
                if(target > val && target <= nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return false;
    }
};