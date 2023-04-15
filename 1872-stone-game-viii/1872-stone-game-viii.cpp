class Solution {
public:
    vector<vector<int>> dp;
    int result=0;
    int stoneGame(vector<int>& prefix,int i,int turn){
        if(i==prefix.size()){
            // cout<<"ANswer is 0"<<endl;
            return 0;
            // if(turn==0)
                // result=max(result,result+)    
        }
        if(dp[i][turn]!=-1)
            return dp[i][turn];
        if(turn==0){
            int maxi=INT_MIN,ind=-1,prev_pref=prefix[i];
            for(int j=i;j<prefix.size();j++){
                // if(prefix[j]>=prev_pref){
                    // maxi=max(maxi,stoneGame(prefix,j+1,1));
                    if(stoneGame(prefix,j+1,1)+prefix[j]>=maxi){
                        maxi=stoneGame(prefix,j+1,1)+prefix[j];
                        ind=j;
                    }
                // }
            }
            if(ind==-1){
                cout<<"CALLed from 1"<<endl;
                return 0;
            }
            // cout<<i<<" "<<turn<<endl;
            // cout<<"ANSwer is "<<maxi+prefix[ind]<<endl;
            // return dp[i][turn]=maxi+prefix[ind];
            return dp[i][turn]=maxi;
        }
        else{
            int maxi=INT_MAX,ind=-1,prev_prefix=prefix[i];
            for(int j=i;j<prefix.size();j++){
                // if(prefix[j]<=prev_prefix){
                    // maxi=max(maxi,stoneGame(prefix,j+1,0));
                    if(stoneGame(prefix,j+1,0)-prefix[j]<=maxi){
                        maxi=stoneGame(prefix,j+1,0)-prefix[j];
                        ind=j;
                    }
                // }
            }
            if(ind==-1){
                cout<<"CALled from b"<<endl;
                return 0;
            }
            // cout<<i<<" "<<turn<<endl;
            // cout<<"Anserw is "<<maxi-prefix[ind]<<endl;
            // return dp[i][turn]=maxi-prefix[ind];
            return dp[i][turn]=maxi;
        }
        
    }
    vector<int> dp2;
    int help(int i,vector<int>& prefix){
        if(i==prefix.size()-1){
            return prefix[i];
        }
        if(dp2[i]!=-1)
            return dp2[i];
        int op1=prefix[i]-help(i+1,prefix);
        int op2=help(i+1,prefix);
        return dp2[i]=max(op1,op2);
    }
    int stoneGameVIII(vector<int>& stones) {
        result=0;
        dp.clear();
        dp2.clear();
        int n=stones.size(),sumi=0;
        dp2.resize(n+1,-1);
        dp.resize(n+1,vector<int>(2,-1));
        vector<int> prefix(n,0);
        for(int i=0;i<n;i++){
            sumi+=stones[i];
            prefix[i]=sumi;
        }
        // Below is the O(N^2) solution
        // return stoneGame(prefix,1,0);
        
        //------------------O(N) Solution---------------------
        return help(1,prefix);
        // return 0;
    }
};