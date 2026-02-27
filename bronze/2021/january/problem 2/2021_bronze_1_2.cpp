#include<iostream>
#include<vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int even_breed_ID = 0;
    for (int i = 0; i < n; i++) {
        int N;
        cin >> N;
        if (N%2 == 0) {
            even_breed_ID += 1;
        }
    }
    int odd_breed_ID = n - even_breed_ID;
    int ans = 0;
    while (odd_breed_ID + even_breed_ID > 0){
        if (even_breed_ID >= 1) {
            even_breed_ID -= 1;
            ans += 1;
        }
        else if (odd_breed_ID >= 2) {
            odd_breed_ID -= 2;
            ans += 1;
        }
        else {
            break;
        }
        if (odd_breed_ID >= 1) {
            odd_breed_ID -= 1;
            ans += 1;
        }
        else {
            break;
        }
    }
    if (odd_breed_ID == 1) {
        ans -= 1;
    }
    cout << ans;
    return 0;
}