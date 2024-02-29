// 2667 단지 번호 붙이기
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
    return lhs.a < rhs.a;
}

ll cnt1, cnt2, n, ans;
vvll g;
vll sz;

void dfs(ll x, ll y) {
    if (x < 0 || x >= n || y < 0 || y >= n || g[x][y] == 0) return;
    g[x][y] = 0;
    cnt1--;
    cnt2++;
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x + 1, y);
    dfs(x, y + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    g.resize(n, vll(n, 0));

    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (ll j = n - 1; j >= 0; j--) {
            g[j][i] = s[j] - '0';
            if (g[j][i] == 1) cnt1++;
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (g[i][j] == 1) {
                cnt2 = 0;
                dfs(i, j);
                ans++;
                sz.push_back(cnt2);
            }
            if (cnt1 == 0) break;
        }
        if (cnt1 == 0) break;
    }

    cout << ans << '\n';
    sort(sz.begin(), sz.end());
    for (auto k : sz) {
        cout << k << '\n';
    }
}