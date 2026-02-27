#include<iostream>
#include<vector>
#include<string>
using namespace std;
// vector<int> base10(long long n) {
//     vector<int> ans;
//     while (n > 0) {
//         ans.push_back(n%10);
//         n /= 10;
//     }
//     vector<int> reverse_ans(ans.size());
//     for (int i = 0; i < ans.size();) {
//         reverse_ans[i] = ans[ans.size() - i - 1];
//     }
//     return reverse_ans;
// }
// long long turn_back(vector<int> representation) {
//     long long n = 0;
//     for (int i = 0; i < representation.size(); i++) {
//         n += 10^i * representation[i];
//     }
//     return n;
// }
int main() {
    int T;
    cin >> T;
    vector<long long> answers;
    for(int i = 0; i < T; i++) {
        string x;
        cin >> x;
        long long ans = 0;
        while (x != "0") {
            bool zeros_and_ones = true;
            for (const char&j : x) {
                if (j != '0' && j != '1') {
                    zeros_and_ones = false;
                }
            }
            if (zeros_and_ones == true) {
                int amount = 0;
                while(x[x.length() - amount - 1] == '0') {
                    amount++;
                }
                if(amount = 0) {
                    if (x[x.length() - 1] == '0') {}
                }
                else {
                    for (int i = 0; i < amount; i++) {
                        x[x.length() - amount - 1] = '9';
                    }
                }
            }
            else {
                for (int j = 0; j < x.size(); j++) {
                    if (x[j] = '0' || x[j] = '2' || x[j] = '4' || x[j] = '6' || x[j] = '8') {
                        x[j] = '0';
                    }
                    else {
                        x[j] = '1';
                    }
                }
            }
            ans++;
            ans %= 10^9 + 7;
        }
        answers.push_back(ans);
    }
    for (const int& ans : answers) {
        cout << ans << "\n";
    }
    return 0;
}