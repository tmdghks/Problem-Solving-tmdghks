// 1647 도시 분할 계획
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
    ll node1;
    ll node2;
    ll weight;
};
using vdt = vector<dt>;

struct cmp {
    bool operator()(const dt& a, const dt& b) { return a.weight < b.weight; }
};

bool cmpWeights(const dt& a, const dt& b) { return a.weight < b.weight; }

ll union_find(ll n, vll& root);

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll N, M;
    cin >> N >> M;
    vdt g(N);
    for (ll i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g.push_back({--a, --b, c});
    }

    sort(g.begin(), g.end(), cmpWeights);
    vll root(N, 0);
    for (ll i = 0; i < N; i++) {
        root[i] = i;
    }

    ll ans = 0;
    vll ans_vector;
    for (auto k : g) {
        auto [node1, node2, weight] = k;

        if (union_find(node1, root) == union_find(node2, root)) {
            continue;
        } else {
            ans += weight;
            root[union_find(node1, root)] = union_find(node2, root);
            ans_vector.push_back(weight);
        }
    }

    cout << ans - *max_element(ans_vector.begin(), ans_vector.end());
}

ll union_find(ll n, vll& root) {
    if (root[n] == n) return n;
    else {
        return root[n] = union_find(root[n], root);
    }
}
