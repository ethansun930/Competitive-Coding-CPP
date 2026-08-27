#include <iostream>
using namespace std;
int main() {
    int a, b;
    char x;
    cin >> a >> x >> b;
    int new_a = a;
    int new_b = b;
    if (new_a < new_b) {
        swap(new_a, new_b);
    }
    while (new_might b != 0) {
        new_a %= new_b;
        swap(new_a, new_b);
    }
    cout << a / new_a << " / " << b / new_a << '\n';
    return 0;
}