class Solution {
public:
    bool solve(int r,int c , int n , int m, int k, vector<string>& grid,vector<vector<int>>& dp){
        if(r == n){
            return dp[n-1][m-1] == k;
        }

        int nr = r;
        int nc = c+1; 
        if(nc == m){
            nr = r+1;
            nc=0;
        }   

        grid[r][c] = '.';

        if(r==0 && c==0)
            dp[0][0] = 1;
        else{
            dp[r][c] = (r > 0 ? dp[r-1][c] : 0) + (c > 0 ? dp[r][c-1] : 0);
        }    

        //proceed if ways to erach currrent cell less than k
        if(dp[r][c] <= k){
            if(solve(nr,nc,n,m,k,grid,dp)) 
                return true;
        }

        //if already k ways to reach then block the area off 
        if((r != 0 || c!=0) &&( r!=n-1 ||c !=m-1)){
            grid[r][c]= '#';
            dp[r][c] = 0;
            //try solving from next cells 
            if(solve(nr,nc,n,m,k,grid,dp)) 
                return true;
        }
        return false;
    }
    vector<string> createGrid(int m, int n, int k) {
        vector<string>grid(m,string(n,'.'));
        vector<vector<int>>dp(m,vector<int>(n,0));
        if(solve(0,0,m,n,k,grid,dp))
            return grid;
        return {};
    }
};