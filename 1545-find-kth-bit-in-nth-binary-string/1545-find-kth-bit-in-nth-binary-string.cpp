class Solution {
public:
    string temp, tempReverse;
    void negate(string & st){
        for(int i=0;i< st.length();i ++){
            if(st[i]=='1'){
                st[i]='0';
            }
            else{
                st[i]='1';
            }
        }
        return;
    }
    string recurse(int n){
        if( n== 1){
            return "0";
        }
        temp = recurse(n-1);
        tempReverse = temp;
         negate(tempReverse);
        reverse(tempReverse.begin(), tempReverse.end());
        string newSt = temp + "1" + tempReverse;
        return newSt;
    }
    char findKthBit(int n, int k) {
        if( n== 1){
            return '0';
        }
        string result = recurse(n);
        // cout<<"RESULT IS "<<result<<endl;
        return result[k-1];
        
    }
};