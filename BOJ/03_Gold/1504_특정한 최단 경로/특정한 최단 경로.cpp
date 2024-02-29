// 1504 특정한 최단 경로
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

vector<vdt> g;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll N, E;
    cin >> N >> E;
    g.resize(N);

    for (ll i = 0; i < E; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    ll x, y;
    cin >> x >> y;
    x--, y--;

    vll distance1(N, INF), distance2(N, INF), distance3(N, INF);
    priority_queue<dt, vector<dt>, cmp> pq;
    pq.push({0, 0});
    distance1[0] = 0;
    while (!pq.empty()) {
        ll a = pq.top().a;
        ll b = pq.top().b;
        pq.pop();
        if (b > distance1[a]) continue;
        for (auto& k : g[a]) {
            if (distance1[k.a] > k.b + b) {
                distance1[k.a] = k.b  + b;
                pq.push({k.a, distance1[k.a]});
            }
        }
    }

    pq.push({x, 0});
    distance2[x] = 0;
    while (!pq.empty()) {
        ll a = pq.top().a;
        ll b = pq.top().b;
        pq.pop();
        if (b > distance2[a]) continue;
        for (auto& k : g[a]) {
            if (distance2[k.a] > k.b + b) {
                distance2[k.a] = k.b + b;
                pq.push({k.a, distance2[k.a]});
            }
        }
    }

    pq.push({y, 0});
    distance3[y] = 0;
    while (!pq.empty()) {
        ll a = pq.top().a;
        ll b = pq.top().b;
        pq.pop();
        if (b > distance3[a]) continue;
        for (auto& k : g[a]) {
            if (distance3[k.a] > k.b + b) {
                distance3[k.a] = k.b + b;
                pq.push({k.a, distance3[k.a]});
            }
        }
    }

    ll tmp1 = distance1[x] + distance2[y] + distance3[N - 1], tmp2 = distance1[y] + distance2[y] + distance2[N - 1];
    if (distance1[x] >= INF || distance1[y] >= INF || distance1[N - 1] >= INF) cout << -1;
    else {
        cout << min(tmp1, tmp2);
    }
}