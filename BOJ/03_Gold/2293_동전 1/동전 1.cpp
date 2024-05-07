// 2293 동전 1
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL =
    __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vll v(n, 0);
    for (auto& k : v) {
        cin >> k;
    }

    vll dp(100'001, 0);
    dp[0] = 1;

    for (auto k_ : v) {
        for (int i = k_; i <= 100'000; i++) {
            dp[i] += dp[i - k_];
        }    
    }

    cout << dp[k];
}