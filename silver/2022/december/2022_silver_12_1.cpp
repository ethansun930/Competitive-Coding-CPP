#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void dfs(long long node, long long parent, vector<long long>& h,
         vector<vector<long long>>& adj, long long& ans,
         vector<vector<long long>>& positive_moves,
         vector<vector<long long>>& negative_moves) {
    if (adj[node].size() == 1 && node != 0) {
        return;
    }
    for (const long long& child : adj[node]) {
        if (child == parent) {
            continue;
        }
        dfs(child, node, h, adj, ans, positive_moves, negative_moves);
        if (h[child] > 0) {
            positive_moves.push_back({child + 1, node + 1, h[child]});
            h[node] += h[child];
            h[child] = 0;
            ans++;
        } else if (h[child] < 0) {
            negative_moves.push_back({node + 1, child + 1, -h[child]});
            h[node] += h[child];
            h[child] = 0;
            ans++;
        }
    }
    return;
}
int main() {
    int N;
    cin >> N;
    vector<long long> h(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
        sum += h[i];
    }
    for (int i = 0; i < N; i++) {
        h[i] -= (sum / N);
    }
    vector<vector<long long>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        long long x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long ans = 0;
    vector<vector<long long>> positive_moves;
    vector<vector<long long>> negative_moves;
    dfs(0, -1, h, adj, ans, positive_moves, negative_moves);
    cout << ans << '\n';
    for (long long i = 0; i < positive_moves.size(); i++) {
        cout << positive_moves[i][0] << ' ' << positive_moves[i][1] << ' '
             << positive_moves[i][2] << '\n';
    }
    for (long long i = negative_moves.size() - 1; i >= 0; i--) {
        cout << negative_moves[i][0] << ' ' << negative_moves[i][1] << ' '
             << negative_moves[i][2] << '\n';
    }
    return 0;
}