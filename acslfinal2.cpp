#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long eval(long long& x, long long& y, char& oper) {
    if (oper == '+') {
        return x + y;
    } else if (oper == '-') {
        return x - y;
    } else if (oper == '*') {
        return x * y;
    } else if (oper == '/') {
        return x / y;
    } else if (oper == '^') {
        long long xi = 1;
        for (int i = 0; i < y; i++) {
            xi *= x;
        }
        return xi;
    }
    return 0;
}
void add_solns(vector<long long>& nums, long long& target, long long& curr,
               vector<char>& opers, long long& ans) {
    if (curr == target) {
        ans++;
    }
    if (nums.size() == 0) {
        return;
    }
    int dups = 1;
    for (int i = 0; i < nums.size(); i += dups) {
        long long val = nums[i];
        nums.erase(nums.begin() + i);
        for (int j = 0; j < opers.size(); j++) {
            char oper = opers[j];
            if (oper == '/' && val == 0) {
                continue;
            }
            long long new_curr = eval(curr, val, opers[j]);
            opers.erase(opers.begin() + j);
            add_solns(nums, target, new_curr, opers, ans);
            opers.insert(opers.begin() + j, oper);
        }
        nums.insert(nums.begin() + i, val);
        dups = 1;
        while (i + dups < nums.size() && nums[i + dups] == nums[i]) {
            dups++;
        }
    }
}
int countSolutions(int target, string plate) {
    long long targeti = target;
    vector<long long> nums;
    for (int i = 0; i < plate.size(); i++) {
        if ('0' <= plate[i] && plate[i] <= '9') {
            nums.push_back(plate[i] - '0');
        }
    }
    if (nums.size() == 0) {
        if (target == 0) {
            return 1;
        }
        return 0;
    }
    sort(nums.begin(), nums.end());
    vector<char> opers = {'+', '-', '*', '/', '^'};
    long long ans = 0;
    if (targeti == 0) {
        ans++;
    }
    long long curr = 0;
    int dups = 1;
    for (int i = 0; i < nums.size(); i += dups) {
        curr = nums[i];
        nums.erase(nums.begin() + i);
        add_solns(nums, targeti, curr, opers, ans);
        nums.insert(nums.begin() + i, curr);
        dups = 1;
        while (i + dups < nums.size() && nums[i + dups] == nums[i]) {
            dups++;
        }
    }
    return ans;
}
int main() {
    cout << countSolutions(12, "3141PI") << '\n';
    return 0;
}