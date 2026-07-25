class Solution {
public:
    int solve(vector<int> needs, vector<int>& price, vector<vector<int>>& special,map<vector<int>,int>& dp ){

        if(dp.count(needs)) return dp[needs];
        bool done = true;
        for(int i=0;i<needs.size();i++){
            if(needs[i] != 0){
                done = false;
                break;
            }
        }
        if(done) return 0;

        vector<int>tempNeeds = needs;
        int tempCost = 0;
        for(int i=0; i<needs.size(); i++){
            tempCost += (tempNeeds[i] * price[i]);
            tempNeeds[i] = 0;
        }
        int dirCost = tempCost;

        int takeCost = INT_MAX;
        int n = needs.size();
        for(int s = 0 ; s<special.size();s++){
            bool take = true;
            vector<int>newNeed = needs;
            for(int k = 0; k < special[0].size()-1; k++){
                if( newNeed[k] < special[s][k]){
                    take = false;
                    break;
                }
                newNeed[k] -= special[s][k];
            }
            if(take){
                int curCost = special[s][n];
                takeCost = min(takeCost ,curCost + solve(newNeed,price,special , dp));
            }            
        }
        return dp[needs] = min(dirCost , takeCost);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = needs.size();
        map<vector<int>,int >dp;
        return solve(needs,price,special, dp);
    }
};