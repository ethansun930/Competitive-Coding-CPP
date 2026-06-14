#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
bool works(int K, vector<int>& d, int T) {
    priority_queue<int, vector<int>, greater<int>> slot_times;
    for (int i = 0; i < d.size(); i++) {
        if (slot_times.size() < K) {
            slot_times.push(d[i]);
        }
        else {
            int next_avail = slot_times.top(); slot_times.pop();
            slot_times.push(next_avail + d[i]);
        }
    }
    int ans = 0;
    while (!slot_times.empty()) {
        ans = slot_times.top(); slot_times.pop();
    }
    return ans <= T;
}
int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    int N, T;
    cin >> N >> T;
    vector<int> d;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        d.push_back(a);
    }
    int left = 0; 
    int right = N + 1;
    while (left < right) {
        int middle = (left + right)/2;
        if (works(middle, d, T)) {
            right = middle;
        }
        else {
            left = middle + 1;
        }
    }
    cout << left;
    return 0;
}