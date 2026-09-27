class Solution {
public:

    string reverseParentheses(string s) {
        string ans = "";
        int n = s.length();
        int i = 0;

        stack<char>st;

        while(i < n ){
            if(i < n && (isalpha(s[i]) || s[i] == '(') ) 
                st.push(s[i]);

            if(s[i]==')'){
                string temp = "";
                while( !st.empty() && st.top() != '('){
                    temp += st.top();
                    st.pop();
                }  
                st.pop();
                for(auto s : temp) st.push(s);
                cout<<temp<<endl;
            }
            i++; 
        }
        while(!st.empty()){
            if(st.top() != '(')
                ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};