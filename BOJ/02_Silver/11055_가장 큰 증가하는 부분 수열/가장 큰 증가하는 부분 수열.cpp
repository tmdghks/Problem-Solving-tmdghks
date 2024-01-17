// 11055 가장 큰 증가하는 부분 수열
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;

// pair
struct dt {
    ll a; // current
    ll b; // sum
};

// vector<pair>
using vdt = vector<dt>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll i, j, n;
    cin >> n;

    vll v(n, 0);
    vdt dp(n, {0, 0});

    for (auto &k : v) {
        cin >> k;
    }

    dp[0] = {v[0], v[0]};
    for (i = 1; i < n; i++) {
        dp[i] = {v[i], v[i]};
        for (j = 0; j < i; j++) {
            if (dp[i].a > dp[j].a && dp[j].b + v[i] > dp[i].b) {
                dp[i].b = dp[j].b + v[i];
            }
        }
    }

    ll ans = 0;
    for (auto k : dp) {
        if (k.b > ans) {
            ans = k.b;
        }
    }

    cout << ans;

    return 0;
}