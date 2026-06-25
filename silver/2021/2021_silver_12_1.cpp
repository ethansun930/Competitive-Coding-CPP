#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int K, M, N;
    cin >> K >> M >> N;
    vector<pair<long long, long long>> grass(K);
    for (int i = 0; i < K; i++) {
        cin >> grass[i].first >> grass[i].second;
    }
    vector<long long> f(M);
    for (int i = 0; i < M; i++) {
        cin >> f[i];
    }
    sort(grass.begin(), grass.end());
    sort(f.begin(), f.end());
    vector<vector<pair<long long, long long>>> intervals(M + 1);
    int j = 0;
    for (int i = 0; i < M; i++) {
        while (grass[j].first < f[i]) {
            intervals[i].push_back(grass[j]);
            j++;
        }
    }
    while (j < K) {
        intervals[M].push_back(grass[j]);
        j++;
    }
    vector<long long> values;
    long long val_1 = 0;
    long long val_2 = 0;
    for (int i = 0; i <= M; i++) {
        val_1 = 0;
        val_2 = 0;
        if (i == 0 || i == M) {
            for (int j = 0; j < intervals[i].size(); j++) {
                val_1 += intervals[i][j].second;
            }
            values.push_back(val_1);
            values.push_back(0);
            // cout << val_1 << ' ' << val_2 << ' ' << i << '\n';
            continue;
        }
        int l = 0;
        int r = 0;
        long long curr = 0;
        while (l < intervals[i].size()) {
            while (r < intervals[i].size() &&
                   (((2 * intervals[i][r].first) -
                     (2 * intervals[i][l].first)) < (f[i] - f[i - 1]))) {
                curr += intervals[i][r].second;
                r++;
            }
            val_1 = max(val_1, curr);
            curr -= intervals[i][l].second;
            l++;
        }
        values.push_back(val_1);
        for (int j = 0; j < intervals[i].size(); j++) {
            val_2 += intervals[i][j].second;
        }
        values.push_back(val_2 - val_1);
        // cout << val_1 << ' ' << val_2 << ' ' << i << '\n';
    }
    sort(values.begin(), values.end());
    reverse(values.begin(), values.end());
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += values[i];
    }
    cout << ans << '\n';
    return 0;
}
/*
0, 0, N, N, 0, N, 0, N, 0 , 0, 0 , N , 0 , 0
0, 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12, 13
4, 0, 0, 0, 6, 0, 0, 0, 10, 0, 8 , 0 , 12, 14
*/