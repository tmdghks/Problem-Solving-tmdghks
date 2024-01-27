// 1068 트리
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

vll visited;
vvll g;
ll ans;

void dfs(ll x, ll del) {
    if (visited[x] == 1) return;

    visited[x] = 1;
    if (g[x].empty()) {
        ans++;
        return;
    }
    if (g[x].size() == 1 && g[x][0] == del) {
        ans++;
        return;
    }

    for (auto k : g[x]) {
        if (k != del) {
            dfs(k, del);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    g.resize(n, vll(0));
    visited.resize(n, 0);

    ll i, j, tmp, root;
    for (i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == -1) {
            root = i;
            continue;
        }
        g[tmp].push_back(i);
    }

    ll del;
    cin >> del;
    
    if (root != del)
        dfs(root, del);
    cout << ans;
}