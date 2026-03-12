#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;
int main() {
    int T;
    cin >> T;
    vector<vector<int>> movements;
    vector<int> answers;
    for (int k = 0; k < T; k++) {
        int N;
        int M;
        cin >> N >> M;
        string favorite;
        cin >> favorite;
        int ans;
        vector<pair<int, int>> indexes[26];
        string first;
        cin >> first;
        for (int i = 1; i < N; i++) {
            string a;
            cin >> a;
            for (int j = 0; j < M; j++) {
                indexes[a[j] - 'a'].push_back(make_pair(i, j));
            }
        }
        for (int i = 0; i < M; i++) {
            if (first[i] == favorite[i]) {
                continue;
            }
            for (int j = i + 1; j < M; j++) {
                if (first[j] == first[i]) {
                    ans++;
                    movements.push_back({1, 1, i, j});
                }
            }
            
        }
    }
    return 0;
}