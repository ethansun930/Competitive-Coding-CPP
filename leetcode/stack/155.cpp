#include <vector>
using namespace std;

class MinStack {
   public:
    vector<int> s;
    vector<int> mins;
    MinStack() {
        s = vector<int>();
        mins = vector<int>();
    }

    void push(int val) {
        s.push_back(val);
        if (mins.empty() || val <= mins.back()) {
            mins.push_back(val);
        }
    }

    void pop() {
        if (s.back() == mins.back()) {
            mins.pop_back();
        }
        s.pop_back();
    }

    int top() { return s.back(); }

    int getMin() { return mins.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */