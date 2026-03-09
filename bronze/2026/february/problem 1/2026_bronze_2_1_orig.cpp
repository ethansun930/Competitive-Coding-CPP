#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
    int T; 
    cin >> T;
    vector<int> answers;
    for (int i = 0; i < T; i++) {
        int N, K;
        cin >> N >> K;
        vector<int> a(N);
        for (int j = 0; j < N; j++) {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        while (all_distinct(a) == false) {
            for (int j = 0; j < N - 1; j++) {
                if(a[j] == a[j + 1]) {
                    a[j] += K;
                    ans++;
                    sort(a.begin(), a.end());
                }
            }
        }
        answers.push_back(ans);
    }
    for (const int& ans : answers) {
        cout << ans << "\n";
    }
    return 0;
}