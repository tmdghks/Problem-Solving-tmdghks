#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;

ull fastPower(ll a, ll n, ll mod) {
    if (n == 0)
        return 1;
    else if (n == 1)
        return a % mod;
    else if (n % 2) {
        return a * fastPower(a * a % mod, n / 2, mod) % mod;
    } else {
        return fastPower(a * a % mod, n / 2, mod) % mod;
    }
}

ll gcd(ll a, ll b) {
    return b ? a % b : a;
}

ll extended_euclid(ll a, ll b, ll x, ll y) {
    if (a % b == 0) {
        return ;
    } else if (a % b == 1) {
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ull N, A;
    cin >> N >> A;

    if (N % A) {
        cout << N - A << " " <<  << '\n';
    } else {
        cout << N - A << " " << -1;
    }
}