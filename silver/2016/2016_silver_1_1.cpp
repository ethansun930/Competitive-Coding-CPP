#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
bool work(int power, int K, vector<int>& x) {
    int amount_left = x.size() - 1;
    while (K > 0 && amount_left >= 0) {
        K--;
        int blast_loc = x[amount_left] - 2 * power;
        while (amount_left >= 0 && x[amount_left] >= blast_loc) {
            amount_left--;
        }
    }
    if (amount_left == -1) {
        return true;
    }
    return false;
}
int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    vector<int> x;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        x.push_back(a);
    }
    sort(x.begin(), x.end());
    int left = 0;
    int right = (x[N - 1] - x[0]) / 2 + 1;
    while (left < right) {
        int middle = (left + right) / 2;
        // cout << "middle" << middle << '\n';
        if (work(middle, K, x)) {
            right = middle;
            // cout << "right" << right << '\n';
        } else {
            left = middle + 1;
            // cout << "left" << left << '\n';
        }
    }
    cout << left << '\n';
    return 0;
}