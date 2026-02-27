#include<iostream>
#include<vector>
#include<string>
#include<vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    string pathway;
    vector<string> ans;
    for (int i = 0; i < N; i++) {
        cin >> pathway;
        int xp = 0, yp = 0;
        int area = 0;
        for (int j = 0; j < pathway.length(); j++) {
            int xc, yc;
            if (pathway[j] == 'N') {
                xc = xp;
                yc = yp + 1;
            }
            else if (pathway[j] == 'E') {
                xc = xp + 1;
                yc = yp;
            }
            else if (pathway[j] == 'S') {
                xc = xp;
                yc = yp - 1;
            }
            else if (pathway[j] == 'W') {
                xc = xp - 1;
                yc = yp;
            }
            area += xp * yc - yp * xc;
            xp = xc;
            yp = yc;
        }
        area += xp * 0 - yp * 0;
        if (area * 1.0 / 2 > 0) {
            ans.push_back("CCW");
        }
        else {
            ans.push_back("CW");
        }
    }
    for (const string& s : ans) {
        cout << s << "\n";
    }
    return 0;
}