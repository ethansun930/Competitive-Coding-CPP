#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    int sqrtn = sqrt(N);
    long long ans = 0;
    vector<long long> pieces(N/sqrtn + 1, 0);
    vector<bool> avail(N, false);
    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;
        s--;
        int jumped = 0;
        while (jumped < s/sqrtn) {
            ans += pieces[jumped];
            jumped++;
        }
        for (int j = jumped * sqrtn; j < s; j++) {
            if (avail[j]) {
                ans++;
            }
        }
        avail[s] = true;
        pieces[s/sqrtn]++;
    }
    cout << ans << '\n';
    return 0;
}