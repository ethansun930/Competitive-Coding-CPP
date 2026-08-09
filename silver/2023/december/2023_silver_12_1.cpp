#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<pair<int, int>> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i].first >> weights[i].second;
    }
    sort(weights.begin(), weights.end());
    priority_queue<pair<int, int>> pq;
    long long ans = 0;
    pq.push({INT_MAX, M});
    while (!pq.empty()) {
        int tower = pq.top().first;
        int amount = pq.top().second;
        pq.pop();
        for (int i = weights.size() - 1; i >= 0; i--) {
            if (weights[i].first + K > tower ||
                (i == weights.size() - 1 && weights[i].second == 0)) {
                weights.pop_back();
                continue;
            }
            if (amount > 0) {
                int used = min(weights[i].second, amount);
                pq.push({weights[i].first, used});
                amount -= used;
                weights[i].second -= used;
                ans += used;
            }
            if (amount == 0) {
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}