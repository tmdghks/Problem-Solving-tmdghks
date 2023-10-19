#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll i, j;
    ll t, n, mod = 1000000007;

    vector<ll> DP(10001, 0);
    DP[0] = 1;
    for (i = 1; i <= 10000; i++) {
        for (j = 0; j < i; j++) {
            DP[i] += DP[j] * DP[i - j - 1];
            DP[i] %= mod;
        }
    }
    
    cin >> n;
    cout << DP[n];
}