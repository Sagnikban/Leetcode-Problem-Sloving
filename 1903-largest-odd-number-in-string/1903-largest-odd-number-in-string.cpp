class Solution {
public:
    string largestOddNumber(string num) {
        
        for(int i=num.length()-1;i>=0;i--)
        {
            int x= int(num[i]);
           
            
            if(x%2==1)
            return num.substr(0,i+1);    
        }    
        
        return "";
    }
};