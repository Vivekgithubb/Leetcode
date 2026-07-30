class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        sort(token.begin(),token.end());
        int i=0;
        int j = token.size()-1;
        int score = 0;
        int ans = 0;
        while(i <= j){
            if( power < token[i] ){
                i++;
                continue;
            }
            while(i <= j && power >= token[i]){
                score += 1; 
                power -= token[i];
                cout<<power<<endl;
                i++;
            }

            ans = max(ans,score);

            if( i <= j && score > 0 ) {
                score -= 1;
                power += token[j];
                j--;
            }
        }

        return ans;
    }
};