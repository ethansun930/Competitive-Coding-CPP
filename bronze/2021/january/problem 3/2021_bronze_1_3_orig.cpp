//this code works but takes to long for big N
#include<iostream>
using namespace std;
long long ans = 0; // final count for the number of possible configurations
int N; // actual number of cows
int a[20]; // all heights of cows not put in stalls yet
int b[20]; // all max heights of stalls not having a cow put inside it yet
int put_cows_in_stalls(int num_of_cows) {
    int A;
    int B;
    /*
    puts the first cow in vector a into the first possible stall in vector b, 
    calls itself and then puts into the next possible stall in vector b
    */
    if (num_of_cows == 0) {
        ans++;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (a[i] != -1) {
            A = a[i];
            a[i] = -1;
            for (int j = 0; j < N; j++) {
                if (b[j] == -1 || A > b[j]) {
                    continue;
                }
                B = b[j];
                b[j] = -1;
                put_cows_in_stalls(num_of_cows - 1);
                b[j] = B;
            }
            a[i] = A;
            break;
        }
    } 
    return 0;  
}
int main(void) {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> b[i];
    }
    put_cows_in_stalls(N);
    cout << ans;
    return 0;
}