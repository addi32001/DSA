class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        st.push('@');
        for(int i = 0;i<s.length();i++){
            if(s.empty())st.push(s[i]);
            else if(s[i]==')' && st.top()=='(')st.pop();
            else if(s[i]=='}' && st.top()=='{')st.pop();
            else if(s[i]==']' && st.top()=='[')st.pop();
            else st.push(s[i]);
        }
        return st.top()=='@';

    }
};