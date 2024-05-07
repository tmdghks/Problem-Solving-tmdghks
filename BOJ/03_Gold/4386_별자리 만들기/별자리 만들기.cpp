// 4386 별자리 만들기
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
    double weight;
};
using vdt = vector<dt>;

struct coordinate {
    double x;
    double y;
};

double euclid_distance(const coordinate& c1, const coordinate& c2);

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

    ll n;
    cin >> n;

    vector<coordinate> star_map;
    for (ll i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        star_map.push_back({a, b});
    }

    vdt g;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            g.push_back({i, j, euclid_distance(star_map[i], star_map[j])});
        }
    }

    sort(g.begin(), g.end(), cmp_weights);

    double ans = 0;
    vll root(n, 0);
    for (ll i = 0; i < n; i++) root[i] = i;
    for (auto k : g) {
        auto [node1, node2, weight] = k;
        if (union_find(node1, root) == union_find(node2, root)) {
            continue;
        } else {
            ans += weight;
            root[union_find(node1, root)] = union_find(node2, root);
        }
    }

    cout << fixed << setprecision(2) << ans;
}

ll union_find(ll n, vll& root) {
    if (root[n] == n)
        return n;
    else {
        return root[n] = union_find(root[n], root);
    }
}

double euclid_distance(const coordinate& c1, const coordinate& c2) {
    return pow((c2.x - c1.x) * (c2.x - c1.x) + (c2.y - c1.y) * (c2.y - c1.y),
               0.5);
}