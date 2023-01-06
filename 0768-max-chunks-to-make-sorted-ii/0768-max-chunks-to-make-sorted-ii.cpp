int binSearch(int l,int r,int target,int tindex,vector<int>& arr){
    int mid,ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(arr[mid]==target){
            ans=mid;
            if(mid>tindex)
                r=mid-1;
            else
                l=mid+1;
        }
        else if(arr[mid]<target){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> copyarr=arr;
        sort(copyarr.begin(),copyarr.end());
        set<pair<int,int>>intervals;
        int count=0,n=arr.size(),start,end;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==copyarr[i]){
                start=i;
                end=i;
            }
            else{
            start=i;
            end=binSearch(0,n-1,arr[i],i,copyarr);
            }
            intervals.insert({min(start,end),max(start,end)});
        }
        //Merge intervals
        // for(auto i:intervals){
        //     cout<<i.first<<"  "<<i.second<<endl;
        // }
        end=(intervals.begin())->second;
        count=1;
        for(auto i=intervals.begin();i!=intervals.end();i++){
            if(i->first<=end){
                end=max(end,i->second);
            }
            else{
                count++;
                end=i->second;
            }
        }
        return count;
    }
};