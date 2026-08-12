class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;
        unordered_map<int,int>mp;
        int j=0;
        int i=0;
        while( j < n){
            mp[nums[j]]++;
            while(mp[nums[j]] > k ){
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans , j-i+1);
            j++;
        }
        return ans;
    }
};