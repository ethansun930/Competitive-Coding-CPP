#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<int> last_a(N);
    vector<int> last_b(N);
    vector<int> last_c(N);
    last_a[0] = a[0];
    last_b[0] = b[0];
    last_c[0] = c[0];
    for (int i = 1; i < N; i++) {
        last_a[i] = max(last_b[i - 1], last_c[i - 1]) + a[i];
        last_b[i] = max(last_a[i - 1], last_c[i - 1]) + b[i];
        last_c[i] = max(last_a[i - 1], last_b[i - 1]) + c[i];
    }
    cout << max(max(last_a[N - 1], last_b[N - 1]), last_c[N - 1]) << '\n';
    return 0;
}