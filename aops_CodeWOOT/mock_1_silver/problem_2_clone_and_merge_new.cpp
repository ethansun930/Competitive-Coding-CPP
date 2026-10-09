#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int binary_bound(int n) {
    
}
struct vector_hash {
    int operator() (const vector<int>& vec) const {
        int hash = 31;
        for (int i : vec) {
            hash = 33 * hash + i;
        }
        return hash;
    }
}
int main() {
    int N;
    cin >> N;
    
}