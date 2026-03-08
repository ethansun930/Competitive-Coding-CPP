#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> ids(N);
    vector<int> sums(N+1);
    sums[0] = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        ids[i] = x%7;
        sums[i+1] = (sums[i] + ids[i])%7;
    }
    int ans = 0;
    for (int i = 0 ; i < 7; i++) {
        int first = N;
        int last = 0;
        for (int j = 0 ; j < N+1; j++) {
            if (sums[j] == i) {
                first = min(first, j);
                last = max(last, j);
            }
        }
        if (first <= last) {
            ans = max(ans, last - first);
            // cout << first << " " << last << " " << i << "\n";
        }
    }
    // for (int x : sums) {
    //     cout << x << "\n";
    // }
    cout << ans << "\n";
    return 0;
}
/*
0
3
1
2
1
3
3
6
*/