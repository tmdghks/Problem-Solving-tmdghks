// 1197 최소 스패닝 트리
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
    cin.tie(0); cout.tie(0);

    ll i, j, a, b, c, n, m;
    cin >> n >> m;
    root.resize(n);
    for (i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g.push_back({a-1, b-1, c});
    }

    sort(g.begin(), g.end(), dt_cmp);
    for (i = 1; i < n; i++) {
        root[i] = i;
    }

    ll ans = 0;

    for (i = 0; i < m; i++) {
        if (find(g[i].a) != find(g[i].b)) {
            ans += g[i].w;
            root[find(g[i].a)] = find(g[i].b);
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