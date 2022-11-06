class Solution {
public:
    string orderlyQueue(string s, int k) {
        string result=s,temp=s;
        if(k==1){
            for(int i=0;i<s.length();i++){
                temp=temp.substr(1,s.length()-1)+temp.substr(0,1);
                result=min(result,temp);
            }
        }
        else{
            sort(s.begin(),s.end());
            result=s;
        }
        return result;
    }
};