class Solution {
public:
    void per(vector<vector<int>>&result,vector<int>& temp_ans,vector<int>& nums,int i){
        if(i==nums.size()){
            result.push_back(temp_ans);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            temp_ans.push_back(nums[i]);
            per(result,temp_ans,nums,i+1);
            temp_ans.pop_back();
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp_ans;
        per(result,temp_ans,nums,0);
        return result;
    }
};