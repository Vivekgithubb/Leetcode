class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>>pq;
    
        pq.push({health,{0,0}});
        int dRow[4] = { -1 , 0 , 1 , 0};
        int dCol[4] = { 0 , 1 , 0 , -1};

        vector<vector<int>>vis(n,vector<int>(m,0));

        while(!pq.empty()){
            auto it = pq.top();
            int r = it.second.first;
            int c = it.second.second;
            int curHealth = it.first;
            pq.pop();

            //check if already visited , mark visited
            if(vis[r][c]) continue; 
            vis[r][c] = 1;

            if( grid[r][c] == 1) 
                curHealth -= 1;

            if(curHealth <= 0 ) continue;
            if( r == n-1 && c == m-1 ) return true;

            for(int i=0;i<4;i++){
                int curR = r + dRow[i];
                int curC = c + dCol[i];
                if( curR >= 0 && curR <n && curC >= 0 && curC < m && vis[curR][curC] == 0){
                    pq.push({curHealth,{curR , curC}});
                }
            }
        }
        return false;
    }
};