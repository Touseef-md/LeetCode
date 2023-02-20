class Solution {
public:
    int binSearch(vector<int>& nums,int target){
        int l=0,r=nums.size()-1,mid,ans=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target){
                return ans=mid;
            }
            else if(nums[mid]>target){
                ans=mid;
                r=mid-1;
            }
            else{
                // ans=mid;
                l=mid+1;
            }
        }
        if(ans==-1)
            ans=nums.size();
        return ans;
    }
    int searchInsert(vector<int>& nums, int target) {
        return this->binSearch(nums,target);
    }
};