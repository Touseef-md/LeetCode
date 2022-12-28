class Solution {
public:
    int halveArray(vector<int>& nums) {
        long long int total=0,count=0;
        priority_queue<double>pq;
        for(auto i:nums){
            pq.push(i);
            total+=i;
        }
        double sumi=total;
        while(sumi>total/2.0){
            double x=pq.top();
            pq.pop();
            sumi-=x/2.0;
            pq.push(x-x/2);
            count++;
        }
        return count;
    }
};