class Solution {
public:
    // bool predict(int i, int j , int s1  , int s2 , bool turn , vector<int>& nums){

    //     if(i>j) return s1>=s2;
    //     if(i==j){
    //         if(turn)    return (s1+nums[i]) >= s2;
    //         else        return s1 >= (s2 + nums[i]);
    //     }

    //     bool nt = 0;
    //     bool t = 0;
    //     if(turn){
    //         nt = predict(i,j-1,s1 + nums[j] ,s2,false,nums);  
    //         t = predict(i+1,j,s1 + nums[i],s2,false,nums);
    //     }else{
    //         nt = predict(i,j-1,s1,s2  + nums[j]  ,true,nums);  
    //         t = predict(i+1,j,s1 ,s2+ nums[i],true,nums);
    //     }
    //     if(turn)
    //         return nt || t ;

    //     return nt && t;
    // }

    //ans=max player 1 can score and total=sum of all elements in the array
    //so, player2's score=total-player1's score . ie:-total-ans;
	//According to question player1's score should be greater than or equal to player2's score. 
    int maxScore(vector<int>& nums, vector<vector<int>>&dp ,int total , int i, int j){
        if( i > j) return 0;
        if(dp[i][j] !=-1 ) return dp[i][j];

        //max the current player can get is total-maxm the next player can get.
        int curPlayerMax = total - min( maxScore(nums,dp, total-nums[i], i+1, j) , maxScore(nums,dp, total-nums[j], i, j-1));
        return curPlayerMax;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;

        //dp[i][j]= maxm a player can score if they have access to elements form index i to index j only
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int total = 0;
        for(auto i : nums) total+=i;
        
        int ans = maxScore(nums,dp,total,0,n-1);
        return ans >= total-ans;

        // return predict(0,n-1,0,0,true,nums);
    }
};