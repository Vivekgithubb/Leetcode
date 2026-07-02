class Solution {
public:
    bool predict(int i, int j , int s1  , int s2 , bool turn , vector<int>& nums){

        if(i>j) return s1>=s2;
        if(i==j){
            if(turn)    return (s1+nums[i]) >= s2;
            else        return s1 >= (s2 + nums[i]);
        }

        bool nt = 0;
        bool t = 0;
        if(turn){
            nt = predict(i,j-1,s1 + nums[j] ,s2,false,nums);  
            t = predict(i+1,j,s1 + nums[i],s2,false,nums);
        }else{
            nt = predict(i,j-1,s1,s2  + nums[j]  ,true,nums);  
            t = predict(i+1,j,s1 ,s2+ nums[i],true,nums);
        }
        if(turn)
            return nt || t ;

        return nt && t;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        return predict(0,n-1,0,0,true,nums);
    }
};