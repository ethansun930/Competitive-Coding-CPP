#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, T;
    cin >> N >> K >> T;
    vector<int> a(K);
    for (int i = 0; i < K; i++) {
        cin >> a[i];
    }
    vector<int> final(N);
    int curr_smaller = 0;
    for (int i = 0; i < N; i++) {
        if (a[curr_smaller + 1] <= i) {
            curr_smaller++;
        }
        int cycle = a[curr_smaller + 1] - a[curr_smaller];
        int time = T % cycle;
        int result = (i - time + cycle) % cycle;
        final[result] = i;
    }
    cout << final[0];
    for (int i = 1; i < N; i++) {
        cout << ' ' << final[i];
    }
    cout << '\n';
    return 0;
}