class Solution {
public:
    void getPerm(vector<vector<int>>& result,vector<int> &temp_ans,vector<int>& nums,int i){
        if(i==nums.size()){
            result.push_back(temp_ans);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            temp_ans.push_back(nums[i]);
            getPerm(result,temp_ans,nums,i+1);
            temp_ans.pop_back();
        }
    }
    void getNums(vector<vector<int>>& result,vector<int>& temp_ans,vector<int>& nums,int i,int &k){
        if(k==0){
            result.push_back(temp_ans);
            return;
        }
        if(i>=nums.size()){
            return;
        }
        temp_ans.push_back(nums[i]);
        --k;
        getNums(result,temp_ans,nums,i+1,k);
        ++k;
        temp_ans.pop_back();
        getNums(result,temp_ans,nums,i+1,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> temp_result;
        vector<vector<int>> result;
        vector<int> temp_ans;
        vector<int> nums;
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        // cout<<"NUms done"<<endl;
        getNums(temp_result,temp_ans,nums,0,k);
        // cout<<"GET nums done "<<endl;
        // for(int j=0;j<temp_result.size();j++){
        //     getPerm(result,temp_ans,temp_result[j],0);
        // }
        return temp_result;
    }
};