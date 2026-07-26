class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        int maxL = 0;
        for(int i=0;i<n-1;i++){
            int count = 0;
            bool t1=false,t2=false;
            if(i < n-1 && nums[i] >= nums[i+1]) continue;
            int j = i;
            while( j< n-1 && nums[j] < nums[j+1]){
                t1 = true;
                count+=1;
                j++;
            }
            count++;
            j++;
            while( j < n && nums[j-1] > nums[j]){
                t2 = true;
                count+=1;
                j++;
            }
            if(t1 && t2){
                if(maxL < count){
                    maxL = count;
                    cout<<j;
                }
            }
        }

        return maxL;
    }
};