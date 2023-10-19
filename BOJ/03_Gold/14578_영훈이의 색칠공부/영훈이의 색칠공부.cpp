#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, mod = 1000000007, sum = 0;
    ll i, j, fact = 1;
    cin >> n;   
    vector<ll> dp(100001, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (i = 3; i <= 100000; i++) {
        dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]) % mod;
    }

    for (int i = n; i > 0; i--) {
        fact = fact * i % mod;
    }

    cout << fact * dp[n] % mod;
}