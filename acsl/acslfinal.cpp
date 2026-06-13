#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
 * Complete the 'countReversals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING values as parameter.
 */
vector<long long> split(string& values) {
    vector<long long> ans;
    long long curr = 0;
    long long sign = 1;
    while (values[values.size() - 1] == ' ') {
        values.pop_back();
    }
    for (int i = 0; i < values.size(); i++) {
        if (values[i] == ' ') {
            ans.push_back(curr);
            curr = 0;
            sign = 1;
        } else if (values[i] == '-') {
            sign = -1;
        } else {
            curr = 10 * curr + (values[i] - '0') * sign;
        }
    }
    ans.push_back(curr);
    return ans;
}
bool sorted(vector<long long>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] >= nums[i + 1]) {
            return false;
        }
    }
    return true;
}
void rev(vector<long long>& nums, int x, int y) {
    int xi = x;
    int yi = y;
    while (xi < yi) {
        swap(nums[xi], nums[yi]);
        xi++;
        yi--;
    }
}
bool largest(vector<long long>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (nums[0] < nums[i]) {
            return false;
        }
    }
    return true;
}
int find_after(vector<long long>& nums) {
    pair<int, long long> curr = make_pair(0, 10000000000000000LL);
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < curr.second && nums[i] > nums[0]) {
            curr = make_pair(i, nums[i]);
        }
    }
    return curr.first;
}
int countReversals(string values) {
    vector<long long> nums;
    nums = split(values);
    int ans = 0;
    while (!sorted(nums)) {
        ans++;
        if (nums[0] <= nums[1]) {
            for (int i = 1; i < nums.size() - 1; i++) {
                if (nums[i] >= nums[i + 1]) {
                    rev(nums, 0, i);
                    break;
                }
            }
        } else if (largest(nums)) {
            rev(nums, 0, nums.size() - 1);
        } else {
            int swapper = find_after(nums);
            rev(nums, 0, swapper - 1);
        }
        // for (int i = 0; i < nums.size(); i++) {
        //     cout << nums[i] << ' ';
        // }
        // cout << '\n';
    }
    return ans;
}
int main() {
    string x = "57 48 26 31 19 -3 ";
    cout << countReversals(x);
    return 0;
}