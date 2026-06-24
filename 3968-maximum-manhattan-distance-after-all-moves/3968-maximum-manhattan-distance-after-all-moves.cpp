class Solution {
public:
    int maxDistance(string moves) {
       int uc=0;
       int negc=0;
       int plusc=0;
       pair<int,int> point = {0,0};

       for(auto m : moves){
            if( m == 'L'){
                negc+=1;
                point.first -= 1;
            }
            else if( m=='D'){
                negc+=1;
                point.second -= 1;
            }
            else if( m=='R'){
                plusc+=1;
                point.first += 1;
            }
            else if( m=='U'){
                plusc+=1;
                point.second += 1;
            }
            else 
                uc+=1;
        } 

        int curSum = point.first + point.second;
        if(curSum >= 0){
            if(point.first >=0 ) 
                point.first += uc;
            else 
                point.second+=uc;
        }
        else {
            if(point.first >=0 ) 
                point.second -= uc;
            else 
                point.first -= uc;
        }
        int ans = abs(0-point.first) + abs(0-point.second);

        return ans;
    }
};