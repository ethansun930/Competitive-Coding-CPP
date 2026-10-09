#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
#include<utility>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long sum = 0;
    vector<vector<long long>> adj(N, vector<long long>(N, LLONG_MAX));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long x;
            cin >> x;
            if (x > 0) {
                sum += x;
                adj[i][j] = min(adj[i][j], x);
                adj[j][i] = min(adj[j][i], x);
            }
            else {
                adj[i][j] = 0;
                adj[j][i] = 0;
            }
        }
    }
    long long ans = 0;
    vector<long long> visited(N, LLONG_MAX);
    visited[0] = 0;
    vector<bool> b_visited(N, false);
    priority_queue<pair<long long, int>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        int node = pq.top().second;
        long long d = -pq.top().first;
        pq.pop();
        if (visited[node] < d) {
            continue;
        }
        if (b_visited[node]) {
            continue;
        }
        b_visited[node] = true;
        ans += d;
        for (int i = 0; i < N; i++) {
            if (visited[i] <= adj[node][i]) {
                continue;
            }
            if (b_visited[i]) {
                continue;
            }
            visited[i] = adj[node][i];
            pq.push({-adj[node][i], i});
        }
    }
    cout << sum - ans << '\n';
    return 0;
}