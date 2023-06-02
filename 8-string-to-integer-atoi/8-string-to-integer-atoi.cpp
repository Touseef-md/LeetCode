class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        long flag=0,i=0,j=0,sign=1,count=0,maxi=2147483648-1,mini=-2147483648,num=0,placeValue=1;
        // while(i<n){
            while(i<n&&s[i]==' '){
                i++;
            }
                if(s[i]=='-'){
                    sign=-1;
                    i++;
                }
                else if(s[i]=='+'){
                    i++;
                }
                if((s[i]<=47)||s[i]>57){
                    return 0;
                }
        while(i<n&&s[i]==48){
            i++;
        }
            
            // i++;
        j=i;
        while(j<n&&(s[j]>=48&&s[j]<=57)){
            j++;
            // count++;
        }
        j--;
        // while(j>=0&&(s[j]==' '||s[j]<=47||s[j]>57)){
        //     // if(s[j]==' ')
        //         s.pop_back();
        //     j--;
        // }
        // n=j-i+1;
            // cout<<i<<"  "<<j<<endl;
        while(j>=i){
            if(s[j]>=48&&s[j]<=57){
                if(sign==1){
                    if(num+placeValue*(s[j]-48)>=maxi)
                        return maxi;
                }
                else{
                    if((num+placeValue*(s[j]-48))*(-1)<=mini)
                        return mini;
                }
                num+=placeValue*(s[j]-48);
                if(placeValue*10>=maxi&&j-1>=i){
                    if(sign==1){
                    // if(num+placeValue*(s[j]-48)>=maxi)
                        return maxi;
                    }
                    else{
                        return mini;
                        // if((num+placeValue*(s[j]-48))*(-1)<=mini)
                            // return mini;
                    }   
                }
                placeValue*=10;
                flag=1;
            }
            else if(s[j]==46){
                placeValue=1;
                num=0;
            }
            else{
                if(flag==1){
                    break;
                }
            }
            // if(num>=maxi){
            //     return maxi;
            // }
            // else if(num<=mini)
            //     return mini;
            j--;
        }
        
            // if(s[j-1]>=48&&s[j-1]<=57){
            //     // if(num+placeValue*(s[j]-48)>=maxi){
            //         if(sign==1)
            //             return maxi;
            //         else{
            //             if(num>=maxi+1)
            //                 return mini;
            //         }
            //     // }
            //         // return maxi;
            //     // if(num)
            //     num+=placeValue*(s[j]-48);
            //     // cout<<"whiel "<<j<<" num is "<<num<<endl;
            //     if(placeValue*10>=maxi){
            //         break;
            //     }
            //     placeValue*=10;
            //     flag=1;
            // }
        
        if(sign==-1)
            return -1*num;
        return num;
            
        // }
        // for(int i=0;i<n;i++){
            // if
        // }
    }
};