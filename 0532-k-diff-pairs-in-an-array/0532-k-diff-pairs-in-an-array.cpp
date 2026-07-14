class Solution {
public:
    int binary(int i , int l , int h ,int k , vector<int>& nums){
        while( l <= h){
            int mid = l + (h - l)/2;
            int ans = abs(nums[i]-nums[mid]);
            if( ans == k){
                return 1;
            }else if( ans > k)
                h = mid-1;
            else 
                l = mid + 1;
        }
        return 0;
    }
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(nums.size() == 2) return (nums[1]-nums[0]) == k;
        for(int i=0;i<n-1;i++){
            count += binary(i,i+1,n-1,k,nums);
            while(i+1 < n && nums[i] == nums[i+1])
                i++;
        }
        return count;
    }
};