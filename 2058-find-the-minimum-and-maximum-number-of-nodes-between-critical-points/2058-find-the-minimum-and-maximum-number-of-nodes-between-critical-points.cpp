/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* temp=head;
        ListNode* prev=NULL;
        
        int min_distance=INT_MAX,max_distance=INT_MIN;
        int c=0;
        vector<int>res,ans;
        int n=0;
        
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }
        
        temp=head;
        
        while(temp!=NULL)
        {
            c++;
            if(c!=1 && c!=n)
            {
            if(temp->val > temp->next->val && temp->val > prev->val)
            {
                ans.push_back(c);
            }
            else if( 
               temp->val < temp->next->val && temp->val < prev->val)
            {
              
                ans.push_back(c);
            }
            }
            
            prev=temp;
            temp=temp->next;
        }
        
        for(int i=0;i<ans.size();i++)
           cout<<ans[i]<<" " ;
        
        if(ans.size()<=1)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]-ans[i-1]<min_distance)
            min_distance=ans[i]-ans[i-1];   
        }
        
        max_distance =ans[ans.size()-1]-ans[0];
        
        res.push_back(min_distance);
        res.push_back(max_distance);
        
        return res;
        
    }
};