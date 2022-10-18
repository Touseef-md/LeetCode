class Solution {
public:
    // int minDiff=300001;
    vector<vector<int>> dp;
    int min_Difficulty(vector<int>& jobDifficulty,int d,int i){
        if(i==-1&&d==0)
            return 0;
        if(i<d-1||d<1){
            return -1;
        }
        if(dp[d][i]!=-1)
            return dp[d][i];
        if(i==d-1){
            int sumi=0;
            for(int k=0;k<=i;k++)
                sumi+=jobDifficulty[k];
            return dp[d][i]=sumi;
        }
        int maxi=jobDifficulty[i],maxijob=300001,flag=0;
        for(int k=i;k>=0;k--){
            maxi=max(maxi,jobDifficulty[k]);
            int ans=min_Difficulty(jobDifficulty,d-1,k-1);
            if(ans==-1){
                continue;
            }
            else{
                flag=1;
                maxijob=min(maxijob,maxi+ans);
                // minDiff=min(minDiff,maxi+ans);
            }
        }
        if(flag==0)
            return dp[d][i]=-1;
        return dp[d][i]=maxijob;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        dp.clear();
        int n=jobDifficulty.size();
        dp.resize(d+1,vector<int> (n+1,-1));
        int x=min_Difficulty(jobDifficulty,d,jobDifficulty.size()-1);
        // if(x<0)
        //     return -1;
        // cout<<x<<"This is x"<<endl;
        return x;
        // return minDiff;
    }
};