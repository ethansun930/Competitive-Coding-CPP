#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void work_subsets(vector<pair<int, int>>& moves, vector<int>& answers, int x,
                  int y, int i, int xg, int yg, int size) {
    if (i == moves.size()) {
        if (x == xg && y == yg) {
            answers[size - 1]++;
        }
        return;
    }
    work_subsets(moves, answers, x, y, i + 1, xg, yg, size);
    work_subsets(moves, answers, x + moves[i].first, y + moves[i].second, i + 1,
                 xg, yg, size + 1);
}
int main() {
    int N;
    cin >> N;
    int xg, yg;
    cin >> xg >> yg;
    vector<pair<int, int>> moves(N);
    for (int i = 0; i < N; i++) {
        cin >> moves[i].first >> moves[i].second;
    }
    vector<int> answers(N, 0);
    vector<int> curr;
    work_subsets(moves, answers, 0, 0, 0, xg, yg, 0);
    for (int i = 0; i < N; i++) {
        cout << answers[i] << '\n';
    }
    return 0;
}