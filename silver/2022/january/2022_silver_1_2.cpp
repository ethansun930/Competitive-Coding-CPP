#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> h(N);
    for (long long i = 0; i < N; i++) {
        cin >> h[i];
    }
    long long ans = 0;
    stack<long long> s;
    for (long long i = 0; i < N; i++) {
        while ((!s.empty()) && (h[s.top()] <= h[i])) {
            ans += (i - s.top() + 1);
            s.pop();
        }
        s.push(i);
    }
    s = stack<long long>();
    reverse(h.begin(), h.end());
    for (long long i = 0; i < N; i++) {
        while ((!s.empty()) && (h[s.top()] <= h[i])) {
            ans += (i - s.top() + 1);
            s.pop();
        }
        s.push(i);
    }
    cout << ans << '\n';
    return 0;
}