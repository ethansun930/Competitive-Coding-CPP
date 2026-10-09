#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<utility>
#include<iomanip>
using namespace std;
const double pi = acos(-1.0);

struct Coor {
    double x, y;
};
int main() {
    int N;
    cin >> N;
    vector<Coor> coors(N);
    for (int i = 0; i < N; i++) {
        double r, t;
        cin >> r >> t;
        r /= 1000000;
        t /= 1000000;
        t *= pi;
        t /= 180;
        coors[i].x = r * cos(t);
        coors[i].y = r * sin(t);
    }
    vector<bool> b_visited(N, false);
    vector<double> visited(N, 5);
    visited[0] = 0;
    double ans = 0;
    for (int t = 0; t < N; t++) {
        int node = -1;
        double d = 5;
        for (int i = 0; i < N; i++) {
            if (!b_visited[i] && visited[i] < d) {
                d = visited[i];
                node = i;
            }
        }
        b_visited[node] = true;
        ans += sqrt(visited[node]);
        double x1 = coors[node].x;
        double y1 = coors[node].y;
        for (int i = 0; i < N; i++) {
            if (b_visited[i]) {
                continue;
            }
            double dx = coors[i].x - x1;
            double dy = coors[i].y - y1;
            double dis = dx * dx + dy * dy;
            if (dis < visited[i]) {
                visited[i] = dis;
            }
        }
    }
    cout << fixed << setprecision(6) << ans << '\n';
    return 0;
}