#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<long long, long long>> R(N);
    for (int i = 0; i < N; i++) {
        cin >> R[i].second >> R[i].first;
    }
    sort(R.begin(), R.end());
    long long ans = 0;
    priority_queue<long long> pq;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (i >= K - 1) {
            ans = max(ans, R[i].first * R[i].first + 2 * R[i].first * R[i].second + sum);
        }
        sum += 2 * R[i].first * R[i].second;
        pq.push(-2 * R[i].first * R[i].second);
        if (i >= K - 1) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}