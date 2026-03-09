#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
    int T;
    cin >> T;
    vector<int> answers;
    for (int k = 0; k < T; k++) {
        string x;
        cin >> x;
        long long ans = 0;
        while (stoi(x) > 0) {
            bool zeros_and_ones = true;
            for (const char& i : x) {
                if (i != '0' && i != '1') {
                    zeros_and_ones = false;
                }
            }
            if (zeros_and_ones == true) {
                x = to_string(stoi(x) - 1);
            }
            else {
                string new_x = "";
                for (const char& i : x) {
                    int new_i = i - '0';
                    if (new_i % 2 == 0) {
                    new_x += '0';
                    }
                    else {
                        new_x += '1';
                    }
                }
                x = new_x;
            ans %= 1000000007;
            }
            ans++;
        }
        answers.push_back(ans);
    }
    for (const long long& ans : answers) {
        cout << ans << '\n';
    }
    return 0;
}