#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL = __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

ll INF = 999'999'999;

// 3-pair
struct dt {
    ll x;
    ll y;
};

// vector<pair>
using vdt = vector<dt>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll mx, my, a, kx, ky, b;
    cin >> mx >> my >> a >> kx >> ky >> b;
    ll M, K;
    cin >> M >> K;

    vdt m(M), k(K);
    for (ll i = 0; i < M; i++) {
        cin >> m[i].x >> m[i].y;
    }
    for (ll i = 0; i < K; i++) {
        cin >> k[i].x >> k[i].y;
    }

    cout << (m[0].x - k[0].x) * (m[0].x - k[0].x) + (m[0].y - k[0].y) * (m[0].y - k[0].y) << '\n';
    cout << m[0].x << ' ' << m[0].y << '\n';
    cout << k[0].x << ' ' << k[0].y << '\n';
}