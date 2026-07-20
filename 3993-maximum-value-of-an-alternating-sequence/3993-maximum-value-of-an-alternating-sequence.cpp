class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if( n == 1) return s;

        long long increase = 1LL*(n/2) * m;
        long long decrease = n/2 - 1;

        return 1LL*(s + increase - decrease);

        // return 1LL*(s + ((1LL*n/2) * m) - 1LL*(n/2 - 1));
    }
};