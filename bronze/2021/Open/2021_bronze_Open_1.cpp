#include<iostream>
#include<vector>
using namespace std;
int main() {
    int N, L;
    cin >> N >> L;
    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < N; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}