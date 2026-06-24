#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, K;
        cin >> N >> K;
        string breed;
        cin >> breed;
        vector<int> breeds(N, 1);
        for (int i = 0; i < N; i++) {
            if (breed[i] == 'G') {
                breeds[i] = 0;
            }
        }
        vector<int> patches(N, 0);
        int left_g = -2147483648;
        int left_h = -2147483648;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (breeds[i] == 0) {
                if (left_g < i - K) {
                    left_g = min(i + K, N - 1);
                    while (patches[left_g] == 2) {
                        left_g--;
                    }
                    // cout << 'g' << left_g << ' ';
                    patches[left_g] = 1;
                    ans++;
                }
            } else {
                if (left_h < i - K) {
                    left_h = min(i + K, N - 1);
                    while (patches[left_h] == 1) {
                        left_h--;
                    }
                    // cout << 'h' << left_h << ' ';
                    patches[left_h] = 2;
                    ans++;
                }
            }
        }
        cout << ans << '\n';
        for (int i = 0; i < N; i++) {
            if (patches[i] == 0) {
                cout << '.';
            } else if (patches[i] == 1) {
                cout << 'G';
            } else {
                cout << 'H';
            }
        }
        cout << '\n';
    }
    return 0;
}