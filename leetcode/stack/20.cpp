#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> past;
        unordered_map<char, char> left_right = {
            {'(', ')'}, {'[', ']'}, {'{', '}'}};
        unordered_set<char> left = {'(', '[', '{'};
        for (int i = 0; i < s.size(); i++) {
            if (left.find(s[i]) != left.end()) {
                past.push(s[i]);
            } else if (!past.empty() && (left_right[past.top()] == s[i])) {
                past.pop();
            } else {
                return false;
            }
        }
        return past.empty();
    }
};