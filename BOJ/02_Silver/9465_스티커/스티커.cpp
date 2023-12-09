// 9465 스티커
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int i, j, k;
    int n, t;
    cin >> t;

    vector<vector<int>> v(100001, vector<int>(2, 0));
    vector<vector<ll>> dp(100001, vector<ll>(2, 0));

    for (i = 0; i < t; i++) {
        cin >> n;
        for (j = 0; j < 2; j++) {
            for (k = 1; k <= n; k++) {
                cin >> v[k][j];
            }
        }

        dp[1][0] = v[1][0];
        dp[1][1] = v[1][1];
        for (j = 2; j <= n; j++) {
            dp[j][0] = max(dp[j-2][1], dp[j-1][1]) + v[j][0];
            dp[j][1] = max(dp[j-2][0], dp[j-1][0]) + v[j][1];
        }

        cout << max(dp[n][0], dp[n][1]) << '\n';
    }

    return 0;
}