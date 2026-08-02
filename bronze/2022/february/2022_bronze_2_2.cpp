#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> a_indexes(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        x--;
        a[i] = x;
        a_indexes[x] = i;
    }
    vector<int> b(N);
    vector<int> b_indexes(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        x--;
        b[i] = x;
        b_indexes[x] = i;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a_indexes[i] < a_indexes[j] && b_indexes[i] > b_indexes[j]) {
                ans++;
                int k = a_indexes[j];
                while (k > 0 && a_indexes[j] - a_indexes[i] !=
                                    b_indexes[j] - b_indexes[i]) {
                    swap(a_indexes[a[k]], a_indexes[a[k - 1]]);
                    swap(a[k], a[k - 1]);
                    k--;
                    ;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}