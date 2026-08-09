#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    vector<long long> canes(M);
    for (int i = 0; i < M; i++) {
        cin >> canes[i];
    }
    for (int i = 0; i < M; i++) {
        long long curr_height = 0;
        for (int j = 0; j < N; j++) {
            long long growth =
                min(max(0LL, cows[j] - curr_height), canes[i] - curr_height);
            curr_height = min(max(curr_height, cows[j]), canes[i]);
            cows[j] += growth;
            if (curr_height == canes[i]) {
                break;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << cows[i] << '\n';
    }
    return 0;
}