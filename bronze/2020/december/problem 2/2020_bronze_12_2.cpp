#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int N;
    cin >> N;
    vector<int> daisies;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        daisies.push_back(x);
    }
    int count = 0;
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = i; j < N; j++){
            sum += daisies[j];
            int curr = 0;
            for(int k = i; k <= j; k++){
                if (daisies[k] * (j - i + 1)  == sum){
                    curr = 1;
                }
            }
            count += curr;
        }
    }
    cout << count << "\n";
    return 0;
}