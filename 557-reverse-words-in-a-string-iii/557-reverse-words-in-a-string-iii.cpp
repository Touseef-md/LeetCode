class Solution {
public:
    string reverseWords(string s) {
        s=s+' ';
        string st="",result="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                reverse(st.begin(),st.end());
                result+=st;
                if(i!=s.length()-1)
                result+=' ';
                st="";
            }
            else
                st+=s[i];
        }
        return result;
    }
};