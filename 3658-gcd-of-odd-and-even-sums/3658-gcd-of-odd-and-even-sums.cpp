class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // return n;
        return gcd( (1+n)*n , n*n);
    }
};