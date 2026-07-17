// this was written by chatgpt for 2022 silver february problem 2.
#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;

struct State {
    ll x;
    ll y;
    int count;
};

// Generate every subset from moves[start ... end - 1].
void generate(const vector<pair<ll, ll>>& moves, int index, int end, ll x, ll y,
              int count, vector<State>& result) {
    if (index == end) {
        result.push_back({x, y, count});
        return;
    }

    // Do not use this move.
    generate(moves, index + 1, end, x, y, count, result);

    // Use this move.
    generate(moves, index + 1, end, x + moves[index].first,
             y + moves[index].second, count + 1, result);
}

bool compareStates(const State& a, const State& b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }

    return a.y < b.y;
}

bool samePosition(const State& a, const State& b) {
    return a.x == b.x && a.y == b.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    ll xg, yg;
    cin >> xg >> yg;

    vector<pair<ll, ll>> moves(N);

    for (int i = 0; i < N; i++) {
        cin >> moves[i].first >> moves[i].second;
    }

    int middle = N / 2;

    vector<State> left;
    vector<State> right;

    generate(moves, 0, middle, 0, 0, 0, left);
    generate(moves, middle, N, 0, 0, 0, right);

    /*
     * A right subset with sum (x, y) needs a left subset with:
     *
     * (xg - x, yg - y)
     */
    for (State& state : right) {
        state.x = xg - state.x;
        state.y = yg - state.y;
    }

    sort(left.begin(), left.end(), compareStates);
    sort(right.begin(), right.end(), compareStates);

    vector<ll> answer(N + 1, 0);

    int i = 0;
    int j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i].x < right[j].x ||
            (left[i].x == right[j].x && left[i].y < right[j].y)) {
            i++;
        } else if (right[j].x < left[i].x ||
                   (right[j].x == left[i].x && right[j].y < left[i].y)) {
            j++;
        } else {
            /*
             * left[i] and right[j] have the same position.
             *
             * Count how many subsets of each size reach this position.
             */
            array<ll, 41> leftCount{};
            array<ll, 41> rightCount{};

            int nextI = i;

            while (nextI < left.size() && samePosition(left[nextI], left[i])) {
                leftCount[left[nextI].count]++;
                nextI++;
            }

            int nextJ = j;

            while (nextJ < right.size() &&
                   samePosition(right[nextJ], right[j])) {
                rightCount[right[nextJ].count]++;
                nextJ++;
            }

            // Combine left subset sizes with right subset sizes.
            for (int leftSize = 0; leftSize <= middle; leftSize++) {
                for (int rightSize = 0; rightSize <= N - middle; rightSize++) {
                    answer[leftSize + rightSize] +=
                        leftCount[leftSize] * rightCount[rightSize];
                }
            }

            i = nextI;
            j = nextJ;
        }
    }

    for (int size = 1; size <= N; size++) {
        cout << answer[size] << '\n';
    }

    return 0;
}