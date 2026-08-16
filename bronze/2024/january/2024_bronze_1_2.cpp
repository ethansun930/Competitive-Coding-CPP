#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    S--;
    vector<int> v(N);
    vector<int> q(N);
    for (int i = 0; i < N; i++) {
        cin >> q[i] >> v[i];
    }
    int curr = S;
    int power = 1;
    int dir = 1;
    int ans = 0;
    int time = 0;
    while (curr < N && curr >= 0 && time < 3 * N) {
        if (q[curr] == 0) {
            power += v[curr];
            dir = -dir;
        } else if (power >= v[curr] && v[curr] != -1) {
            ans++;
            v[curr] = -1;
        }
        time++;
        curr += power * dir;
    }
    cout << ans << '\n';
    return 0;
}