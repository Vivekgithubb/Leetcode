class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        vector<int>range(n);
        int maxVal =INT_MIN;
        for(int i=0; i<n;i++){
            string s = to_string(nums[i]);
            int maxi = 0;
            int mini = 9;
            for(auto c : s){
                maxi = max(maxi,c-'0');
                mini = min(mini,c-'0');
            }
            range[i] = maxi-mini;
            maxVal = max(maxVal , range[i]);

        }
        int ans = 0;
        for(int i=0; i<n;i++){
            if(range[i] == maxVal)
                ans += nums[i];
        }
        return ans;
    }
};