#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;

// 3-pair
struct dt {
    ll a;
    ll b;
};

// vector<pair>
using vdt = vector<dt>;

ll n, r, q, cnt[100001];
vector<vector<int>> g;

void dfs(int ind, int pre) {
    cnt[ind]++;
    for (auto& iter : g[ind]) {
        if (iter == pre) continue;
        dfs(iter, ind);
        cnt[ind] += cnt[iter];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, a, b;
    cin >> n >> r >> q;
    g.resize(n + 1);
    for (i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(r, 0);
    for (i = 0; i < q; i++) {
        cin >> a;
        cout << cnt[a] << '\n';
    }
}
