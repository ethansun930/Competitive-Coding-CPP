#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        sum %= 998244353;
    }
    int q;
    cin >> q;
    while (q--) {
        int oper;
        cin >> oper;
        if (oper == 1) {
            int x;
            cin >> x;
            a.push_back(x);
            sum += x;
            sum %= 998244353;
        } else if (oper == 2) {
            sum -= a[a.size() - 1];
            sum += 998244353;
            sum %= 998244353;
        } else if (oper == 3) {
            reverse(a.begin(), a.end());
        } else if (oper == 4) {
            sum *= 2;
            sum %= 998244353;
            int a_size = a.size();
            for (int i = 0; i < a_size; i++) {
                a.push_back(a[i]);
            }
        } else {
            cout << sum << '\n';
        }
    }
    return 0;
}