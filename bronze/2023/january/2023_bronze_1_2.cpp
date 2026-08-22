#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

struct conditioner {
    int a, b, p, m;
};
bool check(const int cooling[], vector<conditioner> conditions, int subset) {
    int cooled[101] = {0};
    for (int i = 0; i < conditions.size(); i++) {
        if ((subset & (1 << i)) != 0) {
            for (int j = conditions[i].a; j <= conditions[i].b; j++) {
                cooled[j] += conditions[i].p;
            }
        }
    }
    for (int i = 0; i <= 100; i++) {
        if (cooled[i] < cooling[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    int N, M;
    cin >> N >> M;
    int cooling[101] = {0};
    for (int i = 0; i < N; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        s--;
        t--;
        for (int j = s; j <= t; j++) {
            cooling[j] = c;
        }
    }
    vector<conditioner> conditions(M);
    for (int i = 0; i < M; i++) {
        cin >> conditions[i].a >> conditions[i].b >> conditions[i].p >>
            conditions[i].m;
        conditions[i].a--;
        conditions[i].b--;
    }
    int ans = INT_MAX;
    for (int i = 0; i < (1 << M); i++) {
        if (check(cooling, conditions, i)) {
            int curr = 0;
            for (int j = 0; j < M; j++) {
                if ((i & (1 << j)) != 0) {
                    curr += conditions[j].m;
                }
            }
            ans = min(ans, curr);
        }
    }
    cout << ans << '\n';
    return 0;
}