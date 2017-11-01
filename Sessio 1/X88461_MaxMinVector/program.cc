#include <iostream>
#include <vector>
#include "vectorIOint.hh"
using namespace std;

void max_min(const vector<int>& v, int& x, int& y) {
    int n = v.size();
    x = y = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > x) x = v[i];
        if (v[i] < y) y = v[i];
    }
}

int main() {
    vector<int> v;
    leer_vector_int(v);
    int x, y;
    max_min(v, x, y);
    cout << x << ' ' << y << endl;
}
