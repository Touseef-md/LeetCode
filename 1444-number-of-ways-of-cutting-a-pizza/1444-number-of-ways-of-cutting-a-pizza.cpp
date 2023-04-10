#define mod 1000000007
class Solution {
public:
    vector<vector<int>> pizzaCount;
    vector<vector<vector<int>>> dp;
    int m,n;
    int pizzaWays(vector<string>& pizza,int i,int j,int cuts){
        // if(i>=pizza.size()||j>=pizza[0].size())
        //     return 0;
        if(cuts==0){
            // cout<<"BASE case ans is 1"<<endl;
            return 1;
        }
        if(dp[i][j][cuts]!=-1){
            // cout<<"DP answer is "<<i<<"  "<<j<<" "<<dp[i][j][cuts]<<endl;
            return dp[i][j][cuts];
        }
        int ways=0;
        for(int k=i;k<m-1;k++){
            if(pizzaCount[k+1][j]>0&&(pizzaCount[i][j]-pizzaCount[k+1][j])>0){
                // cout<<"Valid rows "<<k+1<<" "<<j<<endl;
                // cout<<pizzaCount[k+1][j]<<"  "<<pizzaCount[i][j]-pizzaCount[k+1][j]<<endl;
                ways+=pizzaWays(pizza,k+1,j,cuts-1)%mod;
                ways%=mod;
            }
        }
        for(int k=j;k<n-1;k++){
            if(pizzaCount[i][k+1]>0&&(pizzaCount[i][j]-pizzaCount[i][k+1])>0){
                // cout<<"VAlid cols "<<i<<" "<<k+1<<endl;
                ways+=pizzaWays(pizza,i,k+1,cuts-1)%mod;
                ways%=mod;
            }
        }
        // cout<<i<<"  "<<j<<" ans "<<ways<<endl;
        // cout<<"Correct answer is "<<i<<" "<<j<<"  "<<ways%mod<<endl;
        return dp[i][j][cuts]=ways%mod;
    }
    int ways(vector<string>& pizza, int k) {
        int flag=0,count=0,total_count=0;
        m=pizza.size();
        n=pizza[0].size();
        pizzaCount.clear();
        dp.clear();
        dp.resize(m,vector<vector<int>>(n,vector<int>(k,-1)));
        pizzaCount.resize(m,vector<int>(n,0));
        // mp.clear();
        
        // empty_below.clear();
        // empty_above.clear();
        // empty_below.resize(m,vector<bool>(n,false));
        // empty_above.resize(m,vector<bool>(n,false));
        // for(int i=m-1;i>=0;i--){
        //     for(int j=n-1;j>=0;j--){
        //         if(j+1<n){
        //             empty_below[i][j]=empty_below[i][j]||empty_below[i][j+1];
        //         }
        //         if(i+1<m){
        //             empty_below[i][j]=empty_below[i][j]||empty_below[i+1][j];
        //         }
        //         if(pizza[i][j]=='A'){
        //             empty_below[i][j]=true;
        //         }
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     for(int j=n-1;j>=0;j--){
        //         if(j+1<n){
        //             empty_above[i][j]=empty_above[i][j]||empty_above[i][j+1];
        //         }
        //         if(i+1<m){
        //             empty_above[i][j]=empty_above[i][j]||empty_above[i+1][j];
        //         }
        //         if(pizza[i][j]=='A'){
        //             empty_above[i][j]=true;
        //         }
        //     }
        // }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
            count=0;
                if(pizza[i][j]=='A'){
                    count+=1;
                    total_count+=1;
                }
                if(j+1<n)
                    count+=pizzaCount[i][j+1];
                if(i+1<m)
                    count+=pizzaCount[i+1][j];
                if(i+1<m&&j+1<n){
                    count-=pizzaCount[i+1][j+1];
                }
                pizzaCount[i][j]=count;
            }
        }
        if(total_count==0)
            return 0;
        return pizzaWays(pizza,0,0,k-1);
        
        
    }
};