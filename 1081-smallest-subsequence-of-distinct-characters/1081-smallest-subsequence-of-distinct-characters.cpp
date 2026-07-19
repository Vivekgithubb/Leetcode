class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        vector<int>vis(26,0),lastIndex(26,0);
        for(int i=0;i< s.length();i++){
            lastIndex[s[i]-'a'] = i;
        }

        string ans = "";
        for(int i=0;i<s.length();i++){
            char c = s[i];
            int curInd = c-'a';
            if(vis[curInd]) continue;

            while(!ans.empty() && ans.back() > c && lastIndex[ans.back()-'a'] > i){
                vis[ans.back()-'a'] = 0;
                ans.pop_back();
                cout<<ans<<"\n";
            }
            
            ans += c;
            vis[curInd] = 1;
        }
        return ans;
    }
};