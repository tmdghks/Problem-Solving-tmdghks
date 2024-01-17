// 5615 아파트 임대
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using LL = unsigned long long;
const ll mod = 1'000'000'000;

// pair
struct dt {
    ll a;  // current
    ll b;  // sum
};

// vector<pair>
using vdt = vector<dt>;

LL fast_pow(LL a, LL p, LL mod) {
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

// a == 2 || a == 7 || a == 61
// Judging whether x is prime or not
bool is_prime (LL x, LL a) {
    if (a % x == 0) return true;
    LL k = x - 1;
    while (true) {
        LL tmp = fast_pow(a, k, x);
        if (tmp == x - 1) return true;
        if (k % 2 == 1) return (tmp == 1 || tmp == x - 1);
        k /= 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll i, ans = 0, n;
    cin >> n;
    vll v;
    for (i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp * 2 + 1);
    }

    for (auto k : v) {
        if (is_prime(k, 2) && is_prime(k, 7) && is_prime(k, 61)) ans++;
    }

    cout << ans;
}