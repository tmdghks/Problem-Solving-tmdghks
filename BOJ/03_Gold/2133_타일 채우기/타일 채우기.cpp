// 2133 타일 채우기
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    vll dp(16, 0);
    dp[0] = 1;
    dp[1] = 3;
    for (ll i = 2; i <= 15; i++) {
        dp[i] = 3 * dp[i - 1];
        for (ll j = i - 2; j >= 0; j--) {
            dp[i] += dp[j] * 2;
        }
    }

    if (n % 2 == 0) {
        cout << dp[n / 2];
    } else cout << 0;
}