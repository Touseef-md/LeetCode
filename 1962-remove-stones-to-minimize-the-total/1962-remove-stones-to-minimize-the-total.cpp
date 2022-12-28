class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
     priority_queue<int> pq;
        int total=0;
        for(auto i:piles){
            total+=i;
            pq.push(i);
        }
        int count=0;
        while(count<k){
            int x=pq.top();
            pq.pop();
            total-=x/2;
            pq.push(x-x/2);
            count++;
        }
        return total;
    }
};