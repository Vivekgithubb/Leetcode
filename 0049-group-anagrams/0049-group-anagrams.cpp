class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto s : strs){
            string org = s ;
            sort(s.begin(),s.end());
            mp[s].push_back(org);
        }

        vector<vector<string>>ans;
        for(auto &[s,v] : mp)
            ans.push_back(v);

        return ans;
    }
};