#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    priority_queue<pair<int, int>> pq;
    int last = K;
    vector<int> comp(K);
    for (int i = 0; i < K; i++) {
        comp[i] = i;
    }
    for (int i = 0; i < K; i++) {
        pq.push({-t[i], i});
    }

}