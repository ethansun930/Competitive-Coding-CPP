#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solve() {
    int N, X, S;
    cin >> N >> X >> S;
    if (X == 1) {
        vector<vector<int>> adj(N);
        vector<int> indegree(N, 0);
        for (int i = 0; i < S; i++) {
            int l;
            cin >> l;
            vector<int> nums(l);
            for (int i = 0; i < l; i++) {
                cin >> nums[i];
                nums[i]--;
            }
            for (int i = 1; i < l; i++) {
                adj[nums[i - 1]].push_back(nums[i]);
                indegree[nums[i]]++;
            }
        }
        priority_queue<int> sources;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                sources.push(-i);
            }
        }
        vector<int> pattern;
        for (int i = 0; i < N; i++) {
            if (sources.empty()) {
                cout << "IMPOSSIBLE" << '\n';
                return;
            }
            int source = -sources.top();
            sources.pop();
            pattern.push_back(source);
            for (const int& j : adj[source]) {
                if (indegree[j] != 0) {
                    indegree[j]--;
                    if (indegree[j] == 0) {
                        sources.push(-j);
                    }
                }
            }
        }
        cout << pattern[0] + 1;
        for (int i = 1; i < N; i++) {
            cout << ' ' << pattern[i] + 1;
        }
        cout << '\n';
        return;
    }
    vector<int> next(N, -1);
    vector<int> prev(N, -1);
    bool ok = true;
    for (int i = 0; i < S; i++) {
        int l;
        cin >> l;
        vector<int> nums(l);
        for (int i = 0; i < l; i++) {
            cin >> nums[i];
            nums[i];
            nums[i]--;
        }
        for (int i = 1; i < l; i++) {
            if (!ok) {
                break;
            }
            if (prev[nums[i]] != nums[i - 1] && prev[nums[i]] != -1) {
                ok = false;
                break;
            }
            prev[nums[i]] = nums[i - 1];
            if (next[nums[i - 1]] != nums[i] && next[nums[i - 1]] != -1) {
                ok = false;
                break;
            }
            next[nums[i - 1]] = nums[i];
        }
    }
    if (!ok) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        if (prev[i] != -1) {
            continue;
        }
        ans.push_back(i);
        int curr = i;
        while (next[curr] != -1) {
            curr = next[curr];
            ans.push_back(curr);
        }
    }
    if (ans.size() < N) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    cout << ans[0] + 1;
    for (int i = 1; i < N; i++) {
        cout << ' ' << ans[i] + 1;
    }
    cout << '\n';
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
/*
5 -> 1 -> 2
4 -> 6
3
*/