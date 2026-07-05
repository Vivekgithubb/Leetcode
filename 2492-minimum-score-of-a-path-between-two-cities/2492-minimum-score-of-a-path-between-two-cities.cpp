class DisjointSet{
    public:
    vector<long long>parent , size,cost;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        cost.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = 1LL*i;
            size[i] = 1LL*1;
            cost[i] = LLONG_MAX;
        }
    }
    int findparent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findparent(parent[node]);
    }
    long long costing(long long node){;
        return cost[findparent(node)];
    }
    void unionBySize(long long u , long long v, long long c){
        long long par_u= findparent(u);
        long long par_v= findparent(v);

        if(par_v == par_u){
            cost[par_v] = min(cost[par_u],c);
            return;
        }
        
        if(size[par_u] < size[par_v] ){
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
            cost[par_v] = min({cost[par_u] , c , cost[par_v ]});
        }
        else{
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
            cost[par_u] = min({cost[par_v] , c, cost[par_u]});
        }
    }
};
class Solution {
public:

    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int cost = roads[i][2];
            ds.unionBySize(u,v,cost);
        }

        int ans = 0;

        //since its a single componenet , any node containing 1 is automatically revisted and solved of during making union set , so just getting the cost og root is enough
        ans = (int)ds.costing(1);
        return ans;
    }
};