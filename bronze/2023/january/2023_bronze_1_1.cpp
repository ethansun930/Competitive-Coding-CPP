#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    string breeds;
    cin >> breeds;
    vector<int> e(N);
    for (int i = 0; i < N; i++) {
        cin >> e[i];
        e[i]--;
    }
    int first_g = 0;
    for (int i = 0; i < N; i++) {
        if (breeds[i] == 'G') {
            first_g = i;
            break;
        }
    }
    int last_g = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (breeds[i] == 'G') {
            last_g = i;
            break;
        }
    }
    unordered_set<int> possible_g;
    for (int i = 0; i <= first_g; i++) {
        if (breeds[i] == 'G' && e[i] >= last_g) {
            possible_g.insert(i);
        }
    }
    int first_h = 0;
    for (int i = 0; i < N; i++) {
        if (breeds[i] == 'H') {
            first_h = i;
            break;
        }
    }
    int last_h = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (breeds[i] == 'H') {
            last_h = i;
            break;
        }
    }
    unordered_set<int> possible_h;
    for (int i = 0; i <= first_h; i++) {
        if (breeds[i] == 'H' && e[i] >= last_h) {
            possible_h.insert(i);
        }
    }
    int ans = 0;
    for (const int& i : possible_g) {
        for (int j = 0; j < N; j++) {
            if (breeds[j] == 'G') {
                continue;
            }
            if (possible_h.find(j) != possible_h.end() ||
                (j <= i && i <= e[j])) {
                ans++;
            }
        }
    }
    for (const int& i : possible_h) {
        for (int j = 0; j < N; j++) {
            if (breeds[j] == 'H') {
                continue;
            }
            if (possible_g.find(j) != possible_g.end() ||
                (j <= i && i <= e[j])) {
                ans++;
            }
        }
    }
    ans -= possible_g.size() * possible_h.size();
    cout << ans << '\n';
    return 0;
}