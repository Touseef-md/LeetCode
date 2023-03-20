class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool flag=false;
        int count=0,m=flowerbed.size();
        for(int i=0;i<m;i++){
            if(flowerbed[i]==1)
                continue;
            flag=true;
            if(i-1>=0&&flowerbed[i-1]==1)
                flag=false;
            if(i+1<m&&flowerbed[i+1]==1)
                flag=false;
            if(flag){
                flowerbed[i]=1;
                count++;
            }
        }
        if(count>=n)
            return true;
        return false;
    }
};