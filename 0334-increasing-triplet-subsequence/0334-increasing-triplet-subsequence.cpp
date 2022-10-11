class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        map<int,int> left;
        map<int,int> right;
        bool leftt=false,rightt=false;
        for(int i=nums.size()-1;i>=0;i--){
            right[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            leftt=false;
            rightt=false;
            auto it1=left.lower_bound(nums[i]);
            if(it1==left.end()){
                if(left.size()==0){
                    left[nums[i]]++;
                    right[nums[i]]--;
                    if(right[nums[i]]==0){
                        right.erase(nums[i]);
                    }
                continue;
                }
                // --it1;
                // left=true;
            }
            else if(it1==left.begin()){
                left[nums[i]]++;
                right[nums[i]]--;
                if(right[nums[i]]==0)
                    right.erase(nums[i]);
                continue;
            }
            --it1;
            left[nums[i]]++;
            leftt=true;
            auto it2=right.upper_bound(nums[i]);
            if(it2==right.end()){
                right[nums[i]]--;
                if(right[nums[i]]==0)
                    right.erase(nums[i]);
                continue;
            }
            right[nums[i]]--;
            if(right[nums[i]]==0)
                right.erase(nums[i]);
            rightt=true;
            if(leftt&&rightt)
                return true;
        }
        return false;
    }
};