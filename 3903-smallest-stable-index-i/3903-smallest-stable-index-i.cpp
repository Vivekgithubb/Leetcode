class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ma(n);
        vector<int>mi(n);

        int mini=nums[n-1];
        int maxi=nums[0];

        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            ma[i] = maxi;
        }
        for(int i=nums.size()-1;i>=0;i--){
            mini= min(mini,nums[i]);
            mi[i] = mini;
        }

        for(int i=0;i<nums.size();i++){
            int cur = ma[i]-mi[i];
            if(cur <= k ) 
                return i;
        }

        return -1;
        
    }
};