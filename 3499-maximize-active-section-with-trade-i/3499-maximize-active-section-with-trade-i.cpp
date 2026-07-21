class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int>v;
        int n = s.length();
        for(int i=0;i<n;){
            int count = 0;
            if( s[i] == '0'){
                while( i<n && s[i] == '0'){
                    count--;
                    i++;
                }
                v.push_back(count);
            }else{
                while( i<n && s[i] == '1'){
                    count++;
                    i++;
                }
                v.push_back(count);
            }

        }

        int oneC = 0;
        int ans = 0;

        int m = v.size();
        for(int i=0;i<m;i++){
            if(v[i] > 0)
                oneC += v[i];
        }
        ans = oneC;
        for(int i=0;i<m;i++){
            int curAns = 0;
            if(i == 0 || i==m-1 ) continue;
            if ( v[i] > 0 && v[i-1] < 0 && v[i+1] < 0){
                curAns = abs(v[i-1] + v[i+1]) + oneC;
                ans = max(ans , curAns);
            }
        }

        return ans;
    }
};