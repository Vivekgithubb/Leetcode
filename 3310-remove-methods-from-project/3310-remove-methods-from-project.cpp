class Solution {
public:
    void dfs(vector<int>&sus , vector<vector<int>>& adj, int i , int k ,vector<int>&vis){
        vis[i] = 1;
        for(auto v : adj[i]){
            if(!vis[v]){
                sus[v] = 1;
                dfs(sus,adj,v,k,vis);
            }
        }
        return;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>sus(n,0);
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto i : invocations){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }

        //find all sus nodes 
        sus[k] = 1;
        for(int i=0;i<n; i++){
            if( i == k){
                dfs(sus,adj,i,k,vis);
            }
        }

        vector<int>ans;
        vector<int>ans1;
        for(int i=0;i<n;i++) ans1.push_back(i);

        for(int i=0;i<n;i++){
            if( sus[i] == 0){
                for(auto u : adj[i]){
                    if(sus[u] == 1)
                        return ans1;
                }
                ans.push_back(i);
            }

        }
        return ans;
    }
};