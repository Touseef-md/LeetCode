class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0,last_indx=tokens.size()-1;
        vector<int> flag(tokens.size(),0);
        for(int i=0;i<tokens.size();){
            if(i==0&&tokens[i]>power)
                break;
            if(tokens[i]<=power&&!flag[i]){
                score++;
                power-=tokens[i];
                i++;
            }
            else if(last_indx<=i)
                break;
            else{
                // flag[i]=1;
                if(!flag[last_indx]){
                    flag[last_indx]=1;
                    score--;
                    power+=tokens[last_indx];
                    last_indx--;
                }
            }
            // if(last_indx<i){
            //     break;
            // }
        }
        return score;
        
    }
};