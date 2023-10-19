#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fastPower (ll a, ll r, ll mod) {
    if (r == 0) {
        return 1;
    } else if (r == 1) {
        return a;
    } else if (r % 2) {
        return fastPower(a * a % mod, r / 2, mod) % mod * a % mod;
    } else {
        return fastPower(a * a % mod, r / 2, mod) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, mod = 1000000007, t;
    ll i, j;
    cin >> t;
    vector<ll> fact(2000001, 1);
    vector<ll> inv_fact(2000001, 1);
    for (i = 1; i <= 2000001; i++) {
        fact[i] = (i * fact[i - 1]) % mod;
    }

    inv_fact[n] = fastPower(fact[n], mod - 2, mod);

    for (i = 2000000; i > 0; i--) {
        inv_fact[i - 1] = (inv_fact[i] * i) % mod;
    }

    for (i = 0; i < t; i++) {
        cin >> n;
        cout << fact[2 * n] * inv_fact[n] % mod * fastPower(n + 1, mod - 2, mod) % mod; 
    }
}