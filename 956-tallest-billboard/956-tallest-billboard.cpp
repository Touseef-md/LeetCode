class Solution {
public:
    int maxHeight=0;
    vector<vector<long long int>> dp;
    int billBoard(vector<int>& rods,int i,int diff,int height){
        // cout<<i<<endl;
        if(i==rods.size()){
            if(diff==0){
                return 0;
            }
            return -2;
        }
        if(dp[i][diff+5000]!=-1)
            return dp[i][diff+5000];
        // cout<<"Just before one"<<endl;
        // cout<<"Just before"<<endl;
        // cout<<diff+rods[i]<<endl;
        // cout<<"fsdf"<<endl;
        int a=billBoard(rods,i+1,diff+rods[i],height+rods[i]);
        if(a!=-2){
            a+=rods[i];
        }
        else{
            // a=0;
        }
        // cout<<"Check one "<<endl;
        int b=billBoard(rods,i+1,diff-rods[i],height+rods[i]);
            if(b!=-2){
                b+=rods[i];
        }
        else{
            // b=0;
        }
        // cout<<"CHEck tewo"<<endl;    
        int c=billBoard(rods,i+1,diff,height);
        if(c!=-2){
            // a+=rods[i];
        }
        else{
            // c=0;
        }
        // cout<<"chcek three"<<endl;
        // cout<<"hjgfdsfsd"<<endl;
        dp[i][diff+5000]=max(max(a,b),c);
        // if(dp[i][diff+5000]==0)
        // dp[i][diff]=max({a,b,c});
        // dp[i][diff]=max({billBoard(rods,i+1,diff+rods[i],height+rods[i]),billBoard(rods,i+1,diff-rods[i],height+rods[i]),billBoard(rods,i+1,diff,height)});
    // cout<<i<<"  "<<dp[i][diff]<<endl;
        
        return dp[i][diff+5000];
    }
    //bruteforce
//     int billBoard(vector<int>& rods,int i,int ha,int hb){
//         // if(ha==hb){
//         //     maxHeight=max(maxHeight,ha);
//         //     // return maxHeight;
//         // }
//         if(i==rods.size()){
            
//             if(ha==hb){
//                 return ha;
//             }
//             // maxHeight=
//             return 0;
//         }
//             return max({billBoard(rods,i+1,ha+rods[i],hb),billBoard(rods,i+1,ha,hb+rods[i]),billBoard(rods,i+1,ha,hb)});
//         // else if(ha>hb){
//         //     return max({billBoard(rods,i+1,ha,hb+rods[i]),billBoard(rods,i+1,ha,hb)});
//         // }
//         // else{
//         //     return max({billBoard(rods,i+1,ha+rods[i],hb),billBoard(rods,i+1,ha,hb)});
//         // }
//     }
    
    int tallestBillboard(vector<int>& rods) {
        dp.clear();
        dp.resize(rods.size()+1,vector<long long int>(10000,-1));
        // maxHeight=0;
        int x=billBoard(rods,0,0,0);
        if(x==-2){
            return 0;
        }
        // if(x==0){
            // maxHeight=max(maxHeight,x);
        // }
        // cout<<"X is "<<x<<endl;
        return x/2;
    }
};