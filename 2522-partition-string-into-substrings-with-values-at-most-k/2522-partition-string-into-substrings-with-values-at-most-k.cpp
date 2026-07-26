class Solution {
public:
    int minimumPartition(string s, int k) {
        int count = 0;
        bool pos = true;
        string temp = "";
        int i=0;
        long long current = 0;
        for(int i=0 ; i<s.length() ; i++){
            if( s[i] -'0' > k){
                return -1;
            }
            else{
                current = current * 10 + (s[i]-'0');
                if(current > 1LL*k){
                    current = s[i]-'0';
                    count++;
                }
                else{
                    continue;
                }
            }
        }
        return count+1;
    }
};