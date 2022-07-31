bool compp(vector<int>& a,vector<int>& b){
    if(b[0]<a[0])
        return false;
    else if(b[0]==a[0])
        if(b[1]>a[1])
            return false;
        return true;
    return true;
}
bool comp(vector<int>& a,vector<int>& b){
    if(a[0]<b[0])
        return true;
    else if(a[0]==b[0]){
        if(a[1]>b[1])
            return true;
    }
    return false;
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
   vector<vector<int>> result;
sort(intervals.begin(),intervals.end(),comp);
int i=0,j=1,count=1;
vector<int> temp(2);
temp[0]=intervals[0][0];
temp[1]=intervals[0][1];
while(j<intervals.size()){
    if(temp[1]>=intervals[j][0]){
            temp[1]=max(temp[1],intervals[j][1]);
        j++;
    }
    else{
        result.push_back(temp);
        i=j;
        temp[0]=intervals[i][0];
        temp[1]=intervals[i][1];
        j++;
    }
}
// temp[0]=intervals[i][0];
// temp[1]=intervals[j-1][1];
result.push_back(temp);
return result;     
    }
};