class Solution {
public:
    bool isPalin(string &temp){
        int i=0;
        int j= temp.size()-1;
        while(i < j){
            if( temp[i] != temp[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1,0);

        for(int i=n-1; i>=0 ; i--){
            string temp = "";
            int minCost = INT_MAX;
            for(int j=i ;j<n ;j++){
                temp += s[j]; 
                if(isPalin(temp)){
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost , cost);
                }
            }
            dp[i] = minCost;
        }

        return dp[0]-1;
    }
};