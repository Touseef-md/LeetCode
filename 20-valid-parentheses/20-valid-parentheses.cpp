class Solution {
public:
    char complement(char c){
        if(c==')')
            return '(';
        if(c=='}')
            return '{';
        if(c==']')
            return '[';
        return '.';
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                char comp=complement(s[i]);
                if(st.top()!=comp)
                    return false;
                else{
                    st.pop();
                }
            }
        }
        if(st.size()>0)
            return false;
        return true;
    }
};