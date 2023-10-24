// BOJ 15718 돌아온 떡파이어
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

ll p1 = 97, p2 = 1031;
vector<int> fact1(p1 + 1, 1);
vector<int> fact2(p2 + 1, 1);
vector<int> inv1(p1 + 1, 1);
vector<int> inv2(p2 + 1, 1);

ll comb1(ll n, ll r) {
    if (n % p1 < r % p1) return 0;
    return (fact1[n % p1] * inv1[r % p1] * inv1[(n - r) % p1]) % p1;
}

ll comb2(ll n, ll r) {
    if (n % p2 < r % p2) return 0;
    return (fact2[n % p2] * inv2[r % p2] * inv2[(n - r) % p2]) % p2;
}

int main() {
    for (int i = 2; i < p1; i++) {
        fact1[i] = fact1[i - 1] * i % p1;
    }
    inv1[p1 - 1] = fast_pow(fact1[p1 - 1], p1 - 2, p1);
    for (int i = p1 - 1; i >= 1; i--) {
        inv1[i - 1] = i * inv1[i] % p1;
    }

    for (int i = 2; i < p2; i++) {
        fact2[i] = fact2[i - 1] * i % p2;
    }
    inv2[p2 - 1] = fast_pow(fact2[p2 - 1], p2 - 2, p2);
    for (int i = p2 - 1; i >= 1; i--) {
        inv2[i - 1] = i * inv2[i] % p2;
    }

    ll t;
    cin >> t;
    while (t--) {
        ll m1, n1, m2, n2;
        cin >> n1 >> m1;

        // (m - 1) H (n - m + 1) == (n - 1) C (m - 2)

        if (n1 == 0 && m1 == 1) {
            cout << "1\n";
            continue;
        }
        if (n1 - m1 + 1 < 0 || m1 < 2) {
            cout << "0\n";
            continue;
        } else if (m1 == 2) {
            cout << "1\n";
            continue;
        }

        n1 -= 1;
        m1 -= 2;
        m2 = m1;
        n2 = n1;

        ll ans1 = 1, ans2 = 1;

        while (m1 > 0) {
            ll c1 = comb1(n1, m1);
            ans1 *= c1;
            ans1 %= p1;
            m1 /= p1;
            n1 /= p1;
        }

        while (m2 > 0) {
            ll c2 = comb2(n2, m2);
            ans2 *= c2;
            ans2 %= p2;
            m2 /= p2;
            n2 /= p2;
        }

        for (int j = 0; j <= 100006; j++) {
            if (j % p1 == ans1 && j % p2 == ans2) {
                cout << j << '\n';
                break;
            }
        }
    }
}