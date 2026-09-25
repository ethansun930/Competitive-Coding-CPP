#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int N, P;
    cin >> N >> P;
    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    vector<vector<int>> adj(P);
    vector<int> in(P, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < x[i]; j++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
            in[b]++;
        }
    }
    vector<int> q;
    bool mul = false;
    for (int i = 0; i < P; i++) {
        if (in[i] == 0) {
            q.push_back(i);
        }
    }
    vector<int> pattern(P);
    for (int t = 0; t < P; t++) {
        if (q.empty()) {
            cout << "NONE" << '\n';
            return;
        }
        if (q.size() > 1) {
            mul = true;
        }
        int i = q.back();
        q.pop_back();
        pattern[t] = i;
        int siz = adj[i].size();
        for (int j = 0; j < siz; j++) {
            in[adj[i][j]]--;
            if (in[adj[i][j]] == 0) {
                q.push_back(adj[i][j]);
            }
        }
    }
    if (mul) {
        cout << "MULTIPLE" << '\n';
        return;
    }
    cout << pattern[0] + 1;
    for (int i = 1; i < P; i++) {
        cout << ' ' << pattern[i] + 1;
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