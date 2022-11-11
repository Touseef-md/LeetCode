class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1,j=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                
                continue;
            }
            count+=1;
            j+=1;
            nums[j]=nums[i+1];
        }
        // cout<<count<<endl;
        return count;
    }
};