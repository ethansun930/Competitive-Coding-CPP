#include<iostream> 
#include<string> 
using namespace std;
int main() {
    string cowphabet;
    string heard;
    cin >> cowphabet >> heard;
    int curr_cowphabet = 0;
    int ans = 1;
    for (int i = 0; i < heard.size(); i++) {
        while (cowphabet[curr_cowphabet] != heard[i]) {
            curr_cowphabet++;
            if (curr_cowphabet >= cowphabet.length()) {
                curr_cowphabet %= cowphabet.length();
                ans += 1;
            }
        }  
        curr_cowphabet++;
        if (curr_cowphabet >= cowphabet.length()) {
            curr_cowphabet %= cowphabet.length();
            ans += 1;
        }
    }
    cout << ans;
}