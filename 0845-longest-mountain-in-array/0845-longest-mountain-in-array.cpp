class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        bool flip = false;
        int maxL = 0;
        for(int i=0;i<n-1;i++){
            int count = 1;
            bool t1=false,t2=false;
            if(i < n-1 && nums[i] >= nums[i+1]) continue;
            int j = i;
            while( j < n-1 && nums[j] < nums[j+1]){
                t1 = true;
                count+=1;
                j++;
            }
            while( j < n-1 && nums[j] > nums[j+1]){
                t2 = true;
                count+=1;
                j++;
            }
            if(t1 && t2) maxL = max(maxL,count);
            i = j-1;
        }

        return maxL;
    }
};