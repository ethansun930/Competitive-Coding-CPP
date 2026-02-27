#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int nums[7];
	for (int i = 0; i < 7; i++) {
		cin >> nums[i];
	}
	sort(nums, nums + 7);
	int a = nums[0];
	int b = nums[1];
	int c = nums[6] - a - b;
	cout << a << " " << b << " " << c << "\n";

	return 0;
}