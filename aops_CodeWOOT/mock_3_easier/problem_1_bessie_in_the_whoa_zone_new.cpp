#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<utility>
#include<climits>
#include<algorithm>
using namespace std;

long long key(long long x, long long y, long long grav, long long N) {
    return (x * N + y) * 4 + grav;
}
pair<long long, long long> land(long long x, long long y, long long grav, vector<vector<long long>>& row, vector<vector<long long>>& col) {
    int new_x = x;
    int new_y = y;
    if (grav == 1) {
        auto it = upper_bound(row[y].begin(), row[y].end(), x);
        new_x = *it - 1;
    }
    else if (grav == 3) {
        auto it = upper_bound(row[y].begin(), row[y].end(), x);
        new_x = *(it - 1) + 1;
    }
    else if (grav == 0) {
        auto it = upper_bound(col[x].begin(), col[x].end(), y);
        new_y = *(it - 1) + 1;
    }
    else {
        auto it = upper_bound(col[x].begin(), col[x].end(), y);
        new_y = *it - 1;
    }
    return {new_x, new_y};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N, K, C, W;
    cin >> N >> K >> C >> W;
    vector<vector<long long>> row(N);
    vector<vector<long long>> col(N);
    for (long long i = 0; i < N; i++) {
        row[i].push_back(0);
        row[i].push_back(N - 1);
        col[i].push_back(0);
        col[i].push_back(N - 1);
    }
    for (long long i = 0; i < K; i++) {
        long long r, c;
        cin >> r >> c;
        row[r].push_back(c);
        col[c].push_back(r);
    }
    for (long long i = 0; i < N; i++) {
        sort(row[i].begin(), row[i].end());
        sort(col[i].begin(), col[i].end());
    }
    unordered_map<long long, long long> dis;
    dis[key(1, 1, 0, N)] = 0;
    priority_queue<pair<long long, long long>> pq;
    pq.push({0, key(1, 1, 0, N)});
    while (!pq.empty()) {
        pair<long long, long long> node = pq.top();
        pq.pop();
        if (dis[node.second] < -node.first) {
            continue;
        }
        long long grav = node.second % 4;
        node.second /= 4;
        long long y = node.second % N;
        node.second /= N;
        long long x = node.second;
        if (x == N - 2 && y == N - 2) {
            cout << -node.first << '\n';
            return 0;
        }
        long long new_grav = (grav + 1)%4;
        pair<long long, long long> new_pair = land(x, y, new_grav, row, col);
        long long new_key = key(new_pair.first, new_pair.second, new_grav, N);
        auto it = dis.find(new_key);
        long long cost = -node.first + (new_pair.first - x + new_pair.second - y) * (new_pair.first - x + new_pair.second - y) + W;
        if (it == dis.end() || cost < it->second) {
            dis[new_key] = cost;
            pq.push({-cost, new_key});
        }
        new_grav = (grav + 3)%4;
        new_pair = land(x, y, new_grav, row, col);
        new_key = key(new_pair.first, new_pair.second, new_grav, N);
        it = dis.find(new_key);
        cost = -node.first + (new_pair.first - x + new_pair.second - y) * (new_pair.first - x + new_pair.second - y) + C;
        if (it == dis.end() || cost < it->second) {
            dis[new_key] = cost;
            pq.push({-cost, new_key});
        }
    }
    long long ans = LLONG_MAX;
    for (int i = 0; i < 4; i++) {
        if (dis.find(key(N - 2, N - 2, i, N)) != dis.end()) {
            ans = min(ans, dis[key(N - 2, N - 2, i, N)]);
        }
    }
    cout << ans << '\n';
    return 0;
}