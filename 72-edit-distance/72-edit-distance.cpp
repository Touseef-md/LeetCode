#define lli long long int
class Solution {
public:
    vector<vector<lli>> dp;
    int dist(string& word1,string& word2,int i,int j){
        if(i==0&&j==0)
            return 0;
        if(i==0||j==0){
            return abs(i-j);
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        lli result=INT_MAX;
        if(word1[i-1]==word2[j-1]){
            result=dist(word1,word2,i-1,j-1);
        }
        else{
            result=1+min({dist(word1,word2,i,j-1),dist(word1,word2,i-1,j-1),dist(word1,word2,i-1,j)});
        }
        if(result==INT_MAX){
        cout<<"SOMETHING WENT WROGN"<<endl;
        }
        return dp[i][j]=result;
    }
    int minDistance(string word1, string word2) {
        // dp.clear();
        dp.resize(word1.size()+1,vector<lli>(word2.size()+1,-1));
        return dist(word1,word2,word1.size(),word2.size());
    }
};