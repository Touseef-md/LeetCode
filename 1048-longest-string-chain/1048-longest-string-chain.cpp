class Solution {
public:
    bool check(string& a,string & b){
        if(a.size()+1!=b.size()){
            return false;
        }
        int m=b.size();
            string st1;
        string st2;
        for(int i=0;i<m;i++){
            st1=b.substr(0,i);
            st2=b.substr(i+1,m-1-i);
            if(a==st1+st2){
                return true;
            }
        }
        return false;
        // unordered_map<int,int> freq1;
        // for(auto it:b){
        //     freq1[it]++;
        // }
        // for(auto it:a){
        //     freq1[it]--;
        // }
        // int count=0;
        // char ch;
        // for(auto it=freq1.begin();it!=freq1.end();it++){
        //     if(it->second<0){
        //         return false;
        //     }    
        //     if(it->second>0){
        //         ch=it->first;
        //         count+=it->second;
        //     }
        // }
        // if(count!=1){
        //     return false;
        // }
        // int i=0,j=0,m=a.size(),n=b.size();
        // while(i<m&&j<n){
        //     if()
        // }
        // return false;
    }
    static bool compp(string& a,string &b){
        if(b.size()<=a.size()){
            return false;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),compp);
        for(int i=0;i<n;i++){
            // if()
            for(int j=0;j<i;j++){
                if(check(words[j],words[i])){
                    // cout<<"THis is true"<<endl;
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};