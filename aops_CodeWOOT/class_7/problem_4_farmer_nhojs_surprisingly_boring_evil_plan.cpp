#include<iostream>
#include<vector>
using namespace std;

int tree[1048577] = {0};
int main() {
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        char type;
        cin >> type;
        if (type == 'E') {
            int h;
            cin >> h;
            while (h < 1048577) {
                tree[h]++;
                h += h & -h;
            }
        }
        else if (type == 'L') {
            int h;
            cin >> h;
            while (h < 1048577) {
                tree[h]--;
                h += h & -h;
            }
        }
        else {
            int k;
            cin >> k;
            int l = 0;
            int r = 1048577;
            while (r > l) {
                int m = (l + r)/2;
                int sum = 0;
                while (m >= 1) {
                    sum += tree[m];
                    m -= m & -m;
                }
                m = (l + r)/2;
                if (sum >= k) {
                    r = m;
                }
                else {
                    l = m + 1;
                }
            }
            cout << l << '\n';
        }
    }
    return 0;
}