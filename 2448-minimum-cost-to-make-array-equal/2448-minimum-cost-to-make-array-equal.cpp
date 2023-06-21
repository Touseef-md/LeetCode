class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int l=mini,r=maxi,mid,n=nums.size();
        long long int cost1=0,cost2=0,final_cost=1000000000000;
        while(l<=r){
            mid=l+(r-l)/2;
            cost1=0;
            cost2=0;
            for(int i=0;i<n;i++){
                cost1+=abs(nums[i]-mid)*1LL*cost[i];
                cost2+=abs(nums[i]-mid-1)*1LL*cost[i];
            }
            if(cost1<cost2){
                final_cost=cost1;
                r=mid-1;
            }
            else{
                final_cost=cost2;
                l=mid+1;
            }
            // if(cost<final_cost){
            //     final_cost=cost;
            //     r=mid-1;
            // }
            // else{
            //     l=mid+1;
            // }
        }
        return final_cost;
    }
};