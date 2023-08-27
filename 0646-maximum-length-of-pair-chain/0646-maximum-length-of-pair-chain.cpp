class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        if(b[1]<a[1]){
            return false;
        }
        else if(b[1]==a[1]){
            if(b[0]<a[0]){
                return false;
            }
            return true;
        }
        else
            return true;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int result=1,ans=0,n=pairs.size(),count=1,end;
        vector<int> dp(n+1,0);
        sort(pairs.begin(),pairs.end(),comp);
        dp[0]=1;
        for(int i=1;i<n;i++){
            ans=0;
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    // cout<<"This is it "<<i<<"  "<<j<<endl;
                    
                    ans=max(ans,dp[j]);
                }
            }
            dp[i]=max(dp[i],ans+1);
            result=max(result,dp[i]);
        }
        return result;
        
        
        
        // // if
        // if(n==1){
        //     return 1;
        // }
        // end=pairs[0][1];
        // for(int i=1;i<pairs.size();i++){
        //     if(pairs[i][0]<=end){
        //         // i++;
        //     }
        //     else{
        //         end=pairs[i][1];
        //         count++;
        //     }
        // }
        // return count;
    }
};