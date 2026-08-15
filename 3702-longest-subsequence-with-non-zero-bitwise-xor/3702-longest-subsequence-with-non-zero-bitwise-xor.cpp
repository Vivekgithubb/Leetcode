class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        for(int i=0;i<nums.size();i++){
            x ^= nums[i];
        }  
        
        bool all  = true;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) continue;
            else all = false;
        }   
        if(all) return 0;
        if( x != 0 )  return nums.size();

        return nums.size()-1;
    }
};