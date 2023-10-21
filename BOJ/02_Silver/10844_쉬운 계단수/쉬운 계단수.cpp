#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    vector<vector<ll>> v(n + 1, vector<ll>(10, 0));
    
    for (int i = 1; i <= 9; i++) {
        v[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        v[i][0] = v[i - 1][1];
        v[i][9] = v[i - 1][8];
        for (int j = 1; j <= 9; j++) {
            v[i][j] = (v[i-1][j-1] + v[i-1][j+1]) % 1000000000;
        }
    }       

    ll sum = 0;

    for (int i = 0; i < 10; i++) {
        sum += v[n][i];
    }
    cout << sum % 1000000000 << '\n';
    
}