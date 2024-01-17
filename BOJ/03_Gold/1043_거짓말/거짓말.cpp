// 1043 거짓말
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;

// pair
struct dt {
    ll a;
    ll b;
};

// vector<pair>
using vdt = vector<dt>;
vll g, party, people;
ll find(ll n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c, n, m, l, i, j, ans = 0;
    cin >> n >> m;
    cin >> l;
    people.resize(l);
    g.resize(n + 1);
    for (i = 0; i <= n; i++) {
        g[i] = i;
    }
    for (auto &k : people) {
        cin >> k;
    }

    for (i = 0; i < m; i++) {
        cin >> l;
        cin >> a;
        a = find(a);
        party.push_back(a);
        for (j = 1; j < l; j++) {
            cin >> b;
            g[find(b)] = find(a);
            a = b;
        }
    }

    for (auto k : party) {
        bool f = true;
        for (auto p : people) {
            if (find(k) == find(p)) {
                f = false;
                break;
            }
        }
        if (f) ans++;
    }
    cout << ans;
}

ll find(ll n) {
    if (g[n] == n)
        return n;
    else
        return g[n] = find(g[n]);
}