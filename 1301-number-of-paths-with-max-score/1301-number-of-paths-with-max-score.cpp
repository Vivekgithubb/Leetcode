class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n, {-1e9,0}));
        int mod = 1e9+7;
        dp[0][0] = {0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;

                if(board[i][j] == 'X'){
                    dp[i][j]= {-1e9,0};
                    continue;
                }
                
                if(i==0){
                    if( board[i][j-1] == 'X') continue;
                    int sum = (dp[i][j-1].first + board[i][j] - '0');
                    int count = dp[i][j-1].second;
                    dp[i][j] = {sum,count};
                }
                else if ( j==0){
                    if( board[i-1][j] == 'X') continue;
                    int sum = (dp[i-1][j].first + board[i][j] - '0');
                    int count = dp[i-1][j].second;
                    dp[i][j] = {sum,count};
                }
                else{
                    int topSum = dp[i-1][j].first;
                    int topC = dp[i-1][j].second;

                    int topLeftSum = dp[i-1][j-1].first;
                    int topLeftC = dp[i-1][j-1].second;

                    int leftSum = dp[i][j-1].first;
                    int leftC = dp[i][j-1].second;

                    int curSum = 0;
                    if(board[i][j] == 'S' || board[i][j] == 'E')
                        curSum = 0;
                    else 
                        curSum =  board[i][j]-'0';

                    int sum = max({topSum , leftSum , topLeftSum});
                    int count = 0;

                    if(sum == -1e9) continue;

                    if( sum == topSum)
                        count += topC;
                    if ( sum == leftSum)
                        count += leftC;
                    if( sum == topLeftSum) 
                        count += topLeftC;
                    count = count %mod;

                    dp[i][j] = { sum + curSum , count};
                }
            }
        }
        vector<int>ans;
        if(dp[n-1][n-1].first < 0 ) return {0,0};
        ans.push_back(dp[n-1][n-1].first);
        ans.push_back(dp[n-1][n-1].second);
        return ans;
    }
};