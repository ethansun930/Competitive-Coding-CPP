#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& a, vector<int>& markings, int mark, int i) {
    if (markings[i] != 0) {
        return;
    }
    markings[i] = mark;
    dfs(a, markings, mark, a[i]);
}
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<long long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> v[i];
        a[i]--;
    }
    vector<int> markings(N, 0);
    int mark = 1;
    for (int i = 0; i < N; i++) {
        if (markings[i] == 0) {
            dfs(a, markings, mark, i);
            mark++;
        }
    }
    mark--;
    vector<long long> mins(mark, INT_MAX);
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += v[i];
        mins[markings[i] - 1] = min(mins[markings[i] - 1], v[i]);
    }
    for (int i = 0; i < mark; i++) {
        ans -= mins[i];
    }
    cout << ans << '\n';
    return 0;
}