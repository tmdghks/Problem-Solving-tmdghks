// 1238 파티
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL = __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

ll INF = 100'000'000'000;

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

vector<vdt> g1, g2;
vll ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m, x;
    cin >> n >> m >> x;
    x--;
    ans.resize(n, 0);
    g1.resize(n);
    g2.resize(n);

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g1[a].push_back({b, c});
        g2[b].push_back({a, c});
    }
    vll distance(n, INF);
    priority_queue<dt, vdt, cmp> pq;

    pq.push({x, 0});
    distance[x] = 0;
    while (!pq.empty()) {
        ll a = pq.top().a;
        ll b = pq.top().b;
        pq.pop();
        if (b > distance[a]) continue;
        for (auto& k : g1[a]) {
            if (distance[k.a] > b + k.b) {
                distance[k.a] = b + k.b;
                pq.push({k.a, distance[k.a]});
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        ans[i] += distance[i];
    }

    for (auto& k : distance) {
        k = INF;
    }
    pq.push({x, 0});
    distance[x] = 0;
    while (!pq.empty()) {
        ll a = pq.top().a;
        ll b = pq.top().b;
        pq.pop();
        if (b > distance[a]) continue;
        for (auto& k : g2[a]) {
            if (distance[k.a] > b + k.b) {
                distance[k.a] = b + k.b;
                pq.push({k.a, distance[k.a]});
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        ans[i] += distance[i];
    }

    cout << *max_element(ans.begin(), ans.end());
}