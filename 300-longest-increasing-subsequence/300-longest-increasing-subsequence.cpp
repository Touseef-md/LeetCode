class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),len=0,mid,l,r,upper_b=0;
        vector<int> tail(n,INT_MIN);
        tail[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<=tail[0]){
                tail[0]=nums[i];
            }
            else if(tail[len]<nums[i])
                tail[++len]=nums[i];
            else{
                l=0;r=len,upper_b=-1;
                while(l<=r){
                    mid=l+(r-l)/2;
                    if(tail[mid]>=nums[i]){
                        upper_b=mid;
                        r=mid-1;
                    }
                    else if(tail[mid]<nums[i]){
                        // upper_b=mid;
                        l=mid+1;
                    }
                }
                tail[upper_b]=nums[i];
            }
            // cout<<len<<" LEN"<<endl;
        }
        return len+1;
    }
};