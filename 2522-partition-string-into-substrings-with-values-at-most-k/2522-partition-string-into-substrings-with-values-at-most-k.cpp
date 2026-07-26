class Solution {
public:
    int minimumPartition(string s, int k) {
        int count = 0;
        bool pos = true;
        string temp = "";
        int i=0;
        while(i < s.length()){
            if( s[i] -'0' > k){
                return -1;
            }
            temp += s[i];
            long long check = stoll(temp);
            if(check > 1LL*k){
                temp = "";
                count++;
            }
            else{
                i++;
            }
        }
        return count+1;
    }
};