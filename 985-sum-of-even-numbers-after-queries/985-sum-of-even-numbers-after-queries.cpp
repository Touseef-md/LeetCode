class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even=0,odd=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)
                even+=nums[i];
            else
                odd+=nums[i];
        }
        vector<int> answer;
        for(int i=0;i<queries.size();i++){
            if(nums[queries[i][1]]%2==0){
                if((nums[queries[i][1]]+queries[i][0])%2==0){
                    even+=queries[i][0];
                    nums[queries[i][1]]+=queries[i][0];
                }
                else{
                    even-=nums[queries[i][1]];
                    nums[queries[i][1]]+=queries[i][0];
                    odd+=nums[queries[i][1]];
                }
            }
            else{
                if((nums[queries[i][1]]+queries[i][0])%2==0){
                    odd-=nums[queries[i][1]];
                    nums[queries[i][1]]+=queries[i][0];
                    even+=nums[queries[i][1]];
                }
                else{
                    odd+=queries[i][0];
                    nums[queries[i][1]]+=queries[i][0];
                }
            }
            answer.push_back(even);
        }
        return answer;
    }
};