class Solution {
public:
    int maxi=0;
    void handleRequests(vector<vector<int>>& requests,vector<int>& degrees,int &n,int i,int count){
        if(i==requests.size()){
            return;
        }
        // handleRequests(requests,degrees,n,i+1,count);
        int from=requests[i][0];
        int to=requests[i][1];
        degrees[from]--;
        degrees[to]++;
        int flag=0;
        for(int j=0;j<degrees.size();j++){
            if(degrees[j]!=0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            maxi=max(maxi,count+1);
        }
        handleRequests(requests,degrees,n,i+1,count+1);
        degrees[from]++;
        degrees[to]--;
        handleRequests(requests,degrees,n,i+1,count);
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        maxi=0;
        vector<int> degrees(n,0);
        handleRequests(requests,degrees,n,0,0);
        return maxi;
        // unordered_map<int,string> dp;
        // bitset<16> bit(0);
//         int m=requests.size(),flag=0,temp;
//         // vector<vector<int>> dp(1<<m,vector<int>(n,-1));
//         // string st="";
//         // vector<int> st;
//         // for(int i=0;i<n;i++){
//         //     // st+='0';
//         //     st.push_back(0);
//         // }
//         // dp[0]=st;
        
//         // dp[0]
//         int maxi=0,edgeCount=0;
//         for(int edges=1;edges<(1<<m);edges++){
            
//             for(int edge=0;edge<m;edge++){
//                 temp=edges&(1<<edge);
//                 if(temp!=edges){
//                     st=dp[temp];
//                     int from=requests[edge][0];
//                     int to=requests[edge][1];
//                     st[from]--;
//                     st[to]++;
//                     edgeCount=0;
//                     for(int i=0;i<n;i++){
//                         if(st[i]!=0){
//                             flag=1;
//                             break;
//                         }
//                         // if(edge[i])
//                     }
//                     if(flag==0){
//                         maxi=max(maxi,)
//                     }
//                     // int degree=st[requests[edge][0]]-48;
//                     // st[requests[edge][0]]
//                     requests[edge]
//                 }
//             }
//             // cout<<edge<<endl;
//         }
//         // cout<<bit[1]<<endl;
//         return 5;
    }
};