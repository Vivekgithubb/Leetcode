class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        auto n = s1.size();
        auto m = s2.size();
        int i= 0;
        int j= 0;
        vector<vector<int>>v;
        while( i < n && j < m){
            if( s1[i][0] < s2[j][0]){
                v.push_back({s1[i][0],s1[i][1]+s2[j][1]});
                i++;
            }
            else if (s1[i][0] == s2[j][0] ){
                v.push_back({s1[i][0],s1[i][1]+s2[j][1]});
                i++;
                j++;
            }
            else{
                v.push_back({s2[j][0],s2[j][1]+s1[i][1]});
                j++;
            }
        }
        while( i < n){
            v.push_back(s1[i]);
            i++;
        }
        while( j < m){
            v.push_back(s2[j]);
            j++;
        }
        return v;
    }
};