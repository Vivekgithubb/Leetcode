class Solution {
public:
    bool solve(int aSum , int bSum , int i , int j , vector<int>& nums, bool turn){
        if( i > j)
            return aSum >= bSum;
        if( i == j){
            if(turn) aSum + nums[i] >= bSum;
            else aSum >= nums[i] + bSum;
        }

        bool t = false;
        bool nt = false;
        if(turn){
            t = solve(aSum + nums[i],bSum , i+1,j,nums,false);
            nt = solve(aSum + nums[j] , bSum , i,j-1,nums,false);
        }else{
            t = solve(aSum , nums[i] + bSum , i+1,j,nums,true);
            nt = solve(aSum , nums[j] + bSum , i,j-1,nums,true);         
        }
        //a has to win , so use OR
        if(turn)
            return nt || t;
        return t && nt;
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return solve(0,0,0,n-1,nums,1); 
    }
};