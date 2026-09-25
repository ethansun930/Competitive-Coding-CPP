#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void DFS(int i, int parent, int& time, vector<vector<int>>& adj, vector<int>& dis, vector<int>& low, vector<bool>& vul) {
    dis[i] = time;
    low[i] = time;
    time++;
    int children = 0;
    for (int child : adj[i]) {
        if (child == parent) {
            continue;
        }
        if (dis[child] != -1) {
            low[i] = min(low[i], dis[child]);
        }
        else {
            children++;
            DFS(child, i, time, adj, dis, low, vul);
            low[i] = min(low[i], low[child]);
            if (i != 0 && low[child] >= dis[i]) {
                vul[i] = true;
            }
        }
    }
    if (i == 0 && children > 1) {
        vul[0] = true;
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> dis(N, -1);
    vector<int> low(N, -1);
    int time = 0;
    vector<bool> vul(N, false);
    DFS(0, -1, time, adj, dis, low, vul);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (vul[i]) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}