class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0,count=0,flag=0;
        string st="";
        while(count<word1.size()+word2.size()){
            flag=0;
            if(count%2==0&&i<word1.size()){
                st+=word1[i++];
                flag=1;
            }
            else{
                if(j<word2.size()){
                    st+=word2[j++];
                    flag=1;
                }
            }
            if(flag==0)
                break;
            count++;
        }
        while(i<word1.size()){
            st+=word1[i];
            i++;
        }
        while(j<word2.size()){
            st+=word2[j];
            j++;
        }
        return st;
    }
};