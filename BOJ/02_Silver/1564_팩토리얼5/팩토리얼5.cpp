// 1564 팩토리얼5
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

    ll n, ans = 1;
    cin >> n;

    for (ll i = 1; i <= n; i++) {
        ans *= i;
        while (ans % 10 == 0) {
            ans /= 10;
        }
        ans %= 1'000'000'000'000;
    }

    printf("%05lld", ans % 100'000);
}
