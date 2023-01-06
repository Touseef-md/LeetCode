class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int currCoin=0,count=0;
        sort(costs.begin(),costs.end());
        for(int i=0;i<costs.size();i++){
            if(currCoin+costs[i]<=coins){
                currCoin+=costs[i];
                count++;
            }
            else
                break;
            
        }
        return count;
    }
};