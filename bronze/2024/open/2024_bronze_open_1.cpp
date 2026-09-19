#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<bool>> s;
    for (int i = 0; i < N; i++) {
        string val;
        cin >> val;
        if (val == "true") {
            s.back().push_back(true);
        }
        if (val == "false") {
            s.back().push_back(false);
        }
        if (val == "or") {
            s.push_back({});
        }
    }
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
    }
}
/*
store them in groups seperated by or's and then for each section it is only true
if and only if it's all true
*/
