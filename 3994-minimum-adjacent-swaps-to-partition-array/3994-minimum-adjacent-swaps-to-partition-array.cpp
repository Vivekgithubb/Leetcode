class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int mod = 1e9+7;
        for(int i=0;i<n;i++){
            if( nums[i] < a)
                nums[i] = 0;
            else if(nums[i] > b)
                nums[i] = 2;
            else 
                nums[i] = 1;
        }

        int swaps = 0;
        unordered_map<int,long long>mp;
        for(int i=0;i<n;i++){
            if( nums[i] == 2){
                mp[2] += 1;
            }
            else if(nums[i] == 1){
                swaps = (swaps + mp[2]) % mod;
                mp[1] += 1;
            }
            else{
                swaps = (swaps + mp[1]%mod + mp[2]%mod ) % mod;
                mp[0] += 1;
            }
        }
        return swaps % mod;
    }
};