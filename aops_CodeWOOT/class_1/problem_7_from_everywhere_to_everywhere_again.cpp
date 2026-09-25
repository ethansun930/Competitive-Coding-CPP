#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

struct Edge {
    int a, b;
    long long c;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M + N);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].c;
        edges[i].a--;
        edges[i].b--;
    }
    for (int i = 0; i < N; i++) {
        edges[i + M].a = N;
        edges[i + M].b = i;
        edges[i + M].c = 0;
    }
    vector<long long> d(N + 1, LLONG_MAX);
    d[N] = 0;
    for (int t = 0; t <= N; t++) {
        bool changed = false;
        for (int i = 0; i < (M + N); i++) {
            if (d[edges[i].a] == LLONG_MAX) {
                continue;
            }
            if (d[edges[i].a] + edges[i].c < d[edges[i].b]) {
                changed = true;
                d[edges[i].b] = d[edges[i].a] + edges[i].c;
            }
        }
        if (!changed) {
            break;
        }
    }
    vector<vector<pair<int, long long>>> adj(N);
    for (int i = 0; i < M; i++) {
        adj[edges[i].a].push_back({edges[i].b, edges[i].c + d[edges[i].a] - d[edges[i].b]});
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        vector<long long> dis(N, LLONG_MAX);
        dis[i] = 0;
        priority_queue<pair<long long, int>> pq;
        pq.push({0, i});
        while (!pq.empty()) {
            long long distance = -pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (distance > dis[node]) {
                continue;
            }
            for (pair<int, long long> edge : adj[node]) {
                if (dis[node] + edge.second >= dis[edge.first]) {
                    continue;
                }
                dis[edge.first] = edge.second + dis[node];
                pq.push({-dis[node] - edge.second, edge.first});
            }
        }
        for (int j = 0; j < N; j++) {
            ans += dis[j] + d[j] - d[i];
        }
    }
    cout << ans << '\n';
    return 0;
}