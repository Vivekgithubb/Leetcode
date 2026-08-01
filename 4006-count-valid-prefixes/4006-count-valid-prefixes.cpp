class Solution {
public:
    int countValidPrefixes(string s) {
        int zcount = 0;
        int ocount = 0;
        int ans= 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '1') ocount++;
            else zcount++;

            if(zcount == ocount || abs(zcount-ocount) == 1)
                ans++;
        }

        return ans;
    }
};