class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end(), [](vector<int> a , vector<int> b){
            if( a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int k = 0;
        int count = inter.size();
        for(int i=1; i<inter.size();i++){
            if( inter[k][1] >= inter[i][1])
                count--;
            else 
                k = i;
        }

        return count;
    }
};