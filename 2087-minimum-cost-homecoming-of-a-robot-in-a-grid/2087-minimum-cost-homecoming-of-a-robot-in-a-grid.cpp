class Solution {
public:
    int minCost(vector<int>& sp, vector<int>& hp, vector<int>& rc, vector<int>& cc) {
        int n = rc.size();
        int m = cc.size();
        
        int x1 = sp[0];
        int y1 = sp[1];
        int x2 = hp[0];
        int y2 = hp[1];
        
        int sum1=0;

        if( x1 < x2) {
            for(int i=x1+1;i<=x2;i++)
                sum1 += rc[i];
        }
        else if(x1 > x2){
            for(int i=x1-1;i>=x2;i--){
                sum1 += rc[i];
            }
        }
        if(y1 < y2){
            for(int i=y1+1;i<=y2;i++)
                sum1 += cc[i];
        }else if(y1 > y2){
            for(int i=y1-1;i>=y2;i--){
                sum1 += cc[i];
            }
        }
        return sum1;
    }
};