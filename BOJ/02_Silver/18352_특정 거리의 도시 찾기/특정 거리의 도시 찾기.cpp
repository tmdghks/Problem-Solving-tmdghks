// 18352 특정 거리의 도시 찾기
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

struct dt {
    ll n;
    ll dis;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll i, j;
    ll n, m, k, x, tmp1, tmp2;
    cin >> n >> m >> k >> x;
    vvll g(n + 1, vll());

    for (i = 0; i < m; i++) {
        cin >> tmp1 >> tmp2;
        g[tmp1].push_back(tmp2);
    }

    queue<dt> que;
    vector<ll> distance(n + 1, 0);
    distance[x] = 0;
    que.push({x, 0});

    while (!que.empty()) {
        ll front = que.front().n;
        ll dis = que.front().dis;

        if (distance[front] != 0) {
            que.pop();
            continue;
        }
        
        distance[front] = dis;
        for (auto s : g[front]) {
            que.push({s, dis + 1});
        }

        que.pop();
    }
    distance[x] = 0;

    bool f = true;
    for (i = 1; i <= n; i++) {
        if (distance[i] == k) {
            f = false;
            cout << i << '\n';
        }
    }

    if (f) cout << -1;

    return 0;
}