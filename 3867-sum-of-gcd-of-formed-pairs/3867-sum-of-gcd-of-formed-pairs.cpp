class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(); 
        vector<long long>prefix(n,0);
        long long curmax=0;

        for(int i=0;i<nums.size();i++){
            curmax = max(curmax,1LL*nums[i]);
            prefix[i] = gcd(curmax , nums[i]);
        }

        sort(prefix.begin(),prefix.end());

        int i=0;
        int j = n-1;
        long long sum=0;
        while(i<j){
            long long curGcd = gcd(prefix[i],prefix[j]);
            sum+=curGcd;
            i++;j--;
        }
        return sum;
    }
};