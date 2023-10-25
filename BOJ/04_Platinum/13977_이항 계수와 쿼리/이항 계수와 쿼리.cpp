#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fast_power(ll base, ll power, ll mod) {
    if (power == 0)
        return 1;
    else if (power == 1)
        return base;
    else {
        if (power % 2 == 1) {
            return fast_power(base * base % mod, power / 2, mod) * base % mod;
        } else {
            return fast_power(base * base % mod, power / 2, mod);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    ll i, j, mod = 1000000007;
    vector<ll> fact(4000001, 1);
    vector<ll> inv(4000001, 1);
    for (i = 2; i <= 4000000; i++) {
        fact[i] = i * fact[i - 1] % mod;
    }
    inv[4000000] = fast_power(fact[4000000], mod - 2, mod);
    for (i = 3999999; i >= 1; i--) {
        inv[i] = (i + 1) * inv[i + 1] % mod;
    }

    int m, n, k;
    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> n >> k;
        ll comb = fact[n];
        comb *= inv[k];
        comb %= mod;
        comb *= inv[n - k];
        comb %= mod;
        cout << comb << '\n';
    }
}