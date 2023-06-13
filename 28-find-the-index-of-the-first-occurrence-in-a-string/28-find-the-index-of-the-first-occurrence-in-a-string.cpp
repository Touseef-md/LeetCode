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
//     abcxxxabc ab
//     abcxxxabcy
    //abceabcdabcfabc
    //ababcdababd
  //-10012001234
    //aabaaac
  //-101
    vector<int> lpsArray(string& pat){
        int i=1,j=2,count=0,n=pat.size();
        vector<int> lps(n+1,0);
        lps[0]=-1;
        lps[1]=0;
        while(j<=n){
            if(pat[i-1]==pat[j-1]){
                count++;
                lps[j]=count;
                i++;j++;
            }
            else{
                if(i==1){
                    lps[j]=count;
                    // if(j==3){
                    //     cout<<lps[j]<<" csdsf"<<endl;
                    //     break;
                    // }
                    j++;
                }
                else{
                    count=lps[i-1];
                    i=lps[i-1]+1;
                    // conti
                }
                // i=0;
                // if(pat[i])
                // count=0;
                // if(i!=1){
                //     i=lps[i];
                //     count=lps[i];
                //     continue;
                //     // j--;
                // }
                // count=0;
                // lps[j]=0;
                // j++;
            }
            // cout<<i<<"  "<<j<<endl;
        }
        // cout<<"lps array"<<endl;
        // for(int i=0;i<=n;i++){
        //     cout<<i<<"  "<<lps[i]<<endl;
        // }
        // cout<<"Finished"<<endl;
        return lps;
    }
    //abc
    //def
    //abcd
    //acde
    //j=j-(j-lps[j-1])
    vector<int> KMP(string& text,string& pattern){
        vector<int> lps=lpsArray(pattern);
        int m=text.size(),n=pattern.size(),i=0,j=0;
        vector<int> result;
        while(i<m){
            // cout<<i<<endl;
            if(text[i]==pattern[j]){
                i++;j++;
                if(j==n){
                    result.push_back(i-n);
                    j=0;
                }
            }
            else{
                if(j==0){
                    i++;
                }
                else{
                    j=lps[j];//Because the lps array is 1 indexing based and here j is 0 indexed
                }
            }
            // if(j==)
        }
        return result;
    }
    
    int strStr(string haystack, string needle) {
        //--------------RABINKARP DOUBLE HASH
        // vector<int> result=RabinKarpDoubleHash(haystack,needle);
        // if(result.size()==0)
        //     return -1;
        // return result[0];
        //--------------------------------------------
        // int n=haystack.size(),m=needle.size();
        // // if(haystack==needle)
        // //     return 0;
        // for(int i=0;i<=n-m;i++){
        //     if(haystack.substr(i,m)==needle){
        //         return i;
        //     }
        // }
        // return -1;
        //--------------------------KMP ALGORITHM---------
        vector<int> kmpresult=KMP(haystack,needle);
        if(kmpresult.size()==0)
            return -1;
        return kmpresult[0];
    }
};