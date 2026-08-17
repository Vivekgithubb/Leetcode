class Solution {
public:
    int minPenalty(int p, vector<int>& l, vector<int>& at) {
        int ans = INT_MIN;
        int cur = INT_MAX;
        int maxE = *max_element(l.begin(),l.end());
        for(int i=0;i<at.size();i++){
            int r = at[i]%p;
            int wait = -1;

            if( r < maxE)
                wait = 0;
            else 
                wait = p - r;

            ans = max(wait,ans);
        }
        return ans;
    }
};