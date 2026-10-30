#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int pN = N;
    while ((pN & (pN - 1)) != 0) {
        pN += pN & -pN;
    }
    long long ans = 0;
    vector<long long> tree(2 * pN, 0);
    for (int i = 0; i < N; i++) {
        int pointer = 1;
        int s = S[i];
        int comp = pN/2;
        tree[1]++;
        while (pointer < pN) {
            if (s > comp) {
                ans += tree[2 * pointer];
                s -= comp;
                comp /= 2;
                pointer = 2 * pointer + 1;
                tree[pointer]++;
            }
            else {
                comp /= 2;
                pointer *= 2;
                tree[pointer]++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}