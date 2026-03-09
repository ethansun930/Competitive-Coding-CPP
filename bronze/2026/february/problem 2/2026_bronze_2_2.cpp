#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define KMOD 1000000007
vector<long long> find(void) {
    vector<long long> f;
    f.push_back(1);
    f.push_back(3);
    for (int i = 2; i <= 200000; i++) {
        f.push_back((f.back() * 2)%KMOD);
    }
    return f;
}
int main(void) {
    vector<long long> f = find();
    int T;
    cin >> T;
    vector<long long> answers;
    for (int k = 0; k < T; k++) {
        string x;
        cin >> x;
        long long ans = 0;
        bool zeros_and_ones = true;
        for (int i = 0; i < x.size(); i++) {
            char curr_digit = x[i];
            if (curr_digit != '0' && curr_digit != '1') {
                zeros_and_ones = false;
            }
            if (curr_digit % 2 == 1) {
                long long tmp = f[x.size() - 1 - i];
                // cout << tmp << " " << x.size() - 1 - i  << " " << i << "\n";
                ans += tmp;
                ans %= KMOD;
            }
        }
        if (zeros_and_ones == false) {
            ans++;
            ans %= KMOD;
        }
        answers.push_back(ans);
    }
    for (const long long& ans : answers) {
        cout << ans << '\n';
    }
}