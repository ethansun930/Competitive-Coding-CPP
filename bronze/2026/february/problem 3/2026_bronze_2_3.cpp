#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<unordered_set>
using namespace std;
int main() {
    int T;
    cin >> T;
    vector<vector<int>> movements(T);
    vector<int> answers;
    for (int k = 0; k < T; k++) {
        int N;
        int M;
        cin >> N >> M;
        string favorite;
        cin >> favorite;
        int ans;
        unordered_set<pair<int, int>> indexes[26];
        string first;
        cin >> first;
        unordered_set<int> first_indexes[26];
        for (int i = 0; i < M; i++) {
            first_indexes[first[i] - 'a'].push_back(i);
        }
        for (int i = 1; i < N; i++) {
            string a;
            cin >> a;
            for (int j = 0; j < M; j++) {
                indexes[a[j] - 'a'].push_back(make_pair(i, j));
            }
        }
        for (int i = 0; i < M; i++) {
            if (first[i] == favorite[i]) {
                first_indexes[first[i] - 'a'].erase(i);
                continue;
            }
            else if (first_indexes[favorite[i] - 'a'].size() > 0) {
                auto a = first_indexes[favorite[i] - 'a'].begin();
                int val = *a;
                first_indexes[favorite[i] - 'a'].erase(val);
                first_indexes[first[i] - 'a'].erase(i);
                first_indexes[first[i] - 'a'].insert(val);
                ans++;
                ansers[k].push_back([1, 1, i, val]);
                continue;
            }
            auto a = first_indexes[favorit]
        }
    }
    return 0;
}