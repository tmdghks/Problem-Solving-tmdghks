#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll i, j;
    ll t, n, mod = 1000000007;

    cin >> t;

    vector<ll> DP(2501, 0);
    DP[0] = 1;
    for (i = 1; i <= 2500; i++) {
        for (j = 0; j < i; j++) {
            DP[i] += DP[j] * DP[i - j - 1];
            DP[i] %= mod;
        }
    }

    for (i = 0; i < t; i++) {
        cin >> n;
        if (n % 2) {
            cout << "0\n";
        } else {
            cout << DP[n / 2] << '\n';
        }
    }
}