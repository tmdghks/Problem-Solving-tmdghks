// 20040 사이클게임
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

struct coordinate {
    ll x;
    ll y;
    ll z;
};

double find_distance(const coordinate& c1, const coordinate& c2);

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

    ll n, m;
    cin >> n >> m;

    vll root(n, 0);
    for (int i = 0; i < n; i++) {
        root[i] = i;
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ll a, b;
        cin >> a >> b;
        if (union_find(a, root) == union_find(b, root)) {
            if (ans == 0) ans = i;
        } else {
            root[union_find(a, root)] = union_find(b, root);
        }
    }

    cout << ans;
    return 0;
}

ll union_find(ll n, vll& root) {
    if (root[n] == n)
        return n;
    else {
        return root[n] = union_find(root[n], root);
    }
}

double find_distance(const coordinate& c1, const coordinate& c2) {
    return min({abs(c1.x - c2.x), abs(c1.y - c2.y), abs(c1.z - c2.z)});
}