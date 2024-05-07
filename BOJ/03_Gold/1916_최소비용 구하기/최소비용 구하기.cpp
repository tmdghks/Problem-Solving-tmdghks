// 1916 최소비용 구하기
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
    ll dist;
};
using vdt = vector<dt>;

struct cmp {
    bool operator()(const dt& a, const dt& b) { return a.dist > b.dist; }
};

bool cmpWeights(const dt& a, const dt& b) { return a.dist > b.dist; }

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<vdt> g(n);

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        g[--a].push_back({--b, c});
    }

    ll start, end; cin >> start >> end;
    start--, end--;
    vll distance(n, 999'999'999'999);
    priority_queue<dt, vdt, cmp> pq;
    pq.push({start, 0});
    distance[start] = 0;

    while (!pq.empty()) {
        auto [node, dist] = pq.top();
        pq.pop();

        if (dist > distance[node]) continue;
        for (auto& k : g[node]) {
            if (distance[k.node] > dist + k.dist) {
                distance[k.node] = dist + k.dist;
                pq.push({k.node, dist + k.dist});
            }
        }
    }

    cout << distance[end];
}
