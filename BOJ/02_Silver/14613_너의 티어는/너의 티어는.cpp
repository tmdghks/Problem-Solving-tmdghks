// 14613 너의 티어는
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;

ll mod;

double fastPower (double a, ll n) {
    if (n == 0) return 1;
    else if (n == 1) return a;
    else if (n % 2) {
        return a * fastPower(a * a, n / 2);
    } else {
        return fastPower(a * a, n / 2);
    }
}

// ull euler(ll n) {
//     ll euler = n;
//     for (ll i = 2; i * i< n; i++) {
//         i++;
//     }
// }

vll fact(21, 1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fact.resize(21, 1);
    for (ll i = 2; i <= 20; i++) {
        fact[i] = fact[i - 1] * i;
    }

    double a, b, c;
    cin >> a >> b >> c;
    
    vector<double> tier_probability(5, 0);

    for (ll i = 0; i <= 20; i++) {
        for (ll j = 0; i + j <= 20; j++) {
            // cout << (fact[20] / (fact[i] * fact[j] * fact[20 - i - j])) * fastPower(a, i) * fastPower(b, j) * fastPower(c, 20 - i - j) << '\n';
            tier_probability[(1000 + 50 * i - 50 * j) / 500] += (fact[20] / (double) (fact[i] * fact[j] * fact[20 - i - j])) * fastPower(a, i) * fastPower(b, j) * fastPower(c, 20 - i - j);
        }
    }

    for (auto k : tier_probability)
        cout << fixed << setprecision(8) << k << '\n';
}