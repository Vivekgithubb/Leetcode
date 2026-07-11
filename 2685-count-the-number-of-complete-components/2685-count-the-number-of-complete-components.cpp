class Solution {
public:
    void dfs (int n ,vector<vector<int>>& adjl,vector<int>& vis, vector<int>& temp){
        vis[n] = 1;

        temp[0] += 1;
        for(auto e : adjl[n]){
            temp[1] += 1;
            if(!vis[e]){
                dfs(e,adjl,vis,temp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>>adjl(n);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        vector<int>vis(n,0);
        for(int i=0 ; i<n ; i++){
            if(vis[i]) continue;
            vector<int>temp(2,0);
            dfs(i,adjl,vis,temp);
            int n = temp[0];
            int e = temp[1];
            int edgesCal = n*(n-1);
            if(edgesCal == e){
                ans++;
                cout<<i;
            }
        }

        return ans;
    }
};