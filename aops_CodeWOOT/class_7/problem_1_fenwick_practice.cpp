#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> tree(N, 0);
    for (int q = 0; q < Q; q++) {
        char type;
        cin >> type;
        if (type == 'F') {
            for (int i = 0; i < N - 1; i++) {
                cout << tree[i] << ' ';
            }
            cout << tree[N - 1] << '\n';
        }
        else if (type == 'A') {
            int w, x;
            cin >> w >> x;
            while (x <= N) {
                tree[x - 1] += w;
                x += x & -x;
            }
        }
        else {
            int x, y;
            cin >> x >> y;
            x--;
            int ans = 0;
            while (y > 0) {
                ans += tree[y - 1];
                y -= y & -y;
            }
            if (x > 0) {
                while (x > 0) {
                    ans -= tree[x - 1];
                    x -= x & -x;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}