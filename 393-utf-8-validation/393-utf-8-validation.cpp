#include<bits/stdc++.h>
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int size=data.size();
        // if(size==1){
        //     bitset<8> a(data[0]);
        //     if(a[0]==0)
        //         return true;
        //     return false;
        // }
        // else{
            int flag=0,count=0;
            for(int i=0;i<size;){
                if(flag==0){
                    bitset<8> b(data[i]);
                    count=0;
                    while(count<8){
                        if(b[7-count]==1)
                            count++;
                        else{
                            break;
                        }
                    }
                        if(count<=1){
                            if(count==1)
                                return false;
                            i++;
                            continue;
                        }
                        if(count>4)
                            return false;
                    flag=1;
                }
                else{
                    count--;
                    while(count--){
                        i++;
                        if(i>=size)
                            return false;
                    bitset<8> a(data[i]);
                        if(a[7]!=1||a[6]!=0){
                            return false;
                        }
                    }
                    flag=0;
                    i++;
                }
            }
            return true;
        // }
    }
};