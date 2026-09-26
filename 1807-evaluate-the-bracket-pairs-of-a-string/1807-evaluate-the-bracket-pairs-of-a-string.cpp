class Solution {
public:
    string evaluate(string s, vector<vector<string>>& know) {
        int i=0;
        int j=0;
        int n = s.length();
        string ans = "";
        unordered_map<string,string>k;
        for(auto i : know){
            k[i[0]] = i[1]; 
        }
        while( i < n){
            if( s[i] == '('){
                string temp ="";
                i++;
                while( i <  n &&  s[i] != ')'){
                    temp += s[i];
                    i++;
                }
                if(k.find(temp) != k.end())
                    ans += k[temp];
                else 
                    ans += '?';
            }
            else{
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};