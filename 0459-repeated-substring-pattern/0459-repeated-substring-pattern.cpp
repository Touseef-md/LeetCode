class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size(),count=0,flag=0,j=0,k;
        if(n==1){
            return false;
        }
        // cout<<floor(sqrt(n))<<endl;
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                // cout<<i<<endl;
                // flag=0;
                j=0;
                k=j+i;
                while(k<n){
                    flag=0;
                    // count=0;
                    // k=j+i;
                    if(s[j]==s[k]){
                        j++;
                        k++;
                    }
                    else{
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    return true;
                }
            }
        }
        return false;
    }
};