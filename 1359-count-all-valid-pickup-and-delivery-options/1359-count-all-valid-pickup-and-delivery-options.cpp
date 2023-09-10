// #include <boost/multiprecision/cpp_int.hpp>
class Solution {
public:
    long long int  mod=1000000007;
    unordered_map<int,long long int> factDp;
    long long int fact(int n){
        if(n<=1){
            return 1;
        }
        long long int temp=(n*1LL*(fact(n-1)%mod));
        // cout<<temp<<"sdf"<<endl;
        return temp%mod;
    }
//     long long int  modInverse(long long int A, long long int M)
// {
//     for (int X = 1; X < M; X++)
//         if (((A % M) * (X % M)) % M == 1)
//             return X;
//         cout<<"-1 Returning"<<endl;
//         return -1;
// }
int gcd(int a, int b);
 
// To compute x raised to power y under modulo M
int power(int x, unsigned int y, unsigned int M);
 
// Function to find modular inverse of a under modulo M
// Assumption: M is prime
long long int modInverse(long long int A,long long  int M)
{
    long long int g = gcd(A, M);
    if (g != 1){
        // cout << "Inverse doesn't exist";
        return 0;
    }
    else {
        // If a and m are relatively prime, then modulo
        // inverse is a^(m-2) mode m
        // cout << "Modular multiplicative inverse is "
             // << power(A, M - 2, M);
        return power(A,M-2,M);
    }
    cout<<"WRONG PLACE"<<endl;
    return 0;
}
 
// To compute x^y under modulo m
long long int power(long long int x, unsigned long long  int y, unsigned long long  int M)
{
    if (y == 0)
        return 1;
 
    long long int p = power(x, y / 2, M) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
 
// Function to return gcd of a and b
long long int gcd(long long int a,long long  int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
    
    
    long long int binExpo(int &x,int y){
        if(y==0)return 1;
        if(y==1)return x;
        int temp=binExpo(x,y/2);
        if(y%2==0){
            return (temp*1LL*temp);
        }
        else{
            return (x*1LL*((temp*1LL*temp)));
        }
    }
    int countOrders(int n) {
        long long int factorial=fact(2*n);
        int base=2;
        cout<<factorial<<endl;
        cout<<binExpo(base,n)<<endl;
        long long int inverse=modInverse(2,mod)%mod;
        for(int i=0;i<n;i++){
            factorial=(1ll*factorial*(inverse))%mod;
        }
        return (factorial)%mod;
    }
};