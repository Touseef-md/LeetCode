bool comp(vector<int>& a,vector<int>& b){
    if(b[0]<a[0])
        return false;
    return true;
}
class Solution {
public:
   int minRefuelStops(int target, int startFuel, vector<vector<int>> s) {
        if(s.size()==0){
            if(startFuel>=target)
                return 0;
            return -1;
        }
       // else if(s.size()==1)
            
       priority_queue<int> fuel;
       int count=0;
       // startFuel=0;
       s.push_back({target,0});
       sort(s.begin(),s.end(),comp);
       s.push_back({0,startFuel});
       sort(s.begin(),s.end(),comp);
       // startFuel-=s[1][0];
        for(int i=0;i<s.size();i++){
            if(i+1<s.size()){
                if(startFuel>=s[i+1][0]-s[i][0])
                {   
                    if(i!=0)
                    fuel.push(s[i][1]);
                startFuel-=(s[i+1][0]-s[i][0]);
                }
                else{
                    if(i!=0)
                    fuel.push(s[i][1]);
                    while(startFuel<s[i+1][0]-s[i][0]){
                        if(!fuel.empty()){
                            cout<<i<<endl;
                        count++;    
                        startFuel+=fuel.top();
                        fuel.pop();
                        }
                        else{
                            return -1;
                        }
                        
                    }
                    startFuel-=s[i+1][0]-s[i][0];
                }
            }
        }
       return count;
   }
};