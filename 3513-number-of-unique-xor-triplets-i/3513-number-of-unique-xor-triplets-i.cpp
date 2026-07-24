class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2) return 2;
        //unsigned 
        uint maxi = *max_element(nums.begin(),nums.end());
        return 1<<bit_width(maxi);
    }
};