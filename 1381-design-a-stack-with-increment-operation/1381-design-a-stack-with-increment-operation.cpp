class CustomStack {
public:
    vector<int> stack;
    int top=-1, n;
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(stack.size() < n){
            stack.push_back(x);
        }
    }
    
    int pop() {
        if(stack.size() > 0){
            int temp = stack.back();
            stack.pop_back();
            return temp;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<(k<stack.size() ? k : stack.size());i++){
            stack[i] += val;
        }
    }
};