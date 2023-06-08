class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32> bitA(a);
        bitset<32> bitB(b);
        bitset<32> bitC(c);
        // cout<<bitA<<endl;
        int count=0;
        for(int i=0;i<32;i++){
            // if(bitC[i]!=bitA[i]||bitB[i])
            //     count++;
            if(bitC[i]==0){
                if(bitA[i]==1){
                    if(bitB[i]==1){
                        count+=2;
                    }
                    else{
                        count+=1;
                    }
                }
                else{
                    if(bitB[i]==1){
                        count+=1;
                    }
                }
            }
            else{
                if(bitA[i]==0){
                    if(bitB[i]==0){
                        count+=1;    
                    }
                }
            }
            // cout<<bitA[i]<<endl;
        }
        return count;
        return 0;
    }
};