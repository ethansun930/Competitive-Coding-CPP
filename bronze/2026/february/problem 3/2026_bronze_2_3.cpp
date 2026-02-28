#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        int M;
        cin >> N >> M;
        int ans = 0;
        string favorite;
        cin >> favorite;
        vector<string> s(N);
        for (int j = 0; j < N; j++) {
            cin >> s[j];
        }
        vector<vector<int>> perform;
        for (int j = 0; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                if (favorite[j] = s[1][k] && favorite[k] = s[1][j] && favorite[j] != favorite[k]) {
                    ans++;
                    perform.push_back([2, 1, j, k]);
                    swap(s[1][j], s[1][k]);
                }
            }
        }
        for (int j = 0; j < M; j++) {
            
        }
    }
    return 0;
}