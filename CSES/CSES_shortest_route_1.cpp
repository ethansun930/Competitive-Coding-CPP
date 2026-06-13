#include <functional>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> adjacency(n);
    for (int i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adjacency[a].push_back(make_pair(b, c));
    }
    vector<long long> distance(n, -1);
    unordered_set<long long> visited;
    distance[0] = 0;
    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>,
                   greater<pair<long long, long long>>>
        pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        pair<long long, long long> nod = pq.top();
        pq.pop();
        long long node = nod.second;
        long long d_node = nod.first;
        if (visited.find(node) != visited.end()) {
            continue;
        }
        visited.insert(node);
        for (pair<long long, long long>& edge : adjacency[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            if (distance[neighbor] == -1 ||
                d_node + weight < distance[neighbor]) {
                distance[neighbor] = d_node + weight;
                pq.push(make_pair(distance[neighbor], neighbor));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << distance[i] << ' ';
    }
    cout << '\n';
    return 0;
}
