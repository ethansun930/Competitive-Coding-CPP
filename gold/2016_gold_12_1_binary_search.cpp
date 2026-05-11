#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct DSU {
    int length;
    vector<int> parent;
    DSU(int l) {
        length = l;
        for (int i = 0; i < length; i++) {
            parent.push_back(i);
        }
    }
    int find(int i) {
        if (parent[i] = i) {
            return i;
        }
        parent[i] = find(parent[i]);
        return parent[i];
    }
    void merge(int i, int j) {
        int rooti = find(i);
        int rootj = find(j);
        if (rooti != rootj) {
            parent[rooti] = rootj;
        }
    }
    bool complete() {
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (parent[i] = i) {
                count++;
            }
        }
    }
};
int main() {}