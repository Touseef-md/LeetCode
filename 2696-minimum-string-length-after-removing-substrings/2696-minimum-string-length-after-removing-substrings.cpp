class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i=0;i < s.length();i ++){
            if(s[i]=='B'){
                if(!st.empty() ){
                    if( st.top()=='A' ){
                        st.pop();
                        // i--;
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
            else if( s[i] == 'D'){
                if(!st.empty()){
                    if(st.top() =='C'){
                        st.pop();
                        // i--;
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size();
        
    }
};