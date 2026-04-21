#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
vector<int> split(string n) {
    string curr = "";
    vector<int> ans;
    for (const char& i : n) {
        if (i == ' ') {
            ans.push_back(stoi(curr));
            curr = "";
        }
        else {
            curr += i;
        }
    }
    if (curr != "") {
        ans.push_back(stoi(curr));
    }
    return ans;
}
string fillPuzzle(int n, string numbers) {
    string ans = "";
    vector<vector<int>> grid(n, vector<int>(n));
    vector<pair<int, int>> empty;
    set<int> unused_numbers;
    vector<int> split_numbers = split(numbers);
    for (int i = 1; i <= n * n; i++) {
        unused_numbers.insert(i);
    }
    for (int i = 0; i < n * n; i++) {
        grid[i/n][i%n] = split_numbers[i];
        if (split_numbers[i] == 0) {
            empty.push_back(make_pair(i/n, i%n));
        }
        else {
            unused_numbers.erase(split_numbers[i]);
        }
    }
    for (const auto& i : empty) {
        set<int> neighbors;
        int dir[5] = {0, 1, 0, -1, 0};
        for (int t = 0; t < 4; t++) {
            if (0 <= i.first + dir[t] && i.first + dir[t] < n && 0 <= i.second + dir[t + 1] && i.second + dir[t + 1] < n) {
               neighbors.insert(grid[i.first + dir[t]][i.second + dir[t + 1]]);
            }
        }
        for (const int& j : unused_numbers) {
            if (neighbors.find(j + 1) != neighbors.end() && neighbors.find(j - 1) != neighbors.end()) {
                unused_numbers.erase(j);
                grid[i.first][i.second] = j;
                ans += to_string(j);
                ans += ' ';
                break;
            }
        }
    }
    if (ans[ans.size() - 1] == ' ') {
        ans.pop_back();
    }
    return ans;
}