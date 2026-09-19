#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Coor {
    int x, y;
};
int abs(int x) {
    if (x >= 0) {
        return x;
    }
    return -x;
}
int main() {
    int N, P;
    cin >> N >> P;
    vector<Coor> fence(P);
    vector<int> prefix(P + 1, 0);
    for (int i = 0; i < P; i++) {
        cin >> fence[i].x >> fence[i].y;
    }
    for (int i = 0; i < P; i++) {
        prefix[i + 1] = prefix[i] + abs(fence[(i + 1) % P].x - fence[i].x) +
                        abs(fence[(i + 1) % P].y - fence[i].y);
    }
    int on_fence[1001][1001] = {-1};
    for (int i = 0; i < P; i++) {
        int x1, y1, x2, y2;
        x1 = min(fence[i].x, fence[(i + 1) % P].x);
        x2 = max(fence[i].x, fence[(i + 1) % P].x);
        y1 = min(fence[i].y, fence[(i + 1) % P].y);
        y2 = max(fence[i].y, fence[(i + 1) % P].y);
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                on_fence[x][y] = i;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
    }
}
/*
store the ditance from 0 to every post using only post x -> post x + 1,
then store which fence segment every point is on.
*/