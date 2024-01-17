// 1644 소수의 연속합
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;

// 3-pair
struct dt {
    ll a;
    ll b;
    ll w;
};

ll find(ll n);
bool dt_cmp(dt lhs, dt rhs) {
    return lhs.w < rhs.w;
}

// vector<pair>
using vdt = vector<dt>;

vll root;
vdt g;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll i, j, n, a, b, ans = 0;
    cin >> n;
    vector<bool> eratos(n + 1, true);
    eratos[0] = eratos[1] = false;
    for (i = 2; i <= n + 1; i++) {
        if (eratos[i]) {
            for (j = i * 2; j <= n + 1; j += i) {
                eratos[j] = false;
            }
        }
    }

    vector<ll> primes;
    for (i = 0; i <= n + 1; i++) {
        if (eratos[i]) {
            primes.push_back(i);
        }
    }

    a = primes.size();
    if (a == 0) {
        cout << 0;
        return 0;
    } else {
        i = 0;
        j = 1;
        b = primes[i];
        while (i < a && j <= a) {
            if (b > n) {
                b -= primes[i++];
            } else if (b < n) {
                b += primes[j++];
            } else {
                ans++;
                b -= primes[i++];
            }
        }
    }

    cout << ans;
}

ll find(ll n) {
    if (root[n] == n)
        return n;
    else
        return root[n] = find(root[n]);
}