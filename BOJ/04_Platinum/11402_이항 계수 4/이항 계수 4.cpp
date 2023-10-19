#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// ll fast_power(ll base, ll power, ll mod) {
//     if (power == 0) return 1;
//     else if (power == 1) return base;
//     else {
//         if (power % 2 == 1) {
//             return fast_power(base * base % mod, power / 2, mod) * base % mod;
//         } else {
//             return fast_power(base * base % mod, power / 2, mod);
//         }
//     }
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    ll n, k, m;
    ll i, j;
    ll tmp = 1;

    cin >> n >> k >> m;

    vector<vector<ll>> dp(2001, vector<ll>(2001, 0));

    dp[0][0] = 1;
    for (i = 1; i <= 2000; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for (j = 1; j <= i - 1; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] % m;
        }
    }

    while (n > 0 && k > 0) {
        tmp *= dp[n % m][k % m];
        tmp %= m;
        n /= m; k /= m;
    }

    cout << tmp << '\n';
}