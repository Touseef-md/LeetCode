unordered_map<int,string> mp;
class Solution {
public:
    string intToRoman(int num) {
        mp[1]="I";
        mp[2]="II";
        mp[3]="III";
        mp[4]="IV";
        mp[5]="V";
        mp[6]="VI";
        mp[7]="VII";
        mp[8]="VIII";
        mp[9]="IX";
        mp[10]="X";
        mp[50]="L";
        mp[100]="C";
        mp[500]="D";
        mp[1000]="M";
        mp[40]="XL";
        mp[90]="XC";
        mp[400]="CD";
        mp[900]="CM";
        int count=0,n,place_n;
        string st="";
        auto it=mp.find(num);
        if(it!=mp.end())
            return it->second;
        for(int i=11;i<=3999;i++){
            count=0,n=i;
            st="";
            while(n){
                int x=n%10;
                place_n=int(pow(10,count)+0.5)*x;
                if(x==2||x==3||x==6||x==7||x==8){
                    if(x==2){
                        // int a=x/2;
                        st=mp[place_n/2]+mp[place_n/2]+st;
                    }
                    else if(x==3){
                        st=mp[place_n/3]+mp[place_n/3]+mp[place_n/3]+st;
                    }
                    else if(x==6){
                        st=mp[place_n-1*int(pow(10,count)+0.5)]+mp[int(pow(10,count)+0.5)]+st;
                    }
                    else if(x==7){
                        st=mp[place_n-2*int(pow(10,count)+0.5)]+mp[int(pow(10,count)+0.5)]+mp[int(pow(10,count)+0.5)]+st;
                    }
                    else if(x==8){
                          st=mp[place_n-3*int(pow(10,count)+0.5)]+mp[int(pow(10,count)+0.5)]+mp[int(pow(10,count)+0.5)]+mp[int(pow(10,count)+0.5)]+st; 
                    }
                }
                else{
                    st=mp[place_n]+st;
                }
                n/=10;
                count++;
            }
                mp[i]=st;
        }
        return mp[num];
    }
};