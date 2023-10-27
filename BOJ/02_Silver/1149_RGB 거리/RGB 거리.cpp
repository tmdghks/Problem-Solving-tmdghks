#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct price {
    int r;
    int g;
    int b;
};

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int i;
    int n;
    cin >> n;

    vector<price> v(n + 1, {0, 0, 0});
    for (i = 1; i <= n; i++) {
        cin >> v[i].r >> v[i].g >> v[i].b;
    }

    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    
    for (i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + v[i].r;
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + v[i].g;
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + v[i].b; 
    }

    int min = dp[n][0];
    if (min > dp[n][1]) min = dp[n][1];
    if (min > dp[n][2]) min = dp[n][2];

    cout << min;
}