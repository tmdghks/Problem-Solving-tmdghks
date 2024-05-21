// 27172 : 수 나누기 게임
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

    ll T = 1;
    while (T--) solve();
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> eratos(1'000'001, 0);

    vector<ll> v(n, 0);
    vector<bool> visited(1'000'001, false);
    for (auto& k : v) {
        cin >> k;
        visited[k] = true;
    }

    for (auto k : v) {
        for (int i = 2 * k; i <= 1'000'000; i += k) {
            if (visited[i]) {
                eratos[i]--;
                eratos[k]++;
            }
        }
    }

    for (auto k : v) {
        cout << eratos[k] << " ";
    }
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
}// 27172 : 수 나누기 게임
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

    ll T = 1;
    while (T--) solve();
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> eratos(1'000'001, 0);

    vector<ll> v(n, 0);
    vector<bool> visited(1'000'001, false);
    for (auto& k : v) {
        cin >> k;
        visited[k] = true;
    }

    for (auto k : v) {
        for (int i = 2 * k; i <= 1'000'000; i += k) {
            if (visited[i]) {
                eratos[i]--;
                eratos[k]++;
            }
        }
    }

    for (auto k : v) {
        cout << eratos[k] << " ";
    }
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