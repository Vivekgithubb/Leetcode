class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int count = 0;
        int pMax = 0;
        int ans  = 0;
        for(int i=0;i<colors.size(); i++){
            if( i > 0 && colors[i] != colors[i-1])
                pMax = 0;
            int cur = neededTime[i];
            ans += min(cur,pMax);
            pMax = max(cur,pMax);
        }

        return ans;
    }
};