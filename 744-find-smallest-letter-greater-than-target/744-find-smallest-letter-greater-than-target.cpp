class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        if(target>=letters[letters.size()-1])
       return letters[0];     
        return *upper_bound(letters.begin(),letters.end(),target);
    }
};