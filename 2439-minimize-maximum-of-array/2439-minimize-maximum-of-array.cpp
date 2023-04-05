class Solution {
public:
    bool check(vector<int>& nums,int target){
        long long int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>target){
                if(i==0)
                    return false;
                if((nums[i]-target)<=count){
                    count-=(nums[i]-target);
                    continue;
                }
                else
                    return false;
            }
            else {
                count+=target-nums[i];
            }
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int l=*min_element(nums.begin(),nums.end());
        int r=*max_element(nums.begin(),nums.end());
        int mid,ans=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            // cout<<mid<<"  "<<ans<<endl;
            if(check(nums,mid)){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};