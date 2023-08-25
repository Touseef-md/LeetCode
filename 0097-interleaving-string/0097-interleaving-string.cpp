class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string &s1,string& s2,string& s3,int i,int j,int k){
        if(k>=s3.size()){
            return true;
        }
        // if(i<0||j<0){
        //     return false;
        // }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool temp_result=false;
        if( s1[i]!=s3[k] && s2[j]!=s3[k]){
            return dp[i][j]=false;
        }
        if(s1[i]==s3[k]){
            temp_result|=solve(s1,s2,s3,i+1,j,k+1);
        }
        if(s2[j]==s3[k]){
            temp_result|=solve(s1,s2,s3,i,j+1,k+1);
        }
        return dp[i][j]=temp_result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size()){
            return false;
        }
        int m=s1.size();
        int n=s2.size();
        dp.clear();
        dp.resize(m+1,vector<int>(n+1,-1));
        return solve(s1,s2,s3,0,0,0);
    }
};