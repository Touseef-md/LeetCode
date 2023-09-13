class Solution {
public:
    int nn;
    vector<int> candies;
    void func(vector<int> & ratings,int i,int j){
          if(i>j)
              return ;
        int mini=INT_MAX,indx;
        for(int k=i;k<=j;k++){
            if(mini>ratings[k]){
                mini=ratings[k];
                indx=k;
            }
        }
        int l=indx,r=indx;
        l--;r++;
        while(l>=i){
            if(ratings[l]>ratings[l+1])
                candies[l]=max(candies[l],candies[l+1]+1);
            else if(ratings[l]==ratings[l+1]){
                
            }
            else{
                func(ratings,i,l+1);
                break;
            }
            l--;
        }
        while(r<=j){
            if(ratings[r]>ratings[r-1])
                candies[r]=max(candies[r],candies[r-1]+1);
            else if(ratings[r]==ratings[r-1]){
                
            }
            else{
                func(ratings,r-1,j);
                break;
            }
            r++;
        }
        if(i+1<nn&&i-1>=0){
            if(ratings[i+1]<ratings[i]){
                if(ratings[i]>ratings[i-1])
                    candies[i]=max(candies[i-1],candies[i+1])+1;
                else  if(ratings[i]==ratings[i-1])
                    candies[i]=candies[i+1]+1;
            }
            else if(ratings[i]==ratings[i+1]){
                cout<<"Lets see"<<endl;
            }
        }
        if(j+1<nn&&j-1>=0){
            if(ratings[j]>ratings[j-1]){
                if(ratings[j]==ratings[j+1]){
                    candies[j]=candies[j-1]+1;
                }
                else if(ratings[j]>ratings[j+1])
                    candies[j]=max(candies[j-1],candies[j+1])+1;
            }
            else 
                cout<<"LETS SEE 2"<<endl;
        }
    }
    
    int candy(vector<int>& ratings) {
        nn=ratings.size();
        candies.clear();
        candies.resize(nn,1);
        func(ratings,0,nn-1);
        int sumi=accumulate(candies.begin(),candies.end(),0);
        return sumi;
        return 0;
    }
};