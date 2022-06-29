class Solution {
public:
    int findParent(int x, unordered_map<int, int> &parent){
        if(x == parent[x])return x; 
        return parent[x] = findParent(parent[x], parent); 
    }
    
    void unify(int x, int y , unordered_map<int, int> &parent){
        int px = findParent(x, parent), py = findParent(y, parent); 
        if(px == py)return ; 
        parent[py] = px; 
    }
    
    bool equationsPossible(vector<string>& equations) {
        unordered_map<int, int> parent;
        for(auto eqn : equations){
            parent[(int)eqn[0]] = (int)(eqn[0]); 
            parent[(int)eqn[3]] = (int)(eqn[3]); 
            
        }
        for(auto eqn : equations){
            if(eqn[1] == '=')
                unify((int)eqn[0], (int)eqn[3], parent); 
        }
        
        for(auto eqn : equations){
            if(eqn[1] == '!' && findParent((int)eqn[0], parent) == findParent((int)eqn[3], parent)){
                return false; 
            }
        }
        return true; 
    }
};