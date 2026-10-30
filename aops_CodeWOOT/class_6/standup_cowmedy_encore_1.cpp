#include<iostream>
#include<vector>
#include<utility>
using namespace std;

pair<vector<int>, long long> merge_sort(vector<int>& nums, int a, int b) {
    if (b == a) {
        return {{}, 0};
    }
    if (b - a == 1) {
        return {{nums[a]}, 0};
    }
    pair<vector<int>, long long> ans1 = merge_sort(nums, a, (a + b)/2);
    pair<vector<int>, long long> ans2 = merge_sort(nums, (a + b)/2, b);
    int p1 = 0;
    int p2 = 0;
    long long ans = ans1.second + ans2.second;
    int size1 = (a + b)/2 - a;
    int size2 = b - (a + b)/2;
    vector<int> new_vec;
    while (p1 < size1 && p2 < size2) {
        if (ans1.first[p1] < ans2.first[p2]) {
            ans += size2 - p2;
            new_vec.push_back(ans1.first[p1]);
            p1++;
        }
        else {
            new_vec.push_back(ans2.first[p2]);
            p2++;
        }
    }
    while (p1 < size1) {
        new_vec.push_back(ans1.first[p1]);
        p1++;
    }
    while (p2 < size2) {
        new_vec.push_back(ans2.first[p2]);
        p2++;
    }
    return {new_vec, ans};
}
int main() {
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    cout << merge_sort(S, 0, N).second << '\n';
    return 0;
}