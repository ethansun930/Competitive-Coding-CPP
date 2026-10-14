#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

const int B = 30000; 
int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    bitset<2 * B + 1> dp;
    dp[B] = 1;
    int curr = 0;
    for (int i = 0; i < N; i++) {
        curr += h[i];
        dp = (dp << h[i]) | (dp >> h[i]);
        for (int j = curr%2; j <= 100; j += 1) {
            if (dp[B + j]) {
                cout << j << '\n';
                break;
            }
        }
    }
    return 0;
}
/*

*/