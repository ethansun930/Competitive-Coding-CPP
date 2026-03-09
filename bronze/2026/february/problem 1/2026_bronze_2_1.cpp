#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int main() {
    int T;
    cin >> T;
    vector<long long> answers;
    for (int k = 0; k < T; k++) {
        int N, K;
        cin >> N >> K;
        int pK = K > 0? K : -K;
        vector<vector<int>> numbers(pK);
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            numbers[x%pK].push_back(x);
        }
        long long ans = 0;
        for (int i = 0; i < pK; i++) {
            if (numbers[i].size() == 0) {
                continue;
            }
            if (K > 0) {
                sort(numbers[i].begin(), numbers[i].end());
                long long curr_level = numbers[i].front();
                for (const int& val : numbers[i]) {
                    if (val >= curr_level) {
                        curr_level = val + K;
                    }
                    else {
                        ans += (curr_level - val)/K;
                        curr_level += K; 
                    }
                }
            }
            else {
                sort(numbers[i].begin(), numbers[i].end(), greater<int>());
                long long curr_level = numbers[i].front();
                for (const int& val : numbers[i]) {
                    if (val <= curr_level) {
                        curr_level = val + K;
                    }
                    else {
                        ans += (val - curr_level)/pK;
                        curr_level += K; 
                    }
                }
            }

        }
        answers.push_back(ans);
    }
    for (const long long& ans : answers) {
        cout << ans << '\n';
    }
    return 0;
}