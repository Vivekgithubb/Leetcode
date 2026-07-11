class Solution {
public:
    bool solve(string& s , string& t, int i, int j , int cnt){
        int n = s.length();
        int m = t.length();

        if( i >= n || j >= m){
            //if t ended but s is still left
            if( j == m && i < n)
                return false;

            return true;
        }

        //if another miscplace after alredady 1 replacement is done , cnt = 1
        if( s[i] != t[j] && cnt == 1)
            return false;
        
        bool temp;
        //when match amd when dont match but cnt = 0, ie not replaced already 
        if( s[i] == t[j]){
            temp = solve(s,t,i+1,j+1,cnt);
        }
        else{
            // either replace || not replace and check next
            temp = solve(s,t,i+1,j+1,1) || solve(s,t,i,j+1,cnt);
        }
        return temp;
    }
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if( n > m) return false;
        if(n == m){
            int count =0;
            for(int i=0;i<n;i++){
                if( s[i] != t[i])
                    count++;
                if(count > 1 ) return false;
            }
        }
        return solve(s,t,0,0,0);
    }
};