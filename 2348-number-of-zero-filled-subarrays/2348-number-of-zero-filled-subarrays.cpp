class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0,n=nums.size();
        long long result=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                result+=(count*(count+1))/2;
                count=0;
            }
            else{
                count++;
            }
        }
        result+=(count*(count+1))/2;
        return result;
    }
};