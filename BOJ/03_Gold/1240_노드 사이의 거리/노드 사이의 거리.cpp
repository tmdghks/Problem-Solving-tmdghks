// 1240 : 노드 사이의 거리
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL =
    __uint128_t;  // 128비트 정수는 cout, printf 등으로 입출력할 수 없음에 유의

struct dt {
    ll node1;
    ll node2;
    ll weight;
};
using vdt = vector<dt>;

struct coordinate_3d {
    ll x;
    ll y;
    ll z;
};

struct coordinate_2d {
    ll x;
    ll y;
};

double find_distance(const coordinate_3d& c1, const coordinate_3d& c2);

struct cmp {
    bool operator()(const dt& a, const dt& b) { return a.weight < b.weight; }
};

bool cmp_weights(const dt& a, const dt& b) { return a.weight < b.weight; }

ll union_find(ll n, vll& root);

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T = 1;
    while (T--) solve();
}

ll n, m;

ll dijkstra(ll a, ll b, vector<vdt>& g) {
    priority_queue<dt, vdt, cmp> pq;
    vll dist(n, INT_MAX);

    dist[a] = 0;
    pq.push({a, a, 0});
    while(!pq.empty()) {
        auto [node1, node2, weight] = pq.top();
        pq.pop();
        if (weight > dist[node2]) continue;
        for (auto& k : g[node2]) {
            if (dist[k.node2] > k.weight + weight) {
                dist[k.node2] = weight + k.weight;
                pq.push({node1, k.node2, dist[k.node2]});
            }
        }
    }

    return dist[b];
}

void solve() {
    cin >> n >> m;

    vector<vdt> g(n);
    for (ll i = 1; i < n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        g[a].push_back({a, b, c});
        g[b].push_back({b, a, c});
    }

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        cout << dijkstra(a - 1, b - 1, g) << '\n';
    }

    return;
}

ll union_find(ll n, vll& root) {
    if (root[n] == n)
        return n;
    else {
        return root[n] = union_find(root[n], root);
    }
}

double find_distance(const coordinate_3d& c1, const coordinate_3d& c2) {
    return min({abs(c1.x - c2.x), abs(c1.y - c2.y), abs(c1.z - c2.z)});
}