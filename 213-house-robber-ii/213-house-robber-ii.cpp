class Solution {
public:
    // Wrong Logic
//     void houserobber(vector<int>& nums,vector<int>& dp,int i){
//         if(i>=nums.size())
//             return;
//         if(i==0||i==1||i==2){
//             dp[i]=nums[i];
//             // return;
//         }
//         else{
//             int x=dp[(i-1)%(i+1)],y=dp[(i+1)%(i+1)];
//             dp[(i-1)%(i+1)]=max(dp[(i-1)%(i+1)],nums[(i-1)%(i+1)]+dp[(i+1)%(i+1)]);
//             dp[(i+1)%(i+1)]=max(dp[(i+1)%(i+1)],nums[(i+1)%(i+1)]+x);
            
//             for(int j=(i+2)%(i+1);j!=(i-1)%(i+1);j++){
//                 dp[i]=max(dp[i],nums[i]+dp[j]);
//             }
//         }
//         // cout<<i<<" I "<<dp[i]<<endl;
//         houserobber(nums,dp,i+1);
//     }
    int rob_house(vector<int>& nums,int i,int j){
        int n=nums.size(),x,l=0;
        vector<int> dp(j-i+1,0);
        for(int k=i;k<=j;k++){
            x=0;
            for( l=i;l<k-1;l++){
                x=max(x,dp[l-i]);
            }
            dp[k-i]=nums[k]+x;
            // cout<<k<<" "<<l<<" DP "<<dp[k-i]<<"  "<<nums[i]<<endl;
        }
        return *max_element(dp.begin(),dp.end());
    }
    int rob(vector<int>& nums) {
        // cout<<"FIRST          "<<rob_house(nums,0,nums.size()-2)<<endl;
        // return 33;
        if(nums.size()==1)
            return nums[0];
        return max(rob_house(nums,0,nums.size()-2),rob_house(nums,1,nums.size()-1));
        // int n=nums.size();
        // vector<int> dp(n);
        // houserobber(nums,dp,0);
        // int maxi=nums[0];
        // for(int i=0;i<n;i++){
        //     maxi=max(maxi,dp[i]);
        //     // cout<<"DP "<<dp[i]<<endl;
        // }
        // return maxi;
    }
};