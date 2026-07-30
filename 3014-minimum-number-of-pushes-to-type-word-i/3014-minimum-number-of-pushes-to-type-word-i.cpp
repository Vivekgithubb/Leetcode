class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_set<char>st;
        for(auto s : word)
            st.insert(s);
        int req = st.size();
        if(req <= 8 ) return req;
        int press = req / 8;
        int spare = req % 8;
        if( press == 3)
            return (6 *8) + (spare * (press + 1 ));
        if( press == 2)
            return (3 * 8) + (spare * (press + 1 ));
        return (8) + (spare * (press + 1 ));
    }
};