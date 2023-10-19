#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    vector<int> v(50, 0);
    int n, tmp;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v[i] = tmp;
    }

    if (v[1] - v[0] == v[2] - v[1]) {
        int d = v[1] - v[0];
        cout << v[n - 1] + d;
    } else {
        int r = v[1] / v[0];
        cout << v[n - 1] * r;
    }
}