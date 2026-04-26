#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
struct Cow {
    int x;
    int y;
    int power;
    int mark = 0;
};
void mark(vector<Cow>& cows, int index, int& mark_count) {
    if (cows[index].mark != 0) {
        return;
    }
    cows[index].mark = 1;
    mark_count++;
    for (int i = 0; i < cows.size(); i++) {
        if (((cows[i].x - cows[index].x) * (cows[i].x - cows[index].x) +
             (cows[i].y - cows[index].y) * (cows[i].y - cows[index].y)) <=
            (cows[index].power * cows[index].power)) {
            mark(cows, i, mark_count);
        }
    }
}
int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int N;
    cin >> N;
    vector<Cow> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].x >> cows[i].y >> cows[i].power;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cows[j].mark = 0;
        }
        if (cows[i].mark == 0) {
            int mark_count = 0;
            mark(cows, i, mark_count);
            ans = max(mark_count, ans);
        }
    }
    cout << ans << '\n';
    return 0;
}