class Solution {
public:
//     int parse(string& st,int i,int j){
        
//     }
    int compareVersion(string version1, string version2) {
        version1+='.';
        version2+='.';
        int i=0,j=0,k,l,m=version1.size(),n=version2.size();
        int num1,num2;
        while(i<m&&j<n){
            k=i;
            l=j;
            while(i<m&&version1[i]!='.'){
                i++;
            }
            // whi
            while(j<n&&version2[j]!='.'){
                j++;
            }
            num1=stoi(version1.substr(k,i));
            num2=stoi(version2.substr(l,j));
            if(num1>num2){
                return 1;
            }
            else if(num1==num2){
                i++;
                j++;
            }
            else{
                return -1;
            }
        }
        while(i<m){
            k=i;
            while(i<m&&version1[i]!='.'){
                i++;
            }
            num1=stoi(version1.substr(k,i));
            if(num1>0){
                return 1;
            }
            else{
                i++;
            }
            
        }
        while(j<n){
            l=j;
            while(j<n&&version2[j]!='.'){
                j++;
            }
            num2=stoi(version2.substr(l,j));
            if(num2>0)
                return -1;
            else{
                j++;
            }
        }
        return 0;
//             while(i<m&&version1[i]=='0')
//                 i++;
//             while(j<n&&version2[j]=='0')
//                 j++;
//         while(i<m&&j<n){
//             if(i<m&&j<n&&version1[i]=='.'&&version2[j]=='.'){
//                 i++;
//                 j++;
//                 while(i<m&&version1[i]=='0')
//                     i++;
//                 while(j<n&&version2[j]=='0')
//                     j++;
//             }
//             else if(i<m&&j<n&&version1[i]>version2[j]){
//                 cout<<"Fsdrs"<<endl;
//                 return 1;
//             }
//             else if(i<m&&j<n&&version1[i]==version2[j]){
//                 i++;j++;
//             }
//             else if(i<m&&j<n&&version1[i]<version2[j]){
//                 // cout<<"Firesr"<<endl;
//                 return -1;
//             }
            
//         }
//         // cout<<i<<" "<<j<<endl;
//         while(i<m){
//             if(i<m&&version1[i]=='.'){
//                 i++;
//                 while(i<m&&version1[i]=='0'){
//                     i++;
//                 }
//             }
//             else if(i<m){
//                 return 1;
//             }
//         }
//         while(j<n){
//             if(j<n&&version2[j]=='.'){
//                 j++;
//                 while(j<n&&version2[j]=='0'){
//                     j++;
//                 }
//             }
//             else if(j<n){
//                 // cout<<"f'sfsd"<<endl;
//                 return -1;
//             }
//         }
//         return 0;
    }
};