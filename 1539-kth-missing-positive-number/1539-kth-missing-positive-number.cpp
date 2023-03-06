class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> v(1001,1);
        for(int i=0;i<arr.size();i++){
            v[arr[i]]--;
        }
        int i=1;
        while(i<=1000){
        // cout<<"Checknig "<<i<<endl;
            if(v[i]==1){
                k--;
            }
            if(k==0){
                return i;
            }
            i++;
        }
        while(1){
            k--;
            if(k==0)
                return i;
            i++;
        }
        return -1;
    }
};