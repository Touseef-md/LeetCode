class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        if(b[1]<a[1]){
            return false;
        }
        else if(b[1]==a[1]){
            if(b[0]<a[0]){
                return false;
            }
            return true;
        }
        else
            return true;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        // if
        int n=pairs.size(),count=1,end;
        if(n==1){
            return 1;
        }
        end=pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]<=end){
                // i++;
            }
            else{
                end=pairs[i][1];
                count++;
            }
        }
        return count;
    }
};