// 1717 집합의 표현
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;

// pair
struct dt {
    ll a; // current
    ll b; // sum
};

// vector<pair>
using vdt = vector<dt>;
vll g;

ll find(ll n) {
    if (g[n] == n) 
        return n;
    else
        return g[n] = find(g[n]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, m, i, j;
    cin >> n >> m;
    g.resize(n + 1);

    for (i = 0; i <= n; i++) {
        g[i] = i;
    }

    ll a, b, c;
    for (i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 0) {
            g[find(b)] = find(c);
        } else {
            cout << ((find(b) == find(c)) ? "YES\n" : "NO\n");
        }
    }
}