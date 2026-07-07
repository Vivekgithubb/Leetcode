class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        int num =0;
        int x = n;
        string s = to_string(n);
        for(auto d : s){
            if(d-'0' != 0){
                sum += (d-'0');
                num = num*10 + (d-'0');
            }
        }
        return 1LL*sum*num;
    }
};