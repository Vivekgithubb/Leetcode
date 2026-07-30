class Solution {
public:
    int solve(int f , int s ,vector<int>& nums,vector<int>& pre){

        int maxLsum = 0;
        int result = 0;
        int n = nums.size();

        for(int mend = f+s-1 ; mend < n ; mend++){
            int msum = pre[mend] - (pre[mend-s]);
            int lsum = pre[mend-s] - ((mend-s-f) < 0 ? 0 : pre[mend-s-f]);

            maxLsum = max(maxLsum , lsum);
            result = max(result , msum + maxLsum);
        }
        return result;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        int n = nums.size();
        vector<int>pre(n,0);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        return max(solve(f,s,nums,pre),solve(s,f,nums,pre));
    }
};