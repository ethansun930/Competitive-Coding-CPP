#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> count(N + 1, 0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        count[x]++;
    }
    int curr = 0;
    for (int i = 0; i <= N; i++) {
        if (i != 0 && count[i - 1] == 0) {
            curr++;
        }
        cout << max(curr, count[i]) << '\n';
    }
    return 0;
}