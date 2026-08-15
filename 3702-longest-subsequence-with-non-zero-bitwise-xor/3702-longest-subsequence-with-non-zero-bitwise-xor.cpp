class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            x ^= nums[i];
            mp[x] = i; 
        }  
        

        int ans = 0;
        bool all  = true;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) continue;
            if( mp.find(nums[i]) != mp.end() ){
                all = false;
            }
        }   
        if(all) return 0;
        if( x != 0 ) 
            return nums.size();

        return nums.size()-1;
    }
};