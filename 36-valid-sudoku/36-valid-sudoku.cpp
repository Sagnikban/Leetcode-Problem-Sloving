class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& boards) {
        
        for(int i=0;i<boards.size();i++)
        {
            set<char>s;
            int c=0;
            for(int j=0;j<boards[0].size();j++)
            {
                if(boards[i][j]!='.')
                {
                    s.insert(boards[i][j]);
                    c++;
                }
               if(s.size()!=c)
               return false;    
            }
        }
    
      for(int i=0;i<boards.size();i++)
        {
            set<char>s;
            int c=0;
            for(int j=0;j<boards[0].size();j++)
            {
                if(boards[j][i]!='.')
                {
                    s.insert(boards[j][i]);
                    c++;
                }
            }
               if(s.size()!=c)
               return false;    
            
        }
        
        
         
            
        for(int i=0;i<boards.size();i+=3)
        {
            for(int j=0;j<boards[0].size();j+=3)
            {
             set<char>s;
              int c=0;
                
                for(int k=i;k<i+3;k++)
                {   
                    for(int q=j;q<j+3;q++)
                    {
                       
                  if(boards[k][q]!='.')
                 {
                    s.insert(boards[k][q]);
                    c++;
                 }
                        
                    }
                }
                
               if(s.size()!=c)
               return false;    
            
            }
        }
        
        
        return true;
    }
};