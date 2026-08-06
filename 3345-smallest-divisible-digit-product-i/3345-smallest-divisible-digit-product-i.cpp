class Solution {
public:
    int check(int n){
        int mul = 1;
        while( n > 0){
            int d = n%10;
            mul *= d;
            n /= 10;
        }
        return mul;
    }
    int smallestNumber(int n, int t) {
        int l = n;
        int r = n + t;
        for(int i=l ; i<=r; i++){
            if( check(i) % t == 0)
                return i;
        }

        return -1;
    }
};