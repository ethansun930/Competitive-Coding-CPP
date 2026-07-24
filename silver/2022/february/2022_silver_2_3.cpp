#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

void solve() {
    int M, N, K;
    cin >> M >> N >> K;
    vector<int> f(N);
    vector<int> amount_left(M, 0);
    for (int i = 0; i < N; i++) {
        cin >> f[i];
        f[i]--;
        amount_left[f[i]]++;
    }
    vector<bool> filed(N, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        process;
    int first_folder = 0;
    int first_email = 0;
    int last_email = K - 1;
    for (int i = 0; i < K; i++) {
        process.push({f[i], i});
    }
    while (first_folder < M && last_email < (N - 1)) {
        if (amount_left[first_folder] == 0) {
            first_folder++;
            continue;
        }
        while (!process.empty()) {
            if (process.top().second < first_email ||
                filed[process.top().second]) {
                process.pop();
            } else {
                break;
            }
        }
        if (!process.empty() && (process.top().first < (first_folder + K))) {
            int filer = process.top().second;
            process.pop();
            filed[filer] = true;
            amount_left[f[filer]]--;
            last_email++;
            process.push({f[last_email], last_email});
            while (first_email <= last_email && filed[first_email]) {
                first_email++;
            }
        } else {
            first_email++;
            last_email++;
            while (first_email <= last_email && filed[first_email]) {
                first_email++;
            }
            process.push({f[last_email], last_email});
        }
    }
    while (first_folder < M) {
        if (amount_left[first_folder] == 0) {
            first_folder++;
            continue;
        }
        while (!process.empty()) {
            if (process.top().second < first_email ||
                filed[process.top().second]) {
                process.pop();
            } else {
                break;
            }
        }
        if (process.empty()) {
            cout << "NO" << '\n';
            return;
        }
        int filer = process.top().second;
        process.pop();
        if (f[filer] >= (first_folder + K)) {
            cout << "NO" << '\n';
            return;
        }
        filed[filer] = true;
        amount_left[f[filer]]--;
        while (first_email > 0 && filed[first_email]) {
            first_email--;
        }
        process.push({f[first_email], first_email});
    }
    cout << "YES" << '\n';
}
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
