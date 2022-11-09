class Solution {
public:
    int maximum69Number (int num) {
        string st=to_string(num);
        int flag=0;
        // int number=1;
        string answer="";
        for(int i=0;i<st.length();i++){
            if(st[i]=='6'&&flag==0){
                answer+='9';
                flag=1;
            }
            else
                answer+=st[i];
        }
        int number=stoi(answer);
        return number;
        
    }
};