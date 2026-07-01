class Solution {
public:
    bool parser(vector<char>v, char op){
        char val;
        bool ans;
        if(v.size() == 1){
            bool curOp = v[0] =='f' ? 0 : 1;

            if(op =='&' || op =='|') return curOp;
            if(op =='!') return !curOp;
        }
        if(op == '&'){
            ans = v[0] == 'f' ? 0 : 1;
            for(int i=1;i<v.size();i++){
                bool curVal = v[i] == 'f' ? 0 : 1;
                ans &= curVal;
            }
        }
        else if(op == '|'){
            ans = v[0] == 'f' ? 0 : 1;
            for(int i=1;i<v.size();i++){
                bool curVal = v[i] == 'f' ? 0 : 1;
                ans |= curVal;
            }
        }
        else if(op == '!'){
            bool curVal = v[0] == 'f' ? 0 : 1;
            return  !curVal;
        }

        return ans;
    }
    bool parseBoolExpr(string s) {
        int n = s.size();
        if(n == 1) return s[0] == 'f' ? 0 : 1;
        stack<char>st;
        bool ans;
        for(int i=0;i<n;i++){
            if(s[i] == ',' || s[i] == ' ') continue;

            if(st.empty() || s[i] != ')'){
                st.push(s[i]);
                continue;
            }

            if(s[i] == ')'){
                vector<char>v;
                while(st.top() != '('){
                    v.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char curOp = st.top();
                st.pop();
                ans = parser(v,curOp);
                if(ans == false)
                    st.push('f');
                else
                    st.push('t');
            }
        }
        return ans;
    }
};