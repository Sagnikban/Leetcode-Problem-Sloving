class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       
        stack<int>st;
        for(int i=0;i<asteroids.size();i++)
      {
          if(st.empty())
          st.push(asteroids[i]); 
          else if(st.top()>0 && asteroids[i]<0)
          {
              cout<<asteroids[i]<<endl;
              int x=st.top();
              cout<<x<<endl;
              st.pop();
              if(abs(x)==abs(asteroids[i]))
              continue;
              else
              if(abs(x)>abs(asteroids[i]))
              st.push(x);
              else if(abs(x)<abs(asteroids[i]))
              {
                cout<<"Aloo"<<endl;
                st.push(asteroids[i]); 
              }
              
              if(st.size()==1)
              {
                  cout<<"Potol"<<endl;
                  continue;
              }
                
                  
             if(!st.empty()) 
             {
              while(st.top()<0)
              {
                 int x=st.top();
                 st.pop();
                 int y=st.top();
                  st.pop();
                  if(x<0 && y<0)
                  {

                      st.push(y);
                      st.push(x);
                      break;
                  }   
                  else
                 if(abs(x)==abs(y))
                 {
                     break;
                 }
                 else
                 if(abs(x)>abs(y))
                 st.push(x);
                 else if(abs(y)>abs(x))
                  st.push(y);  
                  
                  if(st.size()==1)
                  break;    
              }  
             }
          }  
            else
            st.push(asteroids[i]);
            
        }
           
            vector<int>v;
           if(st.empty())
           return v;    
            while(!st.empty())
            {
                v.push_back(st.top());
                st.pop();
            }
            reverse(v.begin(),v.end());
            return v;
      
    }
};