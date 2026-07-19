class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        vector<int>vis(256,0),lastIndex(256,0);
        for(int i=0;i< s.length();i++){
            lastIndex[s[i]] = i;
        }

        string ans = "";
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(vis[c]) continue;

            while(!ans.empty() && ans.back() > c && lastIndex[ans.back()] > i){
                vis[ans.back()] = 0;
                ans.pop_back();
                cout<<ans<<"\n";
            }
            
            ans += c;
            vis[c] = 1;
        }
        return ans;
    }
};