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
int take_care(vector<int>& h, vector<int>& costs, vector<bool>& ready, int i,
              int k) {
    if (i <= 0) {
        return 0;
    }
    if (i < k) {
        return abs(h[i] - h[0]);
    }
    if (ready[i]) {
        return costs[i];
    }
    int ans = 2147483647;
    for (int j = 1; j <= k; j++) {
        int prev = take_care(h, costs, ready, i - j, k);
        ans = min(ans, prev + abs(h[i] - h[i - j]));
    }
    costs[i] = ans;
    ready[i] = true;
    return ans;
}
int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> costs(n, 0);
    vector<bool> ready(n, false);
    cout << take_care(h, costs, ready, n - 1, k) << '\n';
}