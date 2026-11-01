#include<algorithm>
#include<iostream>
#include<set>
#include<vector>
#include<utility>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> pairs(N);
    for (int i = 0; i < N; i++) {
        cin >> pairs[i].first;
        pairs[i].second = i;
    }
    sort(pairs.begin(), pairs.end());
    int curr_index = 1;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        if (i != 0 && pairs[i].first != pairs[i - 1].first) {
            curr_index++;
        }
        S[pairs[i].second] = curr_index;
    }
    vector<long long> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    curr_index++;
    while ((curr_index & (curr_index - 1)) != 0) {
        curr_index += curr_index & -curr_index;
    }
    vector<long long> tree(2 * curr_index, 0);
    for (int i = 0; i < N; i++) {
        int pointer = 1;
        int s = S[i];
        int comp = curr_index/2;
        long long maximum = 0;
        while (pointer < curr_index) {
            if (s > comp) {
                maximum = max(maximum, tree[2 * pointer]);
                s -= comp;
                comp /= 2;
                pointer = 2 * pointer + 1;
            }
            else {
                comp /= 2;
                pointer *= 2;
            }
        }
        maximum += T[i];
        s = S[i] + curr_index - 1;
        tree[s] = max(tree[s], maximum);
        while (s >= 2) {
            s /= 2;
            tree[s] = max(tree[2 * s], tree[2 * s + 1]);
        }
    }
    cout << tree[1] << '\n';
    return 0;
}