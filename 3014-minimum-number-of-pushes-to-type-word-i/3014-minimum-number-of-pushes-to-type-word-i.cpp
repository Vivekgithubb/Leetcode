class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n <= 8 ) return n;
        int press = n / 8;
        int spare = n % 8;
        if( press == 3) return (6*8) + (spare * (press + 1 ));
        if( press == 2) return (3*8) + (spare * (press + 1 ));
        return (8) + (spare * (press + 1 ));
    }
};