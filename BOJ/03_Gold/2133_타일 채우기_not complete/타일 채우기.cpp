#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    ll i, j;
    ll n;
    cin >> n;
    if (n % 2) {
        cout << 0;
        return 0;
    } 

    vector<ll> dp(n / 2 + 1, 0);
    dp[1] = 3;
    dp[2] = 8;
    for (i = 3; i <= n / 2; i++) {
        for (j = 0; j < i; j++) {
            dp[i] += dp[j] * ((i - j) * 3 + 2);
        }
    }

    cout << dp[n / 2];
}