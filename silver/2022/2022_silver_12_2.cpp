#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    vector<bool> is_prime(5000001, true);
    for (int i = 1; i < 5000001; i++) {
        if (!is_prime[i]) {
            continue;
        }
        if (i == 1) {
            continue;
        }
        for (int j = (2 * i); j < 5000000; j += i) {
            is_prime[j] = false;
        }
    }
    vector<pair<int, int>> win(5000000);
    win[0] = make_pair(0, 1);
    for (int i = 1; i < 5000000; i++) {
        if (i % 4 == 0) {
            win[i] = make_pair(win[i - 2].first + 1, 1);
        } else if (i % 4 == 1) {
            int take_prime = i;
            while (!is_prime[take_prime]) {
                take_prime -= 4;
            }
            win[i] = make_pair(win[i - take_prime].first + 1, 0);
        } else if (i % 4 == 2) {
            win[i] = make_pair(win[i - 2].first + 1, 0);
        } else if (i % 4 == 3) {
            int take_prime = i;
            while (!is_prime[take_prime]) {
                take_prime -= 4;
            }
            win[i] = make_pair(win[i - take_prime].first + 1, 0);
        }
    }
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        int winner = 0;
        int steps = 2147483647;
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            pair<int, int> room = win[a];
            if ((room.first / 2) < steps) {
                steps = (room.first / 2);
                winner = room.second;
            }
        }
        if (winner == 0) {
            cout << "Farmer John" << '\n';
        } else {
            cout << "Farmer Nhoj" << '\n';
        }
    }
    return 0;
}