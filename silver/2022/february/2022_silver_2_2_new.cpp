#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// assisted by chatgpt

struct State {
    long long x;
    long long y;
    long long count;
};
void work_subsets(vector<pair<long long, long long>>& moves, long long i,
                  long long end, State& state, vector<State>& result) {
    if (i == end) {
        result.push_back(state);
        return;
    }
    work_subsets(moves, i + 1, end, state, result);
    state.x += moves[i].first;
    state.y += moves[i].second;
    state.count++;
    work_subsets(moves, i + 1, end, state, result);
    state.x -= moves[i].first;
    state.y -= moves[i].second;
    state.count--;
}
bool smaller_than(const State& a, const State& b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}
bool equal_positions(const State& a, const State& b) {
    return a.x == b.x && a.y == b.y;
}
int main() {
    long long N;
    cin >> N;
    long long xg, yg;
    cin >> xg >> yg;
    vector<pair<long long, long long>> moves(N);
    for (long long i = 0; i < N; i++) {
        cin >> moves[i].first >> moves[i].second;
    }
    long long middle = N / 2;
    vector<State> left;
    vector<State> right;
    State state = {0, 0, 0};
    work_subsets(moves, 0, middle, state, left);
    state = {0, 0, 0};
    work_subsets(moves, middle, N, state, right);
    for (State& state : right) {
        state.x = xg - state.x;
        state.y = yg - state.y;
    }
    sort(left.begin(), left.end(), smaller_than);
    sort(right.begin(), right.end(), smaller_than);
    vector<long long> ans(N + 1, 0);
    long long i = 0;
    long long j = 0;
    while (i != left.size() && j != right.size()) {
        if (smaller_than(left[i], right[j])) {
            i++;
        } else if (!equal_positions(left[i], right[j])) {
            j++;
        } else {
            long long left_count[41] = {};
            long long right_count[41] = {};
            long long next_i = i;
            while (next_i < left.size() &&
                   equal_positions(left[i], left[next_i])) {
                left_count[left[next_i].count]++;
                next_i++;
            }
            long long next_j = j;
            while (next_j < right.size() &&
                   equal_positions(right[j], right[next_j])) {
                right_count[right[next_j].count]++;
                next_j++;
            }
            for (long long a = 0; a <= middle; a++) {
                for (long long b = 0; b <= N - middle; b++) {
                    ans[a + b] += left_count[a] * right_count[b];
                }
            }
            i = next_i;
            j = next_j;
        }
    }
    for (long long i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}