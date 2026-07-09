class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>group(n,0);
        int curGroup = 0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1] > maxDiff)
                curGroup++;
            group[i] = curGroup;
        }

        for(auto q : queries){
            int u = q[0];
            int v = q[1];

            if( group[u] == group[v])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};