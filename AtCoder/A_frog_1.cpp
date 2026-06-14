#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int abs(int n) {
    if (n >= 0) {
        return n;
    }
    return -n;
}
int take_care(vector<int>& h, vector<int>& costs, vector<bool>& ready, int i) {
    if (i <= 0) {
        return 0;
    }
    if (i == 1) {
        return abs(h[1] - h[0]);
    }
    if (ready[i]) {
        return costs[i];
    }
    int prev = take_care(h, costs, ready, i - 1);
    int oprev = take_care(h, costs, ready, i - 2);
    int ans = min(prev + abs(h[i] - h[i - 1]), oprev + abs(h[i] - h[i - 2]));
    costs[i] = ans;
    ready[i] = true;
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> costs(n, 0);
    vector<bool> ready(n, false);
    cout << take_care(h, costs, ready, n - 1) << '\n';
}