class Solution {
public:
    void merge(vector<vector<int>>&ans, vector<vector<int>>& oi , int fs, int fe){
        sort(oi.begin(),oi.end());
        int n = oi.size();
        if(n == 1){
            ans = oi;
            return;
        } 

        for(int i=0;i<n;){
            vector<int> v; 
            int j=i+1;
            //overlap or touch then merge and push
            while( j < n){
                if(oi[j][0] <= oi[i][1]+1 ){
                    oi[i][0] = min(oi[i][0],oi[j][0]);
                    oi[i][1] = max(oi[i][1],oi[j][1]);
                    v = {oi[i][0],oi[i][1]};
                }
                else
                    break;
                j++;
            }

            //incase there is no overlap we cant pus empty v , thus this condition
            if(!v.empty())
                ans.push_back(v);
            else 
                ans.push_back(oi[i]);

            //to skip already checked indexes and prevent duplicates
            i=j;
        }
    }

    //testcase to handle
    // ans = {{1,10}}
    // fs = 4
    // fe = 6 
    //ans = {1,3} , {7,10}
    void filter(vector<vector<int>>&ans, int fs, int fe){
        vector<vector<int>>total;
        int n = ans.size();
        for(int i=0;i<n;i++){
            int end = ans[i][1];
            int start = ans[i][0];

            //no overlap
            if( fe < start || fs > end){
                total.push_back(ans[i]);
            }
            else{
                //left part
                if(fs - 1 >= start ){
                    total.push_back({start,fs-1});
                }
                //right part 
                if( fe + 1 <= end){
                    total.push_back({fe+1,end});
                }    
            }
        }
        ans = total;
    }

    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>>ans;
        if(occupiedIntervals.size() < 1) return {};

        merge(ans,occupiedIntervals,freeStart,freeEnd);
        filter(ans,freeStart,freeEnd);

        return ans;
    }
};