#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> appear[26];
    for (int i = N - 1; i >= 0; i--) {
        appear[S[i] - 'a'].push_back(N - 1 - i);
    }
    vector<int> go_to(N);
    int curr_index[26] = {0};
    for (int i = 0; i < N; i++) {
        go_to[i] = appear[S[i] - 'a'][curr_index[S[i] - 'a']];
        curr_index[S[i] - 'a']++;
    }
    int pN = N;
    while ((pN & (pN - 1)) != 0) {
        pN += pN & -pN;
    }
    long long ans = 0;
    vector<long long> tree(2 * pN, 0);
    for (int i = 0; i < N; i++) {
        int pointer = 1;
        int s = go_to[i] + 1;
        int comp = pN/2;
        tree[1]++;
        while (pointer < pN) {
            if (s > comp) {
                s -= comp;
                comp /= 2;
                pointer = pointer * 2 + 1;
                tree[pointer]++;
            }
            else {
                ans += tree[pointer * 2 + 1];
                comp /= 2;
                pointer *= 2;
                tree[pointer]++;
            }
        }
    }
    cout << ans << '\n';
}
/*
ans = 2
go_to = 0 3 2 1 4
       4
   4      0
 2   2   0   0
1 1 1 1 0 0 0 0
*/