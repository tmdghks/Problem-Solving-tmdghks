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
    ll a;
    ll b;
};

// vector<pair>
using vdt = vector<dt>;

vll fact(2000001, 1);
vll factInv(2000001, 1);

ll fastPower(ll a, ll power) {
    ll ret = 1;
    while (power) {
        if (power % 2) {
            ret = ret * a % 1'000'000'007;
        }
        a = a * a % 1'000'000'007;
        power /= 2;
    }
    return ret % 1'000'000'007;
}

ll comb(ll n, ll r) {
    return fact[n] * factInv[r] % 1'000'000'007 * factInv[n - r] % 1'000'000'007;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (ll i = 1; i <= 2000000; i++) {
        fact[i] = fact[i - 1] * i % 1'000'000'007;
    }
    factInv[2000000] = fastPower(fact[2000000], 1'000'000'007 - 2);

    for (ll i = 1'999'999; i > 0; i--) {
        factInv[i] = factInv[i + 1] * (i + 1) % 1'000'000'007;
    }

    ll N, M;
    cin >> N >> M;

    vll A(N);
    for (auto& k : A) {
        cin >> k;
    }

    ll ans = 1;
    ll unableTime = 0;
    for (ll i = 0; i < N; i++) {
        if (M >= unableTime && A[i] >= unableTime) {
            ans *= comb(M - unableTime, A[i] - unableTime);
            ans %= 1'000'000'007;
            unableTime += (M - A[i]);
        } else {
            ans = 0;
            break;
        }
    }
    if (unableTime > M) {
        ans = 0;
    }

    cout << ans;
}