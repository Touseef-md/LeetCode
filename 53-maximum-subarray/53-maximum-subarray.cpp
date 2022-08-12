class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumi=nums[0],maxi=nums[0];
        if(nums.size()==1)
            return nums[0];
        for(int i=1;i<nums.size();i++){
            if(sumi+nums[i]>=0){
                sumi=max(sumi+nums[i],nums[i]);
                // sumi+=nums[i];
                maxi=max(maxi,sumi);
            }
            else{
                sumi=nums[i];
                maxi=max(maxi,sumi);
            }
        }
        return maxi;
    }
};