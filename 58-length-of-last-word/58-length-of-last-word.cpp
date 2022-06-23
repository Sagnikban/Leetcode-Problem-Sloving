class Solution {
public:
    int lengthOfLastWord(string s) {
          
        int x;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]>=97 && s[i]<=122)
            {
               x=i;
               break; 
            }    
           
            if(s[i]>=65 && s[i]<=90)
            {
               x=i;
               break; 
            }    
        }  
        
        int c=0;
        for(int j=x;j>=0;j--)
        {
           
            if(s[j]==' ')
            break;    
             c++;
        }   
        
        return  c;
            
    }
};