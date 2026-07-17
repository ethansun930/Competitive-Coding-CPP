#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool check_ranges(vector<vector<int>>& ranges, vector<int> a, int i) {
    int curr_min = a[i];
    int curr_max = a[i];
    for (int j = i - 1; j >= 0; j--) {
        curr_min = min(curr_min, a[j]);
        curr_max = max(curr_max, a[j]);
        if (curr_max - curr_min != ranges[i][j]) {
            return false;
        }
    }
    return true;
}
int main() {
    int N;
    cin >> N;
    vector<vector<int>> ranges(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            cin >> ranges[i][j];
            ranges[j][i] = ranges[i][j];
        }
    }
    vector<int> a(N);
    a[0] = 0;
    for (int i = 1; i < N; i++) {
        a[i] = a[i - 1] + ranges[i][i - 1];
        if (!check_ranges(ranges, a, i)) {
            a[i] = a[i - 1] - ranges[i][i - 1];
        }
    }
    for (int i = 0; i < N; i++) {
        if (i > 0) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}