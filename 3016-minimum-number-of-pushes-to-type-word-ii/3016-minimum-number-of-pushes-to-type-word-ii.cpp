class Solution {
public:
    int minimumPushes(string word) {
        vector<int>v(26,0);  
        for(auto c : word){
            v[c-'a']++;
        }
        sort(v.rbegin(),v.rend());
        int ans = 0;
        int count = 1;
        int n = v.size();
        for(int i=0;i<n;){
            int x = 2;
            while(i < n && x <= 9){
               ans += (v[i] * count);
               x += 1;
               i++;
            }
            count++;
        }
        return ans;
    }
};