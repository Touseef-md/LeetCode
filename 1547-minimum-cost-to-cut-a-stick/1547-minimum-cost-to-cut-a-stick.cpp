// unordered_map<int,int> mp;
vector<vector<int>> dp;
// unordered_map<string,int> dp;
class Solution {
public:
//     int cost(int n,vector<int>& cuts,int i,int j){
//         if(i==j)
//             return 0;
//         int k,l,temp_ans1,temp_ans2;
//         k=i+(j-i)/2;
//         l=k;
//         if((j-i)%2!=0)
//             l=k+1;
//         // if((j-i)%2==0){
//             while(k>i&&l<j){
//                 auto it1=mp.find(k);
//                 auto it2=mp.find(l);  
//                 if(it1!=mp.end()){
//                     return j-i+cost(n,cuts,i,k)+cost(n,cuts,k,j);
//                 //     break;
//                 }
//                 if(it2!=mp.end()){
//                     return j-i+cost(n,cuts,i,l)+cost(n,cuts,l,j);
//                 }
//                 k--;
//                 l++;
//             }
//             while(k>i){
//                 auto it1=mp.find(k);

//                 if(it1!=mp.end()){
//                     return j-i+cost(n,cuts,i,k)+cost(n,cuts,k,j);
//                 //     break;
//                 }   
//                 k--;
//             }
//             while(l<j){
//                 auto it2=mp.find(l);  
//                 if(it2!=mp.end()){
//                     return j-i+cost(n,cuts,i,l)+cost(n,cuts,l,j);
//                 }
//                 l++;
//             }
// //         }
// //         else{
            
// //         }
//         return 0;
//     }
    
    int cost(int n,vector<int>& cuts,int i,int j){
        // cout<<i<<"  "<<j<<endl;
        // if(cut>=cuts.size()){
        //     return 0;
        // }
        // string x=to_string(i)+" "+to_string(j);
        // auto it=dp.find(x);
        // if(it!=dp.end())
            // return dp[x];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int temp=INT_MAX;
        for(int k=i+1;k<j;k++){
            // if(cuts[k]>i&&cuts[k]<j){
                // cuts[cut]=-1;
                // temp= j-i+cost(n,cuts,i,cuts[cut],cut+1)+cost(n,cuts,cuts[cut],j,cut+);
                temp=min(temp,cuts[j]-cuts[i]+cost(n,cuts,i,k)+cost(n,cuts,k,j));
            // }
        }
        if(temp==INT_MAX)
            return dp[i][j]=0;
        return dp[i][j]=temp;
        // return min(temp,cost(n,cuts,i,j,cut+1));
        
    }
    int minCost(int n, vector<int>& cuts) {
        // mp.clear();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        dp.clear();
        int m=cuts.size();
        dp.resize(m+1,vector<int>(m+1,-1));
        // for(auto i:cuts){
        //     // mp[i]++;
        // }
        return cost(n,cuts,0,m-1);
    }
};