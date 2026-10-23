#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V, H, S;
    cin >> V >> H >> S;
    vector<double> Y(V);
    for (int i = 0; i < V; i++) {
        cin >> Y[i];
    }
    vector<vector<double>> X(V, vector<double>(H));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < H; j++) {
            cin >> X[i][j];
        }
    }
    vector<double> B(S);
    for (int i = 0; i < S; i++) {
        cin >> B[i];
    }
    sort(B.begin(), B.end());
    vector<int> subsets;
    for (int i = 0; i < (1 << H); i++) {
        if (__builtin_popcount(i) == S) {
            subsets.push_back(i);
        }
    }
    vector<double> dp(subsets.size());
    
}