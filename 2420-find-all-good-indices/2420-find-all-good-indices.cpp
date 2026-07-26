class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        int count = 0;
        for(int i=1;i<n;i++){
            pre[i] = ++count;
            if(nums[i] > nums[i-1])
                count = 0;
        }
        count = 0;
        for(int i=n-2;i>=0;i--){
            suf[i] = ++count;
            if(nums[i] > nums[i+1])
                count = 0;   
        }   
        vector<int>ans;
        for(int i=k;i <= n-k ;i++){
            if(pre[i] >= k && suf[i] >= k)
                ans.push_back(i);
        }
        return ans;
    }
};