#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> adjacency(2 * n);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;
        adjacency[a].push_back(make_pair(b, c));
        adjacency[a].push_back(make_pair(b + n, c / 2));
        adjacency[a + n].push_back(make_pair(b + n, c));
    }
    vector<long long> distance(2 * n, -1);
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
    cout << distance[2 * n - 1] << '\n';
    return 0;
}
