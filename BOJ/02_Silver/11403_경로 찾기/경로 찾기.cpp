// 11403 경로 찾기
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;

// pair
struct dt {
    ll a;  // current
    ll b;  // sum
};

// vector<pair>
using vdt = vector<dt>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vvll> g;
    ll i, j, k, n, tmp;
    cin >> n;
    g.resize(n + 1, vvll(n, vll(n, 0)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[0][i][j];
        }
    }

    for (k = 1; k <= n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                g[k][i][j] = max(g[k - 1][i][j], min(g[k - 1][i][k-1], g[k - 1][k-1][j]));
            }
        }
    }

    for (auto w : g[n]) {
        for (auto k : w) {
            cout << k << ' ';
        }
        cout << '\n';
    }

    return 0;
}