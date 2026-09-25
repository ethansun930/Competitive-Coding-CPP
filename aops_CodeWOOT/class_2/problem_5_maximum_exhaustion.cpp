#include<iostream>
#include<vector>
#include<climits>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, long long>>> adj(N);
    vector<int> indegree(N, 0);
    for (int i = 0; i < M; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
        indegree[b]++;
    }
    vector<int> top_sort(N);
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    for (int i = 0; i < N; i++) {
        int j = q.front();
        q.pop();
        top_sort[i] = j;
        for (pair<int, long long> e : adj[j]) {
            indegree[e.first]--;
            if (indegree[e.first] == 0) {
                q.push(e.first);
            }
        }
    }
    vector<long long> dis(N, LLONG_MIN);
    dis[0] = 0;
    for (int i = 0; i < N; i++) {
        if (dis[top_sort[i]] == LLONG_MIN) {
            continue;
        }
        for (pair<int, long long> e : adj[top_sort[i]]) {
            dis[e.first] = max(dis[e.first], dis[top_sort[i]] + e.second);
        }
    }
    cout << dis[N - 1] << '\n';
    return 0;
}