#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> b(N);
    vector<int> b_indexes(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        b[i]--;
        b_indexes[b[i]] = i;
    }
    vector<int> new_a(N);
    for (int i = 0; i < N; i++) {
        new_a[i] = b_indexes[a[i]];
    }
    int maximum = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (new_a[i] < maximum) {
            ans++;
        } else {
            maximum = new_a[i];
        }
    }
    cout << ans << '\n';
    return 0;
}