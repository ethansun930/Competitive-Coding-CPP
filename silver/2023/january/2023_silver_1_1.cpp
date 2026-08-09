#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int order(char i) {
    if (('a' <= i) && (i <= 'z')) {
        return (i - 'a');
    }
    return (i - 'A' + 26);
}
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string x, y;
        cin >> x >> y;
        if (x == y) {
            cout << 0 << '\n';
            continue;
        }
        vector<int> adj(52, -1);
        unordered_set<int> characters;
        bool ok = true;
        for (int i = 0; i < x.size(); i++) {
            characters.insert(order(y[i]));
            if (adj[order(x[i])] == -1) {
                adj[order(x[i])] = order(y[i]);
            } else if (adj[order(x[i])] != order(y[i])) {
                cout << -1 << '\n';
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        int ans = 0;
        int cycles = 0;
        vector<int> in_degree(52, 0);
        for (int i = 0; i < 52; i++) {
            if (adj[i] != -1 && adj[i] != i) {
                in_degree[adj[i]]++;
            }
        }
        vector<int> visited(52, 0);
        for (int i = 0; i < 52; i++) {
            if (adj[i] != -1 && adj[i] != i) {
                ans++;
            }
            if (visited[i] == 0) {
                int curr = i;
                vector<int> path;
                while (curr != -1 && adj[curr] != curr && visited[curr] == 0) {
                    path.push_back(curr);
                    visited[curr] = 1;
                    curr = adj[curr];
                }
                if (curr != -1 && adj[curr] != curr && visited[curr] == 1) {
                    bool pure_cycle = true;
                    int cycle_node = curr;
                    do {
                        if (in_degree[cycle_node] > 1) {
                            pure_cycle = false;
                        }
                        cycle_node = adj[cycle_node];
                    } while (cycle_node != curr);
                    if (pure_cycle) {
                        cycles++;
                        ans++;
                    }
                }
                for (const int& i : path) {
                    visited[i] = 2;
                }
            }
        }
        if (cycles > 0 && characters.size() == 52) {
            cout << -1 << '\n';
            continue;
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
split into components:
for each component:
    case 1 (No cycle):
        k nodes, k - 1
    case 2 (Pure cycle):
        if haven't used all characters:
            k nodes, k + 1
        else:
            return -1, not solvable.
    case 3 (Not pure cycle):
        k nodes, k.
*/