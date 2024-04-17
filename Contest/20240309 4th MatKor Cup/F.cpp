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

ll N, M;
vll A;

unordered_map<ll, unordered_map<ll, unordered_map<ll, ll>>> memo;

ll findCases(ll depth, ll unableTime1, ll unableTime2) {
    if (depth == N) {
        return 1;
    }

    if (memo[depth][unableTime1][unableTime2] != 0) {
        return memo[depth][unableTime1][unableTime2];
    }

    ll unableTime0 = M - unableTime1 - unableTime2;
    ll ans = 0;
    ll d = M - A[depth];
    if (d < 0) {
        return 0;
    }
    for (ll i = 0; i <= d; i++) {
        if (i > unableTime1 || d - i > unableTime0) {
            continue;
        }
        ans += (comb(unableTime1, i) * comb(unableTime0, d - i) % 1'000'000'007) * findCases(depth + 1, unableTime1 + d - i, unableTime2 + i) % 1'000'000'007;
        ans %= 1'000'000'007;
    }

    memo[depth][unableTime1][unableTime2] = ans;
    return ans;
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

    cin >> N >> M;

    A.resize(N);
    for (auto& k : A) {
        cin >> k;
    }

    cout << findCases(0, 0, 0);
}