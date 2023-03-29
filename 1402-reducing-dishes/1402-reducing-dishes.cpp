class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        vector<int> result(n+1,0);
        vector<int> suffix(n+1,0);
        int curr_res,res_till_now;
        sort(satisfaction.begin(),satisfaction.end());
        int flag=0;
        for(int i=n-1;i>=0;i--){
            res_till_now=result[i+1];
            curr_res=res_till_now+suffix[i+1]+satisfaction[i];
            if(res_till_now>curr_res){
                flag=1;
                break;
            }
            suffix[i]+=suffix[i+1]+satisfaction[i];
            result[i]=curr_res;
        }
        if(flag==1)
            return res_till_now;
        return curr_res;
    }
};