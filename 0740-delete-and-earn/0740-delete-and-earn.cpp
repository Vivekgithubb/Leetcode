class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        vector<int>v;
        
        sort(nums.begin(),nums.end());
        for(auto i : nums){
            mp[i]++;
            if(v.empty() || v.back() != i) 
                v.push_back(i);
        }

        int s = v.size();
        vector<int>dp(s,-1);
        if(n==1) return nums[0];
        dp[0] = nums[0]*mp[nums[0]];

        for(int i=1;i<s;i++){
            int take = v[i]*mp[v[i]];

            if(v[i] == v[i-1]+1){
                if(i > 1)
                    take += dp[i-2];
            }
            else
                take += dp[i-1];

            int notake = dp[i-1] + 0;
            dp[i] = max(take,notake);
        }
        return dp[s-1];
    }
};