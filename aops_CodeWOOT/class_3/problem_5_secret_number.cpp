#include<iostream>
#include<vector>
using namespace std;

struct DSU {
    long long K;
    vector<int> parent;
    vector<long long> w;
    vector<int> size;
    DSU(int l, long long k) {
        K = k;
        for (int i = 0; i < l; i++) {
            parent.push_back(i);
            w.push_back(0);
            size.push_back(1);
        }
    }
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        int p = parent[i];
        parent[i] = find(p);
        w[i] = (w[i] + w[p]) % K;
        return parent[i];
    }
    bool merge(int i, int j, long long d) {
        int ri = find(i);
        int rj = find(j);
        /*
        don't call find multiple times since every time very complex things happen to the grpah, changing things completely.
        */
        if (ri == rj) {
            if ((w[i] - w[j] + K)%K == d) {
                return true;
            }
            return false;
        }
        if (size[ri] <= size[rj]) {
            size[rj] += size[ri];
            w[ri] = (w[j] + d - w[i] + K)%K;
            parent[ri] = rj;
        }
        else {
            size[ri] += size[rj];
            w[rj] = ((K - w[j] - d + w[i])%K + K)%K;
            parent[rj] = ri;
        }
        return true;
    }
};
int main() {
    int N, C;
    long long K;
    cin >> N >> K >> C;
    DSU dsu = DSU(N, K);
    for (int i = 0; i < C; i++) {
        int a, b;
        long long d;
        cin >> a >> b >> d;
        a--;
        b--;
        if (dsu.merge(a, b, d)) {
            cout << "TRUE" << '\n';
        }
        else {
            cout << "FALSE" << '\n';
        }
    }
    return 0;
}