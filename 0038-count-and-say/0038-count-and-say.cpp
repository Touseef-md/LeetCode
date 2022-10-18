class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string st=countAndSay(n-1),result;
        int count=1,i=0;
        for(i=0;i<st.length()-1;i++){
            if(st[i]==st[i+1]){
                count++;
            }
            else{
                result+=to_string(count)+st[i];
                count=1;
            }
        }
        result+=to_string(count)+st[i];
        return result;
    }
};