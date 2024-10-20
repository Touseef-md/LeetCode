class Solution {
public:
    
    bool parseBoolExpr(string expression) {
        stack<char> str;
        stack<char> operations;
        char operation;
        char chrVal;
        bool val, currVal;
        // int flag = 0;
        
        for(int i=0; i<expression.length();i++){
            if(expression[i]=='('||expression[i]==',')
                continue;
            if(expression[i]==')'){
                char temp = operations.top();
                operations.pop();
                if( temp  == '|'){
                    val = false;
                }
                else if ( temp == '&'){
                    val = true;
                }
                while(str.top()!=temp){
                    chrVal = str.top();
                    currVal = chrVal =='f'?false:true;
                    if(temp=='|'){
                        val |= currVal;
                    }
                    else if ( temp == '&'){
                        val &= currVal;
                    }
                    else if ( temp =='!'){
                        val = ! currVal;
                    }
                    str.pop();
                }
                str.pop();
                str.push(val==true?'t':'f');
            }
            else{
                str.push(expression[i]);
                if(expression[i]=='!'||expression[i]=='&'||expression[i]=='|'){
                    operations.push(expression[i]);
                }
            }
        }
        return str.top()=='t'?true:false;
        
    }
};