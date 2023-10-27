#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fast_pow(ll a, ll p, ll mod) {
    if (p == 0)
        return 1;
    else if (p == 1)
        return a;
    else if (p % 2 == 1) {
        return fast_pow((a * a) % mod, p / 2, mod) * a % mod;
    } else {
        return fast_pow((a * a) % mod, p / 2, mod);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int mod = 1000000007;

    vector<int> fact(1000001, 1);
    vector<int> inv(1000001, 1);


    ll n, r;
    cin >> n >> r;

    ll tmp = 1;
    ll inv1 = 1, inv2 = 1;

    for (int i = 1; i <= n; i++) {
        tmp = tmp * i % mod;
        if (i == n - r) {
            inv1 = fast_pow(tmp, mod - 2, mod); 
        } 
        if (i == r) {
            inv2 = fast_pow(tmp, mod - 2, mod);
        }
    }
    

    ll ans = ((tmp * inv1) % mod * inv2) % mod;

    cout << ans;
}