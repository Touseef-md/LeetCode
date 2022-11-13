class Solution {
public:
    string reverseWords(string s) {
        s+=' ';
        string temp="";
        vector<string> st;
        for(int i=0;i<s.length();i++){
            while(i+1<s.length()&&s[i]==' '&&s[i+1]==' '){
                i++;
            }
            if(s[i]==' '){
                if(temp!="")
                st.push_back(temp);
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        reverse(st.begin(),st.end());
        temp="";
        for(int i=0;i<st.size();i++){
            temp+=st[i];
            if(i!=st.size()-1)
            temp+=' ';
        }
        return temp;
    }
};