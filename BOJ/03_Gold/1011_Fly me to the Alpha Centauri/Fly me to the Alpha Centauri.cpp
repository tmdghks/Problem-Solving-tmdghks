// 1011_Fly me to the Alpha Centauri
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

    ll i, j, a, b, T, ans = 0;
    cin >> T;
    for (i = 0; i < T; i++) {
        cin >> a >> b;
        ll tmp = sqrt(b - a);
        ans = 2 * tmp;
        if (tmp * tmp + tmp < b - a) ans++;
        if (tmp * tmp == b - a) ans--;
        cout << ans << '\n'; 
    }
}