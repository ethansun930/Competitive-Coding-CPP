#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    long long ans = 1;
    int i = 0, j = 0;
    while (i < n) {
        while (j < n && b[j] >= a[i]) {
            j++;
        }
        if (j - i <= 0){
            ans = 0;
            break;
        }
        ans *= j - i;
        i++;
    }
    cout << ans;
    return 0;
}