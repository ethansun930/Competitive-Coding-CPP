#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<long long> starts(M + 1, 0);
    vector<long long> ends(M + 1, 0);
    for (long long i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        starts[x]++;
        ends[y]++;
    }
    vector<long long> sweeper(2 * M + 2);
    for (long long i = 0; i <= M; i++) {
        for (long long j = 0; j <= M; j++) {
            sweeper[i + j] += (starts[i] * starts[j]);
            sweeper[i + j + 1] -= (ends[i] * ends[j]);
        }
    }
    long long ans = 0;
    for (int i = 0; i <= 2 * M; i++) {
        ans += sweeper[i];
        cout << ans << '\n';
    }
    return 0;
}