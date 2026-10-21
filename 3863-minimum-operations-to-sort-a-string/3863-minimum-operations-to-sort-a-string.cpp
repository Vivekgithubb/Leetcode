class Solution {
public:
    bool isSorted(string s){
        for(int i=1;i<s.length();i++){
            if(s[i] < s[i-1]) return false;
        }
        return true;
    }
    int minOperations(string s) {
        if(isSorted(s)) return 0;
        int n = s.length();
        
        if( n <= 1) return 0;
        if( n == 2 ){
            if( s[0] < s[1]) return 1;
            else return -1;
        }
        char l = s[0];
        char r = s[n-1];
        int lcount =0;
        int rcount =0;

        for(int i=0;i<n;i++){
            l = max(l,s[i]);
            r = min(r,s[i]);
        }
        for(int i=0;i<n;i++){
            if(s[i] == l) lcount++;
            if(s[i] == r) rcount++;
        }


        if(s[0] == r || s[n-1] == l) return 1;
        if(s[0] == l && s[n-1] == r && lcount == 1 && rcount ==1) return 3; 
        return 2;
    }
};