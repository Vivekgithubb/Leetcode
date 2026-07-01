class Solution {
public:
    // bool parser(vector<char>v, char op){
    //     char val;
    //     bool ans;
    //     if(v.size() == 1){
    //         bool curOp = v[0] =='f' ? 0 : 1;

    //         if(op =='&' || op =='|') return curOp;
    //         if(op =='!') return !curOp;
    //     }
    //     if(op == '&'){
    //         ans = v[0] == 'f' ? 0 : 1;
    //         for(int i=1;i<v.size();i++){
    //             bool curVal = v[i] == 'f' ? 0 : 1;
    //             ans &= curVal;
    //         }
    //     }
    //     else if(op == '|'){
    //         ans = v[0] == 'f' ? 0 : 1;
    //         for(int i=1;i<v.size();i++){
    //             bool curVal = v[i] == 'f' ? 0 : 1;
    //             ans |= curVal;
    //         }
    //     }
    //     else if(op == '!'){
    //         bool curVal = v[0] == 'f' ? 0 : 1;
    //         return  !curVal;
    //     }

    //     return ans;
    // }
    bool parseBoolExpr(string s) {
        int n = s.size();
        if(n == 1) return s[0] == 'f' ? 0 : 1;
        stack<char>st;
        bool ans;
        for(int i=0;i<n;i++){
            if(s[i] == ',' || s[i] == '(') 
                continue;

            if(s[i] != ')'){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                // vector<char>v;
                bool hasFalse = false;
                bool hasTrue = false;

                while(st.top() != '!' && st.top() !='|' && st.top() != '&'){
                    char curVal = st.top();
                    if(curVal == 'f') hasFalse = true;
                    if(curVal == 't') hasTrue = true;
                    st.pop();
                }
                char curOp = st.top();
                st.pop();
                if(curOp == '!')
                    st.push(hasTrue ? 'f' : 't');
                else if( curOp == '&')
                    st.push(hasFalse ? 'f' : 't');
                else
                    st.push(hasTrue ? 't' : 'f');

                // ans = parser(v,curOp);
                // if(ans == false)
                //     st.push('f');
                // else
                //     st.push('t');
            }
        }
        return st.top() == 't';
    }
};