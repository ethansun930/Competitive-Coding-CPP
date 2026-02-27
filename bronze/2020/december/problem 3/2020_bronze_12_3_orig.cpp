// this code doesn't work
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	vector<array<int, 3>> cows;
	for(int i = 0; i < n; i++) {
		char direction;
		int x;
		int y;
		cin >> direction >> x >> y;
		int ndirection;
		if(direction == 'N') {
			ndirection = 1;
		}
		else {
			ndirection = 0;
		}
		array<int, 3> curr = {ndirection, x, y};
		cows.push_back(curr);
	}
	int ans[6];
	for(int i = 0; i < n; i++) {
		int curr_ans = 1000000000;
		for(int j = 0; j < n; j++) {
			if (j == i || cows[i][0] == cows[j][0]){
			    continue;
			}
			else if(cows[i][0] == 1 && cows[i][1] - cows[j][1] < cows[j][2] - cows[i][2] && cows[i][1] > cows[j][1] && cows[j][2] > cows[i][2]) {
				curr_ans = min(curr_ans, cows[j][2] - cows[i][2]);
			}
			else if(cows[i][0] == 0 && cows[j][1] - cows[i][1] > cows[i][2] - cows[j][2] && cows[j][1] > cows[i][1] && cows[i][2] > cows[j][2]) {
				curr_ans = min(curr_ans, cows[j][1] - cows[i][1]);
			}
		}
		if (1000000000 == curr_ans) {
			cout << "Infinity"<< "\n";
		}
		else {
			cout << curr_ans << "\n";
		}
	}


	return 0;
}