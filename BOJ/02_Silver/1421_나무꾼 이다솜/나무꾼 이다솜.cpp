// 1421 나무꾼 이다솜
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

    ll n, c, w;
    cin >> n >> c >> w;

    vll v(n);
    for (auto& k : v) cin >> k;
    
    ll ans = 0, tmp = 0;
    ll i, j;
    for (i = 1; i <= *max_element(v.begin(), v.end()); i++) {
        for (auto& k : v) {
            if (k < i) continue;
            if (k % i == 0) {
                tmp += max(ll(0), (1 - k / i) * c + (k / i) * i * w);
            } else {
                tmp += max(ll(0), - (k / i) * c + (k / i) * i * w);
            }
        }
        ans = max(ans, tmp);
        tmp = 0;
    }

    cout << ans << '\n';
}
