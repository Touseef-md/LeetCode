    bool compp( vector<int>& a, vector<int> & b){
        if(a[1]<b[1])
            return true;
        else if(b[1]==a[1]){
            if(a[0]<b[0])
                return true;
        }
        return false;
        // return false;
        if(b[1]<a[1])
            return false;
    else if(b[1]==a[1]){
        if(b[0]<a[0])
            return false;
    //     return true;
        }
        return false;
    }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& interval) {
        sort(interval.begin(),interval.end(),compp);
        int  i=0,j=1;
        if(interval.size()<=1)
            return 0;
        int count=0;
        while(j<interval.size()){
            if(interval[i][1]>interval[j][0]){
                count++;
                j++;
            }
            else{
                i=j;
                j++;
            }
        }
        return count;
    }
};