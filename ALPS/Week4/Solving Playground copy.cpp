// 행렬 곱셈 순서
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vll>;

ll mod;

ull fastPower (ll a, ll n) {
    if (n == 0) return 1;
    else if (n == 1) return a % mod;
    else if (n % 2) {
        return a * fastPower(a * a % mod, n / 2) % mod;
    } else {
        return fastPower(a * a % mod, n / 2) % mod;
    }
}

void solve() {
    ll N;
    vll v(N+1, 0);
    ll n, m;
    for (ll i = 0; i < N; i++) {
        cin >> n >> m;
        v[i] = n;
    }
    v[N] = m;

    vvll dp(N, vll(N, 0));

    for (ll i = 0; i < N; i++) {
        dp[i][i+1] =  
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
}