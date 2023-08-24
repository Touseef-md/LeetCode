class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int remLen=0,sumi=0,spaceCount=0,flag1=0,lastLine=0;
        string temp="",temp2="";
        for(int i=0;i<words.size();i++){
            // cout<<" notmal "<<i<<endl;
            if(flag1==0){
                if(sumi+words[i].size()<=maxWidth){
                    temp+=words[i];
                    sumi+=words[i].size();
                    if(i==words.size()-1){
                        lastLine=1;
                        // result.push_back(temp);
                    }
                }
                else{
                    return {};
                }
                flag1=1;
            }
            else{
                // cout<<"TMEO "<<temp<<endl;
                if(sumi+words[i].size()+1<=maxWidth){
                    temp+=' ';
                    temp+=words[i];
                    spaceCount+=1;
                    sumi+=words[i].size()+1;
                    if(i==words.size()-1){
                        lastLine=1;
                        // result.push_back(temp);
                    }
                    // temp+=' ';
                }
                else{
                    // cout<<"ELSE i "<<i<<endl;
                    i--;
                    remLen=maxWidth-temp.size();
                    // cout<<remLen<<endl;
                    // cout<<remLen%spaceCount<<endl;
                    int flag2=0,sp,j=0;
                    string temp2="";
                    // sp=remLen%space
                    if(spaceCount==0){
                        // cout<<"SpCE COUNT 0"<<endl;
                        while(remLen>0){
                            temp+=' ';
                            remLen--;
                            j++;
                        }
                        // while(j<temp.size()){
                        //     temp2+=temp[j];
                        // }
                        result.push_back(temp);
                        temp="";
                        sumi=0;
                        spaceCount=0;
                        flag1=0;
                        continue;
                    }
                    sp=remLen/spaceCount;
                    while(j<temp.size()){
                            sp=remLen/spaceCount;
                            if(temp[j]==' '){
                                temp2+=' ';
                                while(sp--){
                                    temp2+=' ';
                                }
                            }
                            else{
                                temp2+=temp[j];
                            }
                        j++;
                    }
                    // cout<<temp2<<endl;
                    // cout<<"SFSD"<<endl;
                    temp=temp2;
                    sp=remLen%spaceCount;
                    // cout<<sp<<endl;
                    int k=0;
                    temp2="";
                    while(k<temp.size()-1&&sp>0){
                        // cout<<"WHILE working"<<endl;
                        if(temp[k]==' '&&temp[k+1]!=' '){
                            temp2+=' ';
                            temp2+=' ';
                            sp--;
                        }
                        else{
                            temp2+=temp[k];
                        }
                        k++;
                    }
                    while(k<temp.size()){
                        temp2+=temp[k];
                        k++;
                    }
                    // temp2+=temp[k];
                    result.push_back(temp2);
                    temp="";
                    sumi=0;
                    spaceCount=0;
                    flag1=0;
                }
            }
        }
        if(lastLine==1){
            int j=0;
            while(j<maxWidth){
                if(j>=temp.size()){
                    temp+=' ';
                }
                j++;
            }
        result.push_back(temp);
        }
        return result;
    }
};