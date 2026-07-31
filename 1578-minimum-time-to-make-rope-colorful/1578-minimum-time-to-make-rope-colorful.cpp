class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char,int>>st;
        int count = 0;
        for(int i=0;i<colors.size(); i++){
            bool check = false;
            while(!st.empty() && st.top().first == colors[i] && !check){
                int val1 = neededTime[st.top().second];
                int val2 = neededTime[i];
                if(val1 < val2){
                    count += val1;
                    st.pop();
                }else{
                    count += val2;
                    check = true;
                }
            }
            if(st.empty() || st.top().first != colors[i])
                st.push({colors[i],i});
        }

        return count;
    }
};