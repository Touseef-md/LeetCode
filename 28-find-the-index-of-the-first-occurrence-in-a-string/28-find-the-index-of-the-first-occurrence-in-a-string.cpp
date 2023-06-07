class Solution {
public:
    int binExpo(int& a,int b,int& c){
        if(b==0)
            return 1;
        if(b==1)
            return a;
        long long int x=binExpo(a,b/2,c)%c;
        if(b%2==0)
            return (x*x)%c;
        return (a*((x*x)%c))%c;
    }
    vector<int> RabinKarpDoubleHash(string& haystack,string& needle){
        vector<int> result;
        int n=haystack.size(),m=needle.size();
        if(n<m)
            return {};
        int radix1=31,radix2=10;
        int mod1=1000003,mod2=10000019;
        int power1=binExpo(radix1,m,mod1),power2=binExpo(radix2,m,mod2);
        // cout<<"powers "<<power1<<"  "<<power2<<endl;
        int needleHash1=0,needleHash2=0,strHash1=0,strHash2=0;
        for(int i=0;i<m;i++){
            needleHash1=(needleHash1*radix1)%mod1+needle[i];
            needleHash1%=mod1;
            needleHash2=(needleHash2*radix2)%mod2+(needle[i]-'a');
            needleHash2%=mod2;
        }
        // cout<<needleHash1<<"  "<<needleHash2<<endl;
        for(int i=0;i<=n-1;i++){
            strHash1=(strHash1*radix1)%mod1+haystack[i];
            strHash1%=mod1;
            strHash2=(strHash2*radix2)%mod2+(haystack[i]-'a');
            strHash2%=mod2;
            if(i<m-1){
                continue;
            }
            // cout<<i<<endl;
            if(i>=m){
                strHash1=strHash1-(power1*haystack[i-m])%mod1;
                strHash1%=mod1;
                strHash2=strHash2-(power2*(haystack[i-m]-'a'))%mod2;
                strHash2%=mod2;
                if(strHash1<0){
                    strHash1+=mod1;
                }
                if(strHash2<0){
                    strHash2+=mod2;
                }
            }
            // cout<<strHash1<<"  "<<strHash2<<endl;
            if(strHash1==needleHash1&&strHash2==needleHash2){
                result.push_back(i-m+1);
            }
        }
        return result;
    }
    
    int strStr(string haystack, string needle) {
        vector<int> result=RabinKarpDoubleHash(haystack,needle);
        if(result.size()==0)
            return -1;
        return result[0];
        // int n=haystack.size(),m=needle.size();
        // // if(haystack==needle)
        // //     return 0;
        // for(int i=0;i<=n-m;i++){
        //     if(haystack.substr(i,m)==needle){
        //         return i;
        //     }
        // }
        // return -1;
    }
};