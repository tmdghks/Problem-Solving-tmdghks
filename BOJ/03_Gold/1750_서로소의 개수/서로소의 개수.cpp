// 1750 서로소의 개수
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int gcd(ll a, ll b) {
    if (b % a == 0) return a;
    else return gcd(b % a, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll mod = 10'000'003;
    ll i, j;
    ll n;
    cin >> n;
    vvll v(n, vll(100'001, 0));
    vll q(n, 0);
    
    for (i = 0; i < n; i++) {
        cin >> q[i];
    }

    v[0][q[0]] = 1;
    for (i = 1; i < n; i++) {
        v[i][q[i]] = 1;
        for (j = 1; j <= 100'000; j++) {
            v[i][j] += v[i-1][j] % mod;
            v[i][gcd(q[i], j)] += v[i-1][j] % mod;
        }
    }

    cout << v[n-1][1] % mod;
}