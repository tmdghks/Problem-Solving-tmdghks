// 11404 플로이드
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL = __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

ll INF = 100'000'000;

// 3-pair
struct dt {
    ll a;
    ll b;
};

// vector<pair>
using vdt = vector<dt>;
bool dt_cmp(dt lhs, dt rhs) {
    return lhs.b < rhs.b;
}

struct cmp {
    bool operator()(const dt& lhs, const dt& rhs) {
        return lhs.b > rhs.b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    ll a, b, c;
    vector<vvll> g(n + 1, vvll(n + 1, vll(n + 1, INF)));
    for (ll i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--, b--;
        g[0][a][b] = min(g[0][a][b], c);
    }

    for (ll k = 0; k <= n; k++) {
        for (ll i = 0; i < n; i++) {
            g[k][i][i] = 0;
        }
    }

    for (ll k = 1; k <= n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                g[k][i][j] = min({g[k - 1][i][j], g[k - 1][i][k - 1] + g[k - 1][k - 1][j], INF});
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (g[n][i][j] >= INF)
                cout << 0 << " ";
            else
                cout << g[n][i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}