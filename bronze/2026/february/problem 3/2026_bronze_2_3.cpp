// this code didn't work and later on got abandoned.
// #include <iostream>
// #include <string>
// #include <unordered_set>
// #include <utility>
// #include <vector>
// using namespace std;
// int main() {
//     int T;
//     cin >> T;
//     vector<vector<vector<int>>> movements(T);
//     vector<int> answers(T);
//     for (int k = 0; k < T; k++) {
//         int N;
//         int M;
//         cin >> N >> M;
//         string favorite;
//         cin >> favorite;
//         int ans;
//         string first;
//         cin >> first;
//         unordered_set<int> first_indexes[26];
//         for (int i = 0; i < M; i++) {
//             first_indexes[first[i] - 'a'].insert(i);
//         }
//         unordered_set<int> indexes[26];
//         vector<string> s;
//         for (int i = 1; i < N; i++) {
//             string a;
//             cin >> a;
//             s.push_back(a);
//             for (int j = 0; j < M; j++) {
//                 indexes[a[j] - 'a'].insert(i * M + j);
//             }
//         }
//         for (int i = 0; i < M; i++) {
//             if (first[i] == favorite[i]) {
//                 first_indexes[first[i] - 'a'].erase(i);
//                 continue;
//             } else if (first_indexes[favorite[i] - 'a'].size() > 0) {
//                 auto a = first_indexes[favorite[i] - 'a'].begin();
//                 int val = *a;
//                 first_indexes[favorite[i] - 'a'].erase(val);
//                 first_indexes[first[i] - 'a'].erase(i);
//                 first_indexes[first[i] - 'a'].insert(val);
//                 ans++;
//                 movements[k].push_back({1, 1, i, val});
//                 continue;
//             }
//             auto a = indexes[favorite[i] - 'a'].begin();
//             int val = *a;
//             int first_new = val / M;
//             int second = val % M;
//             if (second == i) {
//                 first_indexes[first[i] - 'a'].erase(i);
//                 indexes[favorite[i] - 'a'].erase(val);
//                 indexes[first[i] - 'a'].insert(val);
//                 swap(first[i], s[first_new][i]);
//                 ans++;
//                 vector<int> new = [ 2, 1, first_new, i ];
//                 movements[k].push_back(new);
//                 continue;
//             }
//             indexes[favorite[i] - 'a'].erase(val);
//             indexes[s[val.first()][i] - 'a'].insert(val);
//             indexes[s[val.first()][i] - 'a'].erase(first_new * M + i);
//             indexes[first[i] - 'a'].insert(make_pair(first_new * M + i);
//             first_indexes[first[i] - 'a'].erase(i);
//             first_indexes[favorite[i] - 'a'].insert(i);
//             swap(s[val.first()][i], s[val.first()][val.second()]);
//             swap(first[i], s[val.first()][i]);
//             ans += 2;
//             vector<int> new = [1, first_new, i, second];
//             movements[k].push_back([new]);
//             new = [2, 1, first, i];
//             movements[k].push_back(new);
//         }
//         answers.push_back(ans);
//     }
//     for (int i = 0; i < T; i++) {
//         cout << answers[i] << '\n';
//         for (int j = 0; j < answers[i]; j++) {
//             cout << movements[i][j][0] << " " << movements[i][j][1] << " "
//                  << movements[i][j][2] << " " << movements[i][j][3] << '\n';
//         }
//     }
//     return 0;
// }