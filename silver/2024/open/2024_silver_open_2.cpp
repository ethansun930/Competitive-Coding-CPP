#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Coor {
    int x, y;
};
int main() {
    int N, P;
    cin >> N >> P;
    vector<Coor> fence(P);
    for (int i = 0; i < P; i++) {
        cin >> fence[i].x >> fence[i].y;
    }
    
}
/*
USACO 2024 US Open Contest, Silver
Problem 2. Painting Fence Posts
store which numbers are in each x coor
and which numbers are in each y coor
that way finding out the order is easy.
to find out which segment a point belongs to, 
check it's y coor line, then binary search the segment that it belongs to.
next, you go like the bronze to prefix sum which direction it will go, 
then sweep line to solve the problem.
*/