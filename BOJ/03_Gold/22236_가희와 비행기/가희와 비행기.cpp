#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll i, j;
    ll n, mod;

    cin >> n >> mod;

    vector<ll> DP(n / 2 + 1, 0);
    DP[0] = 1;
    for (i = 1; i <= n / 2; i++) {
        for (j = 0; j < i; j++) {
            DP[i] += DP[j] * DP[i - j - 1];
            DP[i] %= mod;
        }
    }

    cout << DP[n / 2 - 1] << '\n';
}