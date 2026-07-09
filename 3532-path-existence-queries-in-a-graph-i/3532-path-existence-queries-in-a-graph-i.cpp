class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<vector<int>>q;
        for(int i=0;i<n;i++){
            if(  i == n-1 ){
                q.push_back({i,i});
                continue;
            }
            int k = i;
            int j = i+1;
            while(j<n && ((nums[j] - nums[k]) <= maxDiff)){
                j++;
                k++;
            }
            vector<int>temp = {i,k};
            q.push_back(temp);
            i = j-1;
        }


        vector<vector<int>>range(n,vector<int>(2,-1));
        int i=0;
        for(int k=0; k < n ;k++){ 
            int start = q[i][0];
            int end = q[i][1];
            if( k < start)
                range[k] = { k , k};
            else if( k <= end )
                range[k] = { start , end};
            else{
                range[k] = {k,k};
                i++;
            }
        }

        for(auto x : queries){
            int curS = x[0] >= x[1] ? x[1] : x[0];
            int curE = x[0] >= x[1] ? x[0] : x[1];
            int s = range[curE][0];
            int e = range[curE][1];
            if( curS >= s && curE <= e)
                ans.push_back(true);
            else 
                ans.push_back(false);
        }
        return ans;
    }
};