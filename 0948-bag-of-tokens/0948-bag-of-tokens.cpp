class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        sort(token.begin(),token.end());
        int i=0;
        int j = token.size()-1;
        int score = 0;
        int ans = 0;
        while(i <= j){
            if( power >= token[i]){
                score += 1; 
                power -= token[i];
                ans = max(ans,score);
                i++;
            }else if( score > 0 ) {
                score -= 1;
                power += token[j];
                j--;
            }else{ 
                break;
            }
        }

        return ans;
    }
};