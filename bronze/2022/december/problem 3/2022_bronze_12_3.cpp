#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;
        bool ok = true;
        vector<int> answers(1 << N, -1);
        for (int i = 0; i < M; i++) {
            string x;
            cin >> x;
            int y;
            cin >> y;
            int input = 0;
            for (int i = 0; i < N; i++) {
                if (x[i] == '1') {
                    input += (1 << i);
                }
            }
            if (answers[input] == -1) {
                answers[input] = y;
            } else if (answers[input] != y) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "LIE" << '\n';
            continue;
        }
        int curr_row = 0;
        while (curr_row < N) {
            int val_0 = -1;
            int val_1 = -1;
            bool ok_0 = true;
            bool ok_1 = true;
            for (int i = 0; i < (1 << N); i++) {
                if (!ok_0 && !ok_1) {
                    break;
                }
                if (answers[i] != -1) {
                    continue;
                }
                if ((i & (1 << curr_row)) == 0) {
                    if (!ok_0) {
                        continue;
                    }
                    if (val_0 == -1) {
                        val_0 = answers[i];
                    } else if (val_0 != answers[i]) {
                        ok_0 = false;
                    }
                } else {
                    if (!ok_1) {
                        continue;
                    }
                    if (val_1 == -1) {
                        val_1 = answers[i];
                    } else if (val_1 != answers[i]) {
                        ok_1 = false;
                    }
                }
            }
            if (ok_0) {
                for (int i = 0; i < (1 << N); i++) {
                    if ((answers[i] != -1) && ((i & (1 << curr_row)) == 0)) {
                        answers[i] = -1;
                    }
                }
            }
            if (ok_1) {
                for (int i = 0; i < (1 << N); i++) {
                    if ((answers[i] != -1) && ((i & (1 << curr_row)) == 1)) {
                        answers[i] = -1;
                    }
                }
            }
            if (ok_0 || ok_1) {
                curr_row = 0;
            } else {
                curr_row++;
            }
        }
        for (int i = 0; i < (1 << N); i++) {
            if (answers[i] != -1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "OK" << '\n';
        } else {
            cout << "LIE" << '\n';
        }
    }
    return 0;
}