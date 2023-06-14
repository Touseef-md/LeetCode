class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string tempAns=countAndSay(n-1);
        int count=1,i=0,m=tempAns.size();
        string ans="";
        while(i<m-1){
            if(tempAns[i]==tempAns[i+1]){
                count++;
            }
            else{
                ans+=to_string(count);
                ans+=tempAns[i];
                count=1;
            }
            i++;
        }
        ans+=to_string(count);
        ans+=tempAns[i];
      return ans;
    }
};