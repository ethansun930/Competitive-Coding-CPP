#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(vector<int>& milk, vector<vector<int>>& adj, vector<int>& markers,
         int mark, int i) {
    if (markers[i] != 0) {
        return;
    }
    markers[i] = mark;
    for (const int& neighbor : adj[i]) {
        if (milk[neighbor] == milk[i]) {
            dfs(milk, adj, markers, mark, neighbor);
        }
    }
    return;
}
int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    string cows;
    cin >> cows;
    vector<int> milk(N);
    for (int i = 0; i < N; i++) {
        if (cows[i] == 'G') {
            milk[i] = 0;
        } else {
            milk[i] = 1;
        }
    }
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> markers(N, 0);
    int mark = 1;
    for (int i = 0; i < N; i++) {
        if (markers[i] == 0) {
            dfs(milk, adj, markers, mark, i);
            mark++;
        }
    }
    vector<vector<int>> farmers(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (c == 'G') {
            farmers[i] = {a, b, 0};
        } else {
            farmers[i] = {a, b, 1};
        }
    }
    for (int i = 0; i < M; i++) {
        if (markers[farmers[i][0]] != markers[farmers[i][1]]) {
            cout << 1;
        } else if (milk[farmers[i][0]] == farmers[i][2]) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << '\n';
    return 0;
}
