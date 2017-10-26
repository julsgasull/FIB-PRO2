#include <iostream>
#include <vector>
using namespace std;

vector<int> llegeix() {
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    return v;
}


void max_min(const vector<int>& v, int& max, int& min) {
    max = v[0];
    min = v[0];
    int mida = v.size();
    
    for (int i = 0; i < mida; i++) {
        if (v[i] > max) max = v[i];
        else if (v[i] < min) min = v[i];
    }
}

int main() {
    
    vector<int> v = llegeix();
    
    int max, min;
    max_min(v,max,min);
    
    cout << max << ' ' << min << endl;
}
