#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vector<ll>>;
using ld = long double;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;

    vll squares, dp(50'001, 4);
    for (int i = 1; i * i <= 50'000; ++i) {
        squares.push_back(i * i);
        dp[i * i] = 1;
    }    
    dp[0] = 0;

    for (int i = 0; i <= n; i++) {
        for (auto k : squares) {
            if (k + i > 50'000)
                break;
            dp[i + k] = min(dp[i] + 1, dp[i + k]);
        }
    }       

    cout << dp[n];
}
