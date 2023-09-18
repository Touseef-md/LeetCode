class Solution {
public:
    static bool compp(vector<int>& a,vector<int>& b){
        int count=0;
        for(int i=0;i<a.size()-1;i++){
            if(a[i]==1){
                count++;
            }
            if(b[i]==1){
                count--;
            }
        }
        if(count==0){
            if(a[a.size()-1]>b[a.size()-1]){
                return false;
            }
            return true;
        }
        else if(count>0){
            return false;
        }
        else{
            return true;
        }
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<mat.size();i++){
            mat[i].push_back(i);
        }
        sort(mat.begin(),mat.end(),compp);
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(mat[i][n]);
        }
        return result;
    }
};