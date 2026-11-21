#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct mood_count {
    long long maximum = 0;
    long long sum = 0;
    unordered_map<long long, long long> moods;
    void add(long long mood, long long amount) {
        moods[mood] += amount;
        if (moods[mood] == maximum) {
            sum += mood;
        }
        if (moods[mood] > maximum) {
            sum = mood;
            maximum = moods[mood];
        }
    }
};
void combine(mood_count& a, mood_count& b) {
    if (a.moods.size() < b.moods.size()) {
        swap(a, b);
    }
    for (pair<int, int> val : b.moods) {
        a.add(val.first, val.second);
    }
}
mood_count DFS(int node, vector<long long>& ans, vector<vector<int>>& children, vector<long long>& m) {
    mood_count a;
    a.add(m[node], 1);
    for (int child : children[node]) {
        mood_count b = DFS(child, ans, children, m);
        combine(a, b);
    }
    ans[node] = a.sum;
    return a;
}
int main() {
    int N;
    cin >> N;
    vector<vector<int>> children(N);
    for (int i = 1; i < N; i++) {
        int S;
        cin >> S;
        S--;
        children[S].push_back(i);
    }
    vector<long long> m(N);
    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }
    vector<long long> ans(N, 0);
    DFS(0, ans, children, m);
    for (int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}