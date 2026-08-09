#include <iostream>
#include <vector>
using namespace std;

struct Flight {
    int c, r, d, s;
};
void DFS(vector<Flight>& flights, vector<int>& layover, vector<int>& ans, int l,
         int t) {
    if (ans[l] == -1) {
        ans[l] = t;
    } else {
        ans[l] = t;
    }
    for (int i = 0; i < flights.size(); i++) {
        if (flights[i].c == l && flights[i].r >= t + layover[l] &&
            (ans[flights[i].d] == -1 || ans[flights[i].d] > flights[i].s)) {
            DFS(flights, layover, ans, flights[i].d, flights[i].s);
        }
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<Flight> flights(M);
    for (int i = 0; i < M; i++) {
        cin >> flights[i].c >> flights[i].r >> flights[i].d >> flights[i].s;
        flights[i].c--;
        flights[i].d--;
    }
    vector<int> layover(N);
    for (int i = 0; i < N; i++) {
        cin >> layover[i];
    }
    layover[0] = 0;
    vector<int> ans(N, -1);
    DFS(flights, layover, ans, 0, 0);
    for (int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}