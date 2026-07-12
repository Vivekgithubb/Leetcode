class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int cost = 0;
        long long sum =0;
        long long count = 0;
        int mod = 1e9+7;
        int n = nums.size();
        int st = k;
        for(int i=0 ;i<n;i++){
            if( st - nums[i] >=0 ){
                st -= nums[i];
            }
            else{
                int op = k;
                double req = ceil((double)(nums[i]-st) / (double)op);

                long long l = (count+1)%mod ;
                count = 1LL*(count + req) ;
                long long r = (count)%mod ;
                sum += (1LL*(r*(r+1)/2)%mod - 1LL*(l*(l-1)/2)%mod)%mod ;

                st = st + (op*req);
                st = (st-nums[i]);
            }
        }

        return sum;
    }
};