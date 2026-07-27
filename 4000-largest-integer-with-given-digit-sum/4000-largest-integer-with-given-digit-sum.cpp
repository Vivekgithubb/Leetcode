class Solution {
public:
    // int solve(int cur , int n , int s){
    //     int len =  to_string(cur).length();
    //     if( len >= n){
    //         if( cur == s) return cur;
    //         return -1;
    //     }
    //     int val = -1;
    //     for(int i=0;i<=9;i++){
    //         cur = cur * 10 +  i;
    //         val = max(val,solve(cur,n,s));
    //         cur = (cur - i) / 10;
    //     }
    //     return val;
    // }
    int largestInteger(int n, int s) {
        string num = "";
        int maxV = -1;
        int val = 0;
        if( ceil((double)s/n) > 9.0) return -1;
        if(s == 0 ) return 0;
        string p = "";
        for(int i=1;i<=n;i++){  
            for(int j=9 ; j>=0;j--){
                val = val+j;
                p += (j+'0');

                if(val <= s) break; 

                p.pop_back();
                val = (val-j );
            }
            if(val == s)
                maxV = max(maxV , stoi(p));
        }

        return maxV;
    }
};