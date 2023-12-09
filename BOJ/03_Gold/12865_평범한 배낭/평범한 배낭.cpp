// 12865 평범한 배낭
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    ll i, j;
    ll n, k;
    cin >> n >> k;

    vector<pll> g(n);
    vvll dp(n + 1, vll(k + 1, 0));

    for (auto &k : g) {
        ll a, b;
        cin >> a >> b;
        k = make_pair(a, b);
    }

    for (i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (i = 1; i <= n; i++) {
        for (j = 0; j <= k; j++) {
            if (j >= g[i - 1].first) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - g[i - 1].first] + g[i - 1].second);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][k];
}   