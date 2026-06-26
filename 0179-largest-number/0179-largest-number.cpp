class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans="";

        sort(nums.begin(),nums.end(),[](int a , int b){
            string f = to_string(a);
            string s = to_string(b);
            return (f+s) > (s+f) ;
        });
        int i=0;
        // if(nums[0] == 0){
        //     while( i<nums.size() && nums[i] == 0){
        //         i++;
        //     }
        //     if(i == nums.size())
        //         return "0";
        // }
        for(int j = i; j<nums.size(); j++){
            ans += to_string(nums[j]);
        }
        if(ans[0] == '0' ) return "0";

        return ans;
    }
};