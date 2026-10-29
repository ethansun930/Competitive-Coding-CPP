#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<unordered_set>
#include<algorithm>
#include<climits>
using namespace std;

int binary_bound(int n) {
    int ans = 0;
    while (n > 1) {
        ans += 2;
        if (n % 2 == 1) {
            ans += 2;
        }
        n >>= 1;
    }
    return ans;
}
struct vector_hash {
    int operator() (const vector<int>& vec) const {
        int hash = 31;
        for (int i : vec) {
            hash = 33 * hash + i;
        }
        return hash;
    }
};
int calculate(int N, vector<int>& dp) {
    int bound = binary_bound(N);
    if ((N & (N - 1)) == 0) {
        return bound;
    }
    for (int j = 2; j <= sqrt(N); j++) {
        if (N % j == 0) {
            bound = min(bound, dp[j] + dp[N/j]);
        }
    }
    unordered_set<vector<int>, vector_hash> seen;
    queue<pair<vector<int>, int>> q;
    q.push({{2, 1}, 3});
    while (!q.empty()) {
        pair<vector<int>, int> node = q.front();
        q.pop();
        int sum = 0;
        int size = node.first.size();
        for (int i = 0; i < size; i++) {
            sum += node.first[i];
            if (sum > N) {
                break;
            }
        }
        if (sum > N) {
            continue;
        }
        int min_moves = node.second + node.first.size() - 1;
        if (sum == N) {
            bound = min(bound, min_moves);
            continue;
        }
        int moves_left = bound - min_moves;
        if (moves_left < 0 || sum * (1 << (moves_left/2)) < N) {
            continue;
        }
        if (node.first.size() > 2) {
            for (int i = 0; i < size - 1; i++) {
                vector<int> new_v(size - 1);
                for (int j = 0; j < i; j++) {
                    new_v[j] = node.first[j];
                }
                new_v[i] = node.first[i] + node.first[i + 1];
                for (int j = i + 2; j < size; j++) {
                    new_v[j - 1] = node.first[j];
                }
                if (seen.find(new_v) == seen.end()) {
                    reverse(new_v.begin(), new_v.end());
                    if (seen.find(new_v) == seen.end()) {
                        seen.insert(new_v);
                        q.push({new_v, node.second + 1});
                    }
                }
            }
        }
        if (moves_left > 0) {
            for (int i = 0; i < size; i++) {
                if ((sum + node.first[i]) * (1 << (moves_left - 2)/2) >= N) {
                    vector<int> new_v(size + 1);
                    for (int j = 0; j <= i; j++) {
                        new_v[j] = node.first[j];
                    }
                    for (int j = i; j < size; j++) {
                        new_v[j + 1] = node.first[j];
                    }
                    if (seen.find(new_v) == seen.end()) {
                        reverse(new_v.begin(), new_v.end());
                        if (seen.find(new_v) == seen.end()) {
                            seen.insert(new_v);
                            q.push({new_v, node.second + 1});
                        }
                    }
                }
            }
        }
    }
    return bound;
}
int main() {
    int N;
    cin >> N;
    vector<int> dp(N + 1, INT_MAX);
    for (int i = 1; i <= N; i++) {
        if (N%i != 0) {
            continue;
        }
        dp[i] = calculate(i, dp);
    }
    cout << dp[N] << '\n';
    return 0;
}