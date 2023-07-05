class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count=0,mask=0,number=0;
        for(int i=0;i<32;i++){
            count=0;
            mask=1<<i;
            for(auto num:nums){
                if(num&mask)count++;
            }
            count%=3;
            if(count!=0){
                number|=mask;
            }
            // else
        }
        return number;
    }
};