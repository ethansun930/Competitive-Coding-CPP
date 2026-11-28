#include<iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x, y, z;
        cin >> x >> y >> z;
        if ((((x - 1) ^ (y - 1)) ^ (z - 1)) == 0) {
            cout << "Kressie" << '\n';
        }
        else {
            cout << "Pressie" << '\n';
        }
    }
    return 0;
}