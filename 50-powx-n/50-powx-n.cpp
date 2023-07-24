class Solution {
public:
    double binExpo(double &x,long long int n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        double temp=binExpo(x,n/2);
        if(n%2==0){
            return temp*temp;
        }
        else{
            return x*temp*temp;
        }
    }
    double myPow(double x, int n) {
        if(n>=0){
            return binExpo(x,n);
        }
        else{
            double pow=(-1)*(n*1LL);
            return 1/binExpo(x,pow);
        }
    }
};