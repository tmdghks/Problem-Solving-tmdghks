// 1753 최단경로
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

struct dt {
    ll n;
    ll w;
};

struct cmp {
    bool operator() (const dt& a, const dt& b) {
        return a.w > b.w;
    }
};

vector<vector<dt>> g;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll i, j;
    ll v, e;
    ll start;
    ll a, b, c, n, w;

    cin >> v >> e >> start;
    g.resize(v);

    for (i = 0; i < e; i++) {
        cin >> a >> b >> c;
        g[a-1].push_back({b-1, c});
    }

    priority_queue<dt, vector<dt>, cmp> pq;
    vector<ll> dist(v, INT_MAX);

    pq.push({start-1, 0});
    dist[start-1] = 0;

    while (!pq.empty()) {
        n = pq.top().n;
        w = pq.top().w;
        pq.pop();
        if (w > dist[n]) continue;
        for (auto& k : g[n]) {
            if (dist[k.n] > w + k.w) {
                dist[k.n] = w + k.w;
                pq.push({k.n, dist[k.n]});
            }
        }
    }

    for (i = 0; i < v; i++) {
        if (dist[i] >= INT_MAX) {
            cout << "INF\n";
        } else {
            cout << dist[i] << '\n';
        }
    }   
}