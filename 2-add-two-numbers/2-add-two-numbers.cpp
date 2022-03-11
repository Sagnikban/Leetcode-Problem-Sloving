/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
**/
class Solution {
public:
        string findSum(string str1, string str2){
    
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}
ListNode* convertStringToLL(string s)
{
   
    if(s.size() == 0) return NULL;

  ListNode* tmp=new ListNode(int(s[0])-48); 
  ListNode* ans=tmp;  
  
  for(int k=1;k<s.size();k++)
  {
  tmp->next= new ListNode(int(s[k])-48);
  tmp=tmp->next;
  }
return ans;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            string list1,list2;
            ListNode* temp = l1;
            ListNode* temp1 = l2;
            
            while(temp!=NULL){
                    string v = to_string(temp->val);
                    list1.append(v);
                    temp = temp->next;
            }
            while(temp1!=NULL){
                    string v = to_string(temp1->val);
                    list2.append(v);
                    temp1 = temp1->next;
            }
 
            reverse(list1.begin(),list1.end());
           reverse(list2.begin(),list2.end());
            string res = findSum(list1,list2);
      
            reverse(res.begin(),res.end());
            
            return convertStringToLL(res);
            
            
        
    }
};