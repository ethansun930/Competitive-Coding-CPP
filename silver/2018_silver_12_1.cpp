#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool worked(int middle, vector<int>& arrivals, int M, int C) {
    vector<int> cows;
    int buses = 0;
    for (int i = 0; i < arrivals.size(); i++) {
        if (cows.size() > 0 && (arrivals[i] > (cows[0] + middle))) {
            cows = {};
            buses++;
        }
        cows.push_back(arrivals[i]);
        if (cows.size() >= C) {
            cows = {};
            buses++;
        }
    }
    if (cows.size() != 0) {
        buses++;
    }
    if (buses > M) {
        return false;
    }
    return true;
}
int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> arrivals(N);
    for (int i = 0; i < N; i++) {
        cin >> arrivals[i];
    }
    sort(arrivals.begin(), arrivals.end());
    int left = 0;
    int right = arrivals[arrivals.size() - 1] + 1;
    while (left < right) {
        int middle = (left + right) / 2;
        if (worked(middle, arrivals, M, C)) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    cout << right << '\n';
    return 0;
}