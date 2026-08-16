#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void factors(int N, vector<int>& possibles) {
    for (int i = 0; i < sqrt(N); i++) {
        if (N % i == 0) {
            possibles.push_back(i);
            possibles.push_back(N / i);
        }
    }
}
int main() {
    int N;
    cin >> N;
    vector<long long> adup(N);
    long long maxl = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        adup[i] = x;
        maxl = min(maxl, x / 4);
    }
    sort(adup.begin(), adup.end());
    vector<long long> a;
    for (int i = 0; i < N; i++) {
        if (i == 0 || a[i - 1] != a[i]) {
            a.push_back(a[i]);
        }
    }
    N = a.size();
}