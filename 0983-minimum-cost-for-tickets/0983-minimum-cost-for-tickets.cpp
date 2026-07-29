class Solution {
public:
    int solve(int j ,vector<int>& days, vector<int>& costs,  vector<int>& dp){
        int n = days.size();
        if( j == n){
            return 0;
        }
        if(dp[j] != -1) return dp[j];
        int cost = 0;

        int oday = costs[0] + solve( j+1 , days, costs,dp);

        int s = j,t=j;
        while(s < n && days[s] < (days[j]+7)) s++; 
        int sday = costs[1] + solve(s, days, costs,dp);

        while(t < n && days[t] < (days[j]+30)) t++; 
        int tday = costs[2] + solve(t, days, costs,dp); 
        
        cost = min({oday,sday,tday});
        return dp[j] = cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n,-1);
        return solve(0,days,costs,dp);
    }
};