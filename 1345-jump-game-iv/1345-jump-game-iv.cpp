class Solution {
public:
    //----------Solution 1 using dp
    // vector<int> dp;
    unordered_map<int,vector<int>> mp;
    // int JGame(vector<int>& arr,int i,int & n){
    //     if(i==n){
    //         return 0;
    //     }
    //     int a=INT_MAX-1,b=INT_MAX-1,c=INT_MAX-1,m;
    //     dp[i]=-2;
    //     if(i+1<=n&&dp[i+1]!=-2){
    //         a=JGame(arr,i+1,n);
    //     }
    //     if(i-1>=1&&dp[i-1]!=-2){
    //         b=JGame(arr,i-1,n);
    //     }
    //     int p=mp[arr[i-1]].size();
    //     if(p>1){
    //         // vector<int> temp=mp[arr[i-1]];
    //         for(int j=0;j<p;j++){
    //             m=mp[arr[i-1]][j];
    //             if(dp[m]!=-2)
    //                 c=min(c,JGame(arr,m,n));
    //         }
    //     }
    //     dp[i]=min({a,b,c})+1;
    //     return dp[i];
    //     // return 0;
    // }
    int bfs(vector<int>& arr,int &n){
        queue<pair<int,int>> q;
        q.push({0,0});
        int x,step;
        vector<int> flag(n,-1);
        while(!q.empty()){
            x=q.front().first;
            step=q.front().second;
            // cout<<x<<"  steps "<<step<<endl;
            if(x==n-1){
                return step;
            }
            q.pop();
            // if(flag[x]!=-1)
            //     continue;
            // cout<<"AFter "<<x<<" steps "<<step<<endl;
            
            // if(flag[x]==-1)
            for(auto j:mp[arr[x]]){
                if(flag[j]==-1){
                    flag[j]=-2;
                    q.push({j,step+1});
                }
            }
            mp[arr[x]].clear();
            flag[x]=-2;
            if(x+1<n&&flag[x+1]==-1&&arr[x+1]!=arr[x]){
                flag[x+1]=-2;
                q.push({x+1,step+1});
            }
            if(x-1>=0&&flag[x-1]==-1&&arr[x-1]!=arr[x]){
                flag[x-1]=-2;
                q.push({x-1,step+1});
            }
        }
        return -1;
    }
    vector<vector<int>> adjlist;
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        // dp.resize(n+1,-1);
        mp.clear();
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        // return JGame(arr,1,n);
        // adjlist.clear();
        // adjlist.resize(n);
        // for(int i=0;i<arr.size();i++){
        //     if(i+1<n)
        //         adjlist[i].push_back(i+1);
        //     if(i-1>=0)
        //         adjlist[i].push_back(i-1);
        //     int p=mp[arr[i]].size();
        //     for(int j=0;j<p;j++){
        //         if(i!=mp[arr[i]][j])
        //             adjlist[i].push_back(mp[arr[i]][j]);
        //     }
        // }
        return bfs(arr,n);
        
    }
};