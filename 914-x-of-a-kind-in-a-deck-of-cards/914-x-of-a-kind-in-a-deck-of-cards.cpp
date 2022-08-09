int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);    
}

vector<int> seive_of_Eratosthenes(int n){
    vector<int> primes;
    vector<int> mark(n+1,false);
    for(int i=2;i<=n;i++){
        if(!mark[i]){
            for(int j=i*i;j<=n;j++){
                if(!mark[j])
                    mark[j]=true;
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(!mark[i])
            primes.push_back(i);
    return primes;
}

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n=deck.size();
        unordered_map<int,int> mp;
        // vector<int> primes=seive_of_Eratosthenes(10000);
    for(auto it:deck)
        mp[it]++;
    if(mp.size()==1){
        if(mp.begin()->second==1)
            return 0;
        // for(auto it:primes){
        //     if(mp.begin()->second==it)
        //         return 0;
        // }
        return 1;
    }
    int first=mp.begin()->second,_gcd=mp.begin()->second;
    for(auto it=(++mp.begin());it!=mp.end();it++){
        first=min(first,it->second);
        _gcd=gcd(_gcd,it->second);
    }
    if(_gcd!=1)
        return 1;
    return 0;
    }
};