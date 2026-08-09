#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
    long long N, M, K;
    cin >> N >> M >> K;
    vector<pair<long long, long long>> weights(N);
    for (long long i = 0; i < N; i++) {
        cin >> weights[i].first >> weights[i].second;
    }
    sort(weights.begin(), weights.end());
    queue<pair<long long, long long>> q;
    q.push({LLONG_MAX, M});
    long long ans = 0;
    for (long long i = N - 1; i >= 0; i--) {
        long long wi = weights[i].first;
        long long ai = weights[i].second;
        while (!q.empty() && ai > 0) {
            pair<long long, long long> tower = q.front();
            long long weight = tower.first;
            long long amount = tower.second;
            if (weight < wi + K) {
                break;
            }
            int used = min(ai, amount);
            ai -= used;
            if (used == amount) {
                q.pop();
            } else {
                q.front().second -= used;
            }
        }
        if (weights[i].second > ai) {
            q.push({wi, weights[i].second - ai});
            ans += weights[i].second - ai;
        }
    }
    cout << ans << '\n';
    return 0;
}