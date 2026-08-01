class Solution {
public:
    bool solve( long long ini ,vector<int>& monsters, vector<long long>& b ){
        int n = monsters.size();
        int m = b.size();
        for(int i=0;i<n;i++){
            if(monsters[i] <= (ini + b[i])){
                ini = max(1LL*0 , ini - 1LL*monsters[i] );
            }else{
                return false;
            }
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long>b(n,0);
        vector<long long>diff(n+1,0);
        //using difference array method
            //step 1:
            for(int i=0;i<boosts.size();i++){
                int s = boosts[i][0];
                int e = boosts[i][1];
                int v = boosts[i][2];

                diff[s] += v;
                if(e+1 < n){
                    diff[e+1] -= v;
                }
            }
            //step2: take prefix Sum
            b[0] = diff[0];
            for(int i=1;i<n;i++){
                b[i] = diff[i] + b[i-1];
            }

        long long totalMon = 0;
        for(auto m : monsters){
            totalMon += 1LL*m; 
        }
        long long low = 0;
        long long high = totalMon;
        long long ans = LLONG_MAX;
        while(low <= high){
            long long mid = low + (high - low)/2;
            bool check = solve(mid,monsters, b);
            if(check){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};