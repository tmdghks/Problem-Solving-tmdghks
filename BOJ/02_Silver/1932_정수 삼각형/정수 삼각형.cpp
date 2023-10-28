#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int i, j;
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            cin >> v[i][j];
        }
    }

    dp[0][0] = v[0][0];
    for (i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + v[i][0];
        dp[i][i] = dp[i - 1][i - 1] + v[i][i];
        for (j = 1; j < i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + v[i][j];
        }
    }

    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        maxSum = max(maxSum, dp[n - 1][i]);
    }

    cout << maxSum;
}