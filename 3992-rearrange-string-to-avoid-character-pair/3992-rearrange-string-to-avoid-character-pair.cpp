class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n = s.length();
        int lx = 0;
        int fy = 0;
        string t= "";
        for(int i=0;i<n;i++){
            if(s[i] == x)
                lx++;
            else if(s[i] == y)
                fy++;
            else
                t += s[i];
        }
        while( fy > 0){
            t += y;
            fy--;
        }
        while( lx > 0){
            t += x;
            lx--;
        }
        return t;
    }
};