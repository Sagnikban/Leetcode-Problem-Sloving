 int getNumber(string num) {
    int i,val=0;
    int start = 0;
    if(num.size()>0 && num[0]=='-'){
        start=1;
    }
    for(i=start;i<num.size();i++) {
        val = val*10+(num[i]-'0');    
    }
    if(start==1)
        return 0-val;
    return val;
}

bool isoperator(string c){
    return (c=="+"||c=="-"||c=="*"||c=="/");
}
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i,val1,val2; stack<string> op; stack<int> num; for(i=0;i<tokens.size();i++){ if(isoperator(tokens[i])){ op.push(tokens[i]); }else { num.push(getNumber(tokens[i])); } if(num.size()>=2 && op.size()>0) { val1 = num.top(); num.pop(); val2 = num.top(); num.pop(); if(op.top()=="+"){ val2 = val1+val2; } else if(op.top()=="-"){ val2 = val2-val1; } else if(op.top()=="*"){ val2 = val2*val1; } else { val2 = val2/val1; } num.push(val2); op.pop(); } } return num.top();
    }
};