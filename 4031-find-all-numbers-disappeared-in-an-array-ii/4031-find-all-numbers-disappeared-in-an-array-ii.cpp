class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>ans;
        vector<int>v(upper+1,0);
        // if(upper - lower < 1) return {};
        for(int i=0;i<nums.size();i++){
            if( nums[i] > upper) continue;
            v[nums[i]] = 1;
        }
        
        int start = lower;
        int end = 0;
        for(int i=lower;i<=upper;i++){
            while(i <= upper && v[i] == 0) i++;
            end = i - 1;
            if( end >= start) 
                ans.push_back({start,end});
            start = end + 2; 
        }
        return ans;
    }
};