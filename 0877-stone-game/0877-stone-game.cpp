class Solution {
public:
    bool solve( int i , int j , int a , int b , vector<int>&piles,int turn){
        if( i > j){
            return a > b;
        }
        int nt = true;
        int t = true;
        if(turn){
            t = solve( i+1 , j , a + piles[i] , b , piles , false);
            nt = solve( i , j-1 , a + piles[j] , b , piles , false);
        }else{
            t = solve( i+1 , j , a , piles[i] + b , piles , true);
            nt = solve( i , j-1 , a , piles[j] + b , piles , true);
        }

        return t || nt ;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        return solve(0,0,0,0,piles,true);
    }
};