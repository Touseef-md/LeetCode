class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int result=0,i=0,j=people.size()-1;
        while(i<=j){
            if(people[j]==limit){
                result++;
                j--;
            }
            else if(people[i]+people[j]>limit){
                result++;
                j--;
            }
            else if(people[i]+people[j]<=limit){
                result++;
                i++;
                j--;
            }
            else if(i==j){
                result++;
                i++;
                j--;
            }
            
        }
        return result;
    }
};