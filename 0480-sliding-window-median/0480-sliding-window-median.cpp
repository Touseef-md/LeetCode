#include<bits/stdc++.h>
unordered_map<int,int>mp;
int balance=0;
void balancePq(priority_queue<int>& minH,priority_queue<int,vector<int>,greater<int>>& maxH){
    while(balance>0){
        if(!minH.empty()&&mp.find(minH.top())!=mp.end()&&mp[minH.top()]!=0){
            mp[minH.top()]--;
            minH.pop();
        }else{
            maxH.push(minH.top());
            minH.pop();
            balance-=2;
        }
    }
    while(balance<0){
        if(!maxH.empty()&&mp.find(maxH.top())!=mp.end()&&mp[maxH.top()]!=0){
            mp[maxH.top()]--;
            maxH.pop();
        }
        else{
            minH.push(maxH.top());
            maxH.pop();
            balance+=2;
            // balance--;
        }
    }
}
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> minH;
        priority_queue<int,vector<int>,greater<int>> maxH;
        vector<double>  result;
        mp.clear();
        int i,n=nums.size();
        for(i=0;i<k;i++){
            minH.push(nums[i]);
        }    
        for(i=0;i<k/2;i++){
            maxH.push(minH.top());
            minH.pop();
        }
        balance=0;
        (k%2!=0)?result.push_back(minH.top()):result.push_back((minH.top()*1.0+maxH.top()*1.0)/2.0);
        balance=0;
        i=k;
        // cout<<"hello"<<endl;
        while(i<n){
            // cout<<i<<endl;
            // balance--;
            if(nums[i]<=minH.top()){
                minH.push(nums[i]);
                balance++;   
            }
            else{
                maxH.push(nums[i]);
                balance--;
            }
            mp[nums[i-k]]++;
            if(minH.size()>=1&&nums[i-k]==minH.top()){
                balance--;
                minH.pop();
                mp[nums[i-k]]--;
            }           
            else if(maxH.size()>=1&&nums[i-k]==maxH.top()){
                balance++;
                maxH.pop();
                mp[nums[i-k]]--;
            }
            else if(minH.size()>=1&&nums[i-k]<minH.top()){
                balance--;
            }
            else if(maxH.size()>=1&&nums[i-k]>maxH.top()){
                balance++;
            }
            // cout<<i<<"  "<<balance<<"bEfore balacne"<<endl;
            balancePq(minH,maxH);   
            while(!minH.empty()&&mp.find(minH.top())!=mp.end()&&mp[minH.top()]!=0){
                mp[minH.top()]--;
                minH.pop();
            }
            while(!maxH.empty()&&mp.find(maxH.top())!=mp.end()&&mp[maxH.top()]!=0){
                mp[maxH.top()]--;
                maxH.pop();
            }
            (k%2!=0)?result.push_back(minH.top()):result.push_back((minH.top()*1.0+maxH.top()*1.0)/2.0);
            // cout<<i<<"  "<<result[result.size()-1]<<endl;
            i++;
        }
        return result;
        // balancePq(minH,maxH);
    }
};