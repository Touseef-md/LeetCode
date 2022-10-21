class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0,j=0;
        unordered_map<int,int> mp;
        for(;j<k&&j<nums.size();j++){
            auto it=mp.find(nums[j]);
            if(it!=mp.end()&&it->second>0)
                return true;
            mp[nums[j]]++;
        }
        while(j<nums.size()){
            auto it=mp.find(nums[j]);
            if(it!=mp.end()&&it->second>0)
                return true;
            mp[nums[j]]++;
            mp[nums[i]]--;
            i++;
            j++;
        }
        return false;
    }
};