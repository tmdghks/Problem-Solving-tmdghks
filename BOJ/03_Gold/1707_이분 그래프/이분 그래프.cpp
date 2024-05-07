#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL =
    __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

struct dt {
    ll node;
    ll part;
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll K;
    cin >> K;
    while (K--) solve();
}

void solve() {
    ll V, E;
    cin >> V >> E;
    vvll g(V);
    vll partition(V, 0);
    for (ll i = 0; i < E; i++) {
        ll a, b;
        cin >> a >> b;
        g[--a].emplace_back(--b);
        g[b].emplace_back(a);
    }

    queue<dt> que;
    for (ll v = 0; v < V; ++v) {
        if (partition[v]) continue;

        que.push({v, 1});
        partition[v] = 1;

        while (!que.empty()) {
            auto [node, part] = que.front();
            que.pop();
            ll partInverse = (part == 1) ? 2 : 1;

            for (auto k : g[node]) {
                if (partition[k] == 0) {
                    partition[k] = partInverse;
                    que.push({k, partInverse});
                } else {
                    if (partition[k] == part) {
                        cout << "NO\n";
                        return;
                    } else {
                        continue;
                    }
                }
            }
        }
    }
    
    cout << "YES\n";
    return;
}