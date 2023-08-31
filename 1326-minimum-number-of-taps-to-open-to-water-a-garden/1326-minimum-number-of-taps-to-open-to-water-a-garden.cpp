class Solution {
public:
    static bool comp(vector<int>&a ,vector<int>& b){
        if(b[0]<a[0]){
            return false;
        }
        else if(b[0]==a[0]){
            if(b[1]>a[1]){
                return false;
            }
            return true;
        }
        return true;
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> intervals;
        for(int i=0;i<ranges.size();i++){
            intervals.push_back({max(0,i-ranges[i]),min(n,i+ranges[i])});
        }
        sort(intervals.begin(),intervals.end(),comp);
        if(intervals[0][0]!=0){
            return -1;
        }
        int result=1,prevEnd=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            // if(prevEnd==n)return result;
            if(intervals[i][1]<=prevEnd){
                continue;
            }
            else{
                if(intervals[i][0]>prevEnd){
                    return -1;
                }
                else{
                    int temp=0;
                    while(i<intervals.size()&&intervals[i][0]<=prevEnd){
                        temp=max(temp,intervals[i][1]);
                        i++;
                    }
                    i--;
                    prevEnd=temp;
                    result++;
                    // prevEnd=intervals[i][1];
                }
            }
            // cout<<i<<endl;
           
        }
        return result;
    }
};